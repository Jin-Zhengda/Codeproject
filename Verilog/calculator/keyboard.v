`timescale 1ns / 1ps

module keyboard #(
    parameter CNT_THRESHOLD=1000000-1
)(
    input  wire       clk,
    input  wire       rst,
    input  wire [3:0] row,           //读入行信号
    output reg  [3:0] col,           //输出列扫描信号
    output reg        keyboard_en,   //keyboard是否有按下,只有按下的时候按键值才有效，区分复位状态的0和实际按下编号为0的键
    output reg  [3:0] keyboard_num,  //keyboard具体按下的数字,送到数码管,只维持一个周期
);

wire cnt_end;

/********************************
 * 生成列扫描频率控制信号
 ********************************/
counter #(CNT_THRESHOLD, 24) u_counter(
    .clk(clk), 
    .rst(rst), 
    .cnt_inc(1),
    .cnt_end(cnt_end)
);

reg[15:0] key;   // 16个按键的状态，1是按下，0是没按下
reg[15:0] key_r;

/********************************
 * 列扫描信号生成
 ********************************/
always @(posedge clk, posedge rst) begin
    if (rst == 1)           col <= 4'b1111;
    else if (col ==  4'b1111) col <= 4'b1110;
    else if (cnt_end)         col <= {col[2:0], col[3]};
end

/********************************
 * 读取行信号
 ********************************/
always @(posedge clk, posedge rst) begin
    if (rst == 1) key <= 0;
    else if (cnt_end) begin                     // key[3:0]对应右边第一列col0,即ABCD按键
        if (col[0] == 0) key[3:0]   <= ~row;    // 对行信号做了取反处理方便判断
        if (col[1] == 0) key[7:4]   <= ~row;    // 扫描完之后再统一解码，不是边扫描边判断
        if (col[2] == 0) key[11:8]  <= ~row;
        if (col[3] == 0) key[15:12] <= ~row;
    end
end

//读入的 row 是异步信号，通常进行打两拍操作，将异步信号同步化，并防止亚稳态。
always @(posedge clk, posedge rst) begin
    if (rst == 1) key_r <= 0;
    else key_r <= key;
end

wire[15:0] key_posedge = (~key_r) & key;   // 对应按键按下产生上升沿 

/********************************
 * 按键编码解析
 ********************************/
always @(posedge clk, posedge rst) begin
    if (rst == 1) begin
        keyboard_num <= 0;   
    end else if (key_posedge) begin
		if (key_posedge[0]) keyboard_num <= 'hd;
		else if (key_posedge[1]) keyboard_num <= 'hc;
		else if (key_posedge[2]) keyboard_num <= 'hb;
		else if (key_posedge[3]) keyboard_num <= 'ha;
		else if (key_posedge[4]) keyboard_num <= 'hf;
		else if (key_posedge[5]) keyboard_num <= 'h9;
		else if (key_posedge[6]) keyboard_num <= 'h6;
		else if (key_posedge[7]) keyboard_num <= 'h3;
		else if (key_posedge[8]) keyboard_num <= 'h0;
		else if (key_posedge[9]) keyboard_num <= 'h8;
		else if (key_posedge[10]) keyboard_num <= 'h5;
		else if (key_posedge[11]) keyboard_num <= 'h2;
		else if (key_posedge[12]) keyboard_num <= 'he;
		else if (key_posedge[13]) keyboard_num <= 'h7;
		else if (key_posedge[14]) keyboard_num <= 'h4;
		else if (key_posedge[15]) keyboard_num <= 'h1;
	end else begin
		keyboard_num <= keyboard_num;
	end
end

always @(posedge clk, posedge rst) begin
    if (rst == 1) begin
        keyboard_en <= 0;
    end else if (key_posedge) begin
		keyboard_en <= 1;
	end else begin
		keyboard_en <= 0;
	end
end

endmodule
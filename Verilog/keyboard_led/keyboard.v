`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// gineer: 
// 
// Create Date: 2023/11/17 10:37:53
// Design Name: 
// Module Name: counter
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module keyboard #(
    parameter CNT_THRESHOLD=1000000-1
)(
    input  wire       clk,
    input  wire       reset,
    input  wire [3:0] row,           //�������ź�
    output reg  [3:0] col,           //�����ɨ���ź�
    output reg        keyboard_en,   //keyboard�Ƿ��а���,ֻ�а��µ�ʱ�򰴼�ֵ����Ч�����ָ�λ״̬��0��ʵ�ʰ��±��Ϊ0�ļ�
    output reg [15:0] keyboard_led,  //keyboard���尴�µ�����,�͵�led
    output [7:0] led_en,
    output [7:0] led_cx,
    output reg pass_led
);

wire cnt_end;
reg  [3:0] keyboard_num;

/********************************
 * ������ɨ��Ƶ�ʿ����ź�
 ********************************/
counter #(CNT_THRESHOLD, 24) u_counter(
    .clk(clk), 
    .reset(reset), 
    .cnt_inc(1),
    .cnt_end(cnt_end)
);

reg[15:0] key;   // 16��������״̬��1�ǰ��£�0��û����
reg[15:0] key_r;

/********************************
 * ��ɨ���ź�����
 ********************************/
//always @(posedge clk, posedge reset) begin
//    if (reset == 1)           col <= 4'b1111;
//    else if (col ==  4'b1111) col <= 4'b1110;
//    else if (cnt_end)         col <= {col[2:0], col[3]};
//end
wire [3: 0] col_out;

moore u_moore(
    .clk(clk),
    .rst(reset),
    .cnt_end(cnt_end),
    .out(col_out)
);

always @(*) begin
    col = col_out;
end


/********************************
 * ��ȡ���ź�
 ********************************/
always @(posedge clk, posedge reset) begin
    if (reset == 1) key <= 0;
    else if (cnt_end) begin                     // key[3:0]��Ӧ�ұߵ�һ��col0,��ABCD����
        if (col[0] == 0) key[3:0]   <= ~row;    // �����ź�����ȡ���������ж�
        if (col[1] == 0) key[7:4]   <= ~row;    // ɨ����֮����ͳһ���룬���Ǳ�ɨ����ж�
        if (col[2] == 0) key[11:8]  <= ~row;
        if (col[3] == 0) key[15:12] <= ~row;
    end
end

//����� row ���첽�źţ�ͨ�����д����Ĳ��������첽�ź�ͬ����������ֹ����̬��
always @(posedge clk, posedge reset) begin
    if (reset == 1) key_r <= 0;
    else key_r <= key;
end

wire[15:0] key_posedge = (~key_r) & key;   // ��Ӧ�������²��������� 

/********************************
 * �����������
 ********************************/
always @(posedge clk, posedge reset) begin
    if (reset == 1) begin
        keyboard_num <= 0;   
    end 
    else if (key_posedge) begin
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
	end 
    else begin
		keyboard_num <= keyboard_num;
	end
end

/*
      case ({col, row})  // �����
        8'b1110_1110 : keyboard_num <= 4'hd;   // key_posedge[0]
        8'b1110_1101 : keyboard_num <= 4'hc;   // key_posedge[1]
        8'b1110_1011 : keyboard_num <= 4'hb;   // key_posedge[2]
        8'b1110_0111 : keyboard_num <= 4'ha;   // key_posedge[3]  �����Դ����ƣ�

        8'b1101_1110 : keyboard_num <= 4'hf;  // #��
        8'b1101_1101 : keyboard_num <= 4'h9;
        8'b1101_1011 : keyboard_num <= 4'h6;
        8'b1101_0111 : keyboard_num <= 4'h3;

        8'b1011_1110 : keyboard_num <= 4'h0;
        8'b1011_1101 : keyboard_num <= 4'h8;
        8'b1011_1011 : keyboard_num <= 4'h5;
        8'b1011_0111 : keyboard_num <= 4'h2;

        8'b0111_1110 : keyboard_num <= 4'he;  // *��
        8'b0111_1101 : keyboard_num <= 4'h7;
        8'b0111_1011 : keyboard_num <= 4'h4;
        8'b0111_0111 : keyboard_num <= 4'h1;        
      endcase
   */

wire en;




always @(posedge clk, posedge reset) begin
    if (reset == 1) begin
        keyboard_en <= 0;
    end else if (key_posedge) begin
		keyboard_en <= 1;
	end else begin
		keyboard_en <= 0;
	end
end

always @(posedge clk, posedge reset) begin
    if (reset == 1)
        keyboard_led <= 0;
    else if (en)
        keyboard_led <= key;
    else
        keyboard_led <= 0;
end


always@(*) begin
    case(en)
        1'b1: pass_led = 0;
        1'b0: pass_led = 1;
        1'bz: pass_led = 1;
        default: pass_led = 1;
    endcase
end

password u_password(
    .clk(clk),
    .keyboard_en(keyboard_en),
    .keyboard_num(keyboard_num),
    .rst(reset),
    .en(en)
);

led u_led(
    .clk(clk),
    .rst(reset),
    .keyboard_en(keyboard_en),
    .key_num(keyboard_num),
    .en(en),
    .led_en(led_en),
    .led_cx(led_cx)
);



endmodule

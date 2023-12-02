`timescale 1ns / 1ps

module keyboard #(
    parameter CNT_THRESHOLD=1000000-1
)(
    input  wire       clk,
    input  wire       rst,
    input  wire [3:0] row,           
    output reg  [3:0] col,           
    output reg        keyboard_en,   
    output reg  [3:0] keyboard_num,
    output reg [15: 0] key_pose
);

wire cnt_end;

counter #(CNT_THRESHOLD, 24) u_counter(
    .clk(clk), 
    .rst(rst), 
    .cnt_inc(1),
    .cnt_end(cnt_end)
);

reg[15:0] key;  
reg[15:0] key_r;

always @(posedge clk or posedge rst) begin
    if (rst == 1)           col <= 4'b1111;
    else if (col ==  4'b1111) col <= 4'b1110;
    else if (cnt_end)         col <= {col[2:0], col[3]};
end

always @(posedge clk, posedge rst) begin
    if (rst == 1) key <= 0;
    else if (cnt_end) begin                     
        if (col[0] == 0) key[3:0]   <= ~row;    
        if (col[1] == 0) key[7:4]   <= ~row;    
        if (col[2] == 0) key[11:8]  <= ~row;
        if (col[3] == 0) key[15:12] <= ~row;
    end
end

always @(posedge clk, posedge rst) begin
    if (rst == 1) key_r <= 0;
    else key_r <= key;
end

wire[15:0] key_posedge = (~key_r) & key;  

always @(*) begin
    key_pose = key_posedge;
end

always @(posedge clk, posedge rst) begin
    if (rst == 1) begin
        keyboard_num <= 0;   
    end else if (key_posedge) begin
		if (key_posedge[0]) keyboard_num <= 4'hd;
		else if (key_posedge[1]) keyboard_num <= 4'hc;
		else if (key_posedge[2]) keyboard_num <= 4'hb;
		else if (key_posedge[3]) keyboard_num <= 4'ha;
		else if (key_posedge[4]) keyboard_num <= 4'hf;
		else if (key_posedge[5]) keyboard_num <= 4'h9;
		else if (key_posedge[6]) keyboard_num <= 4'h6;
		else if (key_posedge[7]) keyboard_num <= 4'h3;
		else if (key_posedge[8]) keyboard_num <= 4'h0;
		else if (key_posedge[9]) keyboard_num <= 4'h8;
		else if (key_posedge[10]) keyboard_num <= 4'h5;
		else if (key_posedge[11]) keyboard_num <= 4'h2;
		else if (key_posedge[12]) keyboard_num <= 4'he;
		else if (key_posedge[13]) keyboard_num <= 4'h7;
		else if (key_posedge[14]) keyboard_num <= 4'h4;
		else if (key_posedge[15]) keyboard_num <= 4'h1;
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
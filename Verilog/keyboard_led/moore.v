`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/17 10:57:35
// Design Name: 
// Module Name: moore
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


module moore(
    input wire clk,
    input wire rst,
    input wire cnt_end,
    output reg[3: 0] out
    );
    
parameter IDLE = 4'b1111;
parameter S1 = 4'b1110;
parameter S2 = 4'b1101;
parameter S3 = 4'b1011;
parameter S4 = 4'b0111;

reg [3:0] current_state;
reg [3:0] next_state;
wire rst_n = ~rst;


// 第1个always块，描述次态迁移到现态
always @(posedge clk or negedge rst_n) begin
    if(~rst_n) current_state <= IDLE;
    else       current_state <= next_state;
end

// 第2个always块，描述状态转移条件判断
always @(*) begin
    case (current_state)
        IDLE: if(cnt_end) next_state = S1;
              else    next_state = IDLE;
        S1: if(cnt_end) next_state = S2;
              else    next_state = S1;
        S2: if(cnt_end) next_state = S3;
              else    next_state = S2;
        S3: if(cnt_end) next_state = S4;
              else    next_state = S3;
        S4: if(cnt_end) next_state = S1;
              else    next_state = S4;
        default : next_state = IDLE;
    endcase
end

// 第3个always块，描述输出逻辑
always @(posedge clk or negedge rst_n) begin
    if(~rst_n) out <= 4'b1111;
    else begin
        case(current_state)
            S1 : out <= 4'b1110;
            S2 : out <= 4'b1101;
            S3 : out <= 4'b1011;
            S4 : out <= 4'b0111;
            default : out <= 4'b1111;
        endcase
    end
end

endmodule

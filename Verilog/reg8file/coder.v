`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/03 11:33:26
// Design Name: 
// Module Name: coder
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


module coder(
    input wire [3:0] wsel,
    input wire en,
    output reg [7:0]out_en
    );
always @(*) begin
    if (en == 1) 
        case (wsel)
            0:out_en = 8'b00000001;
            1:out_en = 8'b00000010;
            2:out_en = 8'b00000100;
            3:out_en = 8'b00001000;
            4:out_en = 8'b00010000;
            5:out_en = 8'b00100000;
            6:out_en = 8'b01000000;
            7:out_en = 8'b10000000;
            default:out_en = 8'b00000000;
        endcase
    else
        out_en = 8'b00000000;
end
endmodule

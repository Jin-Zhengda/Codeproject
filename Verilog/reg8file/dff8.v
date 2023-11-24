`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/03 11:30:03
// Design Name: 
// Module Name: dff8
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


module dff8 (
    input wire clk,
    input wire clr,
    input wire en,
    input wire [7:0]d,
    output reg [7:0]r
);

always @(posedge clk) begin
    if (clr == 1)
        r <= 0;
    else if (en == 1) 
        r <= d;
    else 
        r <= r;
end

endmodule

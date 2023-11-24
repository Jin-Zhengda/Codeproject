`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/03 11:30:18
// Design Name: 
// Module Name: select
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


module select(
    input wire [7:0] r0, r1, r2, r3, r4, r5, r6, r7,
    input wire [3:0] rsel,
    output reg [7:0] q
    );
    
    always @(*) begin
        case (rsel)
            0: q = r0;
            1: q = r1;
            2: q = r2;
            3: q = r3;
            4: q = r4;
            5: q = r5;
            6: q = r6;
            7: q = r7;
            default: q = 8'b00000000;
        endcase
    end
endmodule

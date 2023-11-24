`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/03 11:29:44
// Design Name: 
// Module Name: reg8file
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


module reg8file(
    input wire [3:0] wsel,
    input wire en,
    input wire clk,
    input wire clr,
    input wire [7:0] d,
    input wire [3:0] rsel,
    output reg [7:0] q
    );
    wire [7:0] out;
    
    wire [7:0] out_en;
    wire [7:0] r0, r1, r2, r3, r4, r5, r6, r7;
    
    coder u_coder(
        .wsel(wsel),
        .en(en),
        .out_en(out_en)
    );
    
    dff8 u_dff8_0(
        .clk(clk),
        .clr(clr),
        .en(out_en[0]),
        .d(d),
        .r(r0)
    );
    
    dff8 u_dff8_1(
        .clk(clk),
        .clr(clr),
        .en(out_en[1]),
        .d(d),
        .r(r1)
    );
    
    dff8 u_dff8_2(
        .clk(clk),
        .clr(clr),
        .en(out_en[2]),
        .d(d),
        .r(r2)
    );
    
    dff8 u_dff8_3(
        .clk(clk),
        .clr(clr),
        .en(out_en[3]),
        .d(d),
        .r(r3)
    );
    
    dff8 u_dff8_4(
        .clk(clk),
        .clr(clr),
        .en(out_en[4]),
        .d(d),
        .r(r4)
    );
    
    dff8 u_dff8_5(
        .clk(clk),
        .clr(clr),
        .en(out_en[5]),
        .d(d),
        .r(r5)
    );
    
    dff8 u_dff8_6(
        .clk(clk),
        .clr(clr),
        .en(out_en[6]),
        .d(d),
        .r(r6)
    );
    
    dff8 u_dff8_7(
        .clk(clk),
        .clr(clr),
        .en(out_en[7]),
        .d(d),
        .r(r7)
    );
    
    select u_select(
        .rsel(rsel),
        .r0(r0),
        .r1(r1),
        .r2(r2),
        .r3(r3),
        .r4(r4),
        .r5(r5),
        .r6(r6),
        .r7(r7),
        .q(out)
    );

always @(*) begin
    q = out;
end

endmodule

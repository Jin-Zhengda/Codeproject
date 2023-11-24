`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/03 12:17:11
// Design Name: 
// Module Name: testbench
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


module testbench();
    reg [3:0] wsel;
    reg en;
    reg clk = 0;
    reg clr;
    reg [7:0] d;
    reg rsel;
    wire [7:0] q;

    reg8file u_reg8file(
        .wsel(wsel),
        .rsel(rsel),
        .en(en),
        .clk(clk),
        .clr(clr),
        .d(d),
        .q(q)
    );
    
    
   parameter clk_period = 10;
   
   initial   
   begin
       forever
         #(clk_period/2) clk = ~clk;                            
   end
   
    initial
    begin
        clr = 0;en = 0;d = 8'b00000000; wsel = 4'b0000; rsel = 4'b0000;
        #5 begin clr = 1; wsel = 4'b0001; rsel = 4'b0001; d = 8'b00000001; end
        #10 begin clr = 0; en = 1; wsel = 4'b0001; rsel = 4'b0001; d = 8'b00000001;end
        #10 begin clr = 0; en = 1; wsel = 4'b0010; rsel = 4'b0010; d = 8'b00000010; end
        #10 begin clr = 0; en = 1; wsel = 4'b0010; rsel = 4'b0011; d = 8'b00000011; end
        #10 $finish;
    end
endmodule

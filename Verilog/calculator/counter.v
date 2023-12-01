`timescale 1ns / 1ps

module counter #(
    parameter END=15,
    parameter WIDTH=4
)(
    input clk, 
    input rst, 
    input cnt_inc, 
    output cnt_end, 
    output reg[WIDTH-1:0] cnt
);

assign cnt_end = (cnt == END);

always @(posedge clk, posedge rst) begin
	if (rst) cnt <= 1'b0;
	else if (cnt_end) cnt <= 1'b0;
	else if (cnt_inc) cnt <= cnt + 1'b1;
end

endmodule
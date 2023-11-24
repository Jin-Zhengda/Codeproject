`timescale  1ns / 1ps

module tb_dff;

// dff Parameters
parameter PERIOD  = 10;


// dff Inputs
reg   clk = 0 ;
reg   clr = 0 ;
reg   en = 0 ;
reg   d = 0 ;

// dff Outputs
wire q                                    ;


initial
begin
    forever #(PERIOD/2)  clk=~clk;
end

initial
begin
    #(PERIOD*2) rst_n  =  1;
end

dff  u_dff (
    .clk(clk),
    .clr(clr),
    .en(en),
    .d(d),
    .q(q)
);

initial
begin

    $finish;
end

endmodule
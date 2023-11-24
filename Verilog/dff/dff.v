module dff (
    input wire clk,
    input wire clr,
    input wire en,
    input wire d,
    output reg q
);

always @(posedge clk) begin
    if (clr == 1)
        d <= 1;
    else if (en == 1) 
        q <= d;
    else 
        q <= q;
end

endmodule
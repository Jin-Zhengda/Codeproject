`timescale 1ns / 1ps

module flowing_water_lights(
    input wire clk,
    input wire rst,
    input wire button,
    input wire[1:0] freq_set,
    output reg[7:0] led 
    );
    reg cnt_inc;
    reg [31:0] cnt;
    reg [31:0] x;
    wire cnt_end = cnt_inc & (cnt == x);
    
    wire pos_edge;
    reg sig_r0, sig_r1;
    reg flag;
    
    always @(posedge clk)
    begin
        if(rst) sig_r0 <= 1'b0;
        else    sig_r0 <= button;
    end

    always @(posedge clk)
    begin
        if(rst) sig_r1 <= 1'b0;
        else    sig_r1 <= sig_r0;
    end

    assign pos_edge = ~sig_r1 & sig_r0;
    
    always @(*) begin 
        case(freq_set)
            2'b00: x = 32'd1000000;
            2'b01: x = 32'd10000000;
            2'b10: x = 32'd25000000;
            2'b11: x = 32'd100000000;
        endcase
    end
    
    always @ (posedge clk or posedge rst) begin
        if(rst)  cnt_inc <= 1'b0;   
        else if(pos_edge) cnt_inc <= ~cnt_inc;    
    end

    always @ (posedge clk or posedge rst) begin
        if(rst) cnt <= 32'd1;          
        else if(cnt_end)  cnt <= 32'd1;
        else if(cnt_inc) cnt <= cnt + 32'd1; 
    end
    
    always @(posedge clk or posedge rst) begin
        if (rst) led <= 8'b00000001;
        else if (cnt_end) led <= {led[6:0], led[7]};
        else led <= led;
    end
    
    
endmodule
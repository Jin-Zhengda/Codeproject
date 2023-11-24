`timescale 1ns / 1ps

module d_counter(
    input wire clk,
    input wire button1,
    input wire button2,
    output reg[6: 0] num
);

    reg[31: 0] cnt = 32'd1;
    reg cnt_en;
    wire cnt_end = cnt_en & (cnt == 32'd10000000);

    wire pos_edge;
    reg sig_r0, sig_r1;

    always @(posedge clk) begin
        sig_r0 <= button2;
    end

    always @(posedge clk) begin
        sig_r1 <= sig_r0;
    end

    assign pos_edge = ~sig_r1 & sig_r0;
    
    wire rst_n = ~button1;

    always @(posedge clk) begin
        if (pos_edge)
            cnt_en <= ~cnt_en;
    end

    always @(posedge clk) begin
        if (cnt_end) 
            cnt <= 32'd1;
        else if (cnt_en)
            cnt <= cnt + 32'd1;
    end

    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) 
            num <= 7'd0;
        else if (pos_edge && num == 7'd20)
            num <= 7'd0;
        else if (num == 7'd20)
            num <= num;
        else if (cnt_end) 
            num <= num + 7'd1;
        else
            num <= num;
    end

endmodule
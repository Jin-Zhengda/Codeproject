`timescale 1ns / 1ps

module led_display_ctrl(
    input wire clk,
    input wire button1,
    input wire button2,
    input wire button3,
    output reg[7: 0] en,
    output reg[7: 0] cx
);

    wire[6: 0] num21;
    wire[6: 0] num22;
    wire[7: 0] led_en;
    wire[7: 0] led_cx;

    counter u_counter(
        .clk(clk),
        .button1(button1),
        .button3(button3),
        .num(num21)
    );

    d_counter u_d_counter(
        .clk(clk),
        .button1(button1),
        .button2(button2),
        .num(num22)
    );

    led u_led(
        .clk(clk),
        .button1(button1),
        .num21(num21),
        .num22(num22),
        .en(led_en),
        .cx(led_cx)
    );
    
    always @(*) begin
        en = led_en;
        cx = led_cx;
    end

endmodule
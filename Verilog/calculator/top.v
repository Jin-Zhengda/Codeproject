`timescale 1ns / 1ps

module top (
    input wire clk,
    input wire rst,
    input wire euqal,
    input wire[3: 0] row,
    output [3: 0] col,
    output [7: 0] led_en,
    output [7: 0] led_cx
);
    wire pll_out;
    wire pll_lock;
    wire sys_clk;

    clk_div u_clk_div (
        .clk_in(clk),
        .clk_out(pll_out)
        .locked(pll_lock)
    );

    assign sys_clk = pll_out & pll_lock;

    wire keyboard_en;
    wire [3: 0] keyboard_num;

    keyboard u_keyboard (
        .clk(sys_clk),
        .rst(rst),
        .row(row),
        .col(col),
        .keyboard_en(keyboard_en),
        .keyboard_num(keyboard_num)
    );

    wire key_pulse;

    debounce_button u_debounce_button(
        .clk(sys_clk),
        .rst(rst),
        .key(equal),
        .key_pulse(key_pulse)
    );

    wire [15: 0] out;

    calculate u_calculate(
        .clk(sys_clk),
        .rst(rst),
        .key_en(keyboard_en),
        .equal(key_pulse),
        .in(keyboard_num),
        .out(out)
    );

    led u_led (
        .clk(sys_clk),
        .rst(rst),
        .en(keyboard_en),
        .out(out),
        .led_en(led_en),
        .led_cx(led_cx)
    );

endmodule
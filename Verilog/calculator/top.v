`timescale 1ns / 1ps

module top (
    input wire clk,
    input wire rst,
    input wire equal,
    input wire save,
    input wire up,
    input wire down,
    input wire[3: 0] row,
    output [3: 0] col,
    output [7: 0] led_en,
    output [7: 0] led_cx
);
    wire pll_out;
    wire pll_lock;
    wire sys_clk;

    clk_div u_clk_div (
        .clk_in1(clk),
        .clk_out1(pll_out),
        .locked(pll_lock)
    );

    assign sys_clk = pll_out & pll_lock;

    wire keyboard_en;
    wire [3: 0] keyboard_num;
    wire [15: 0] key_posedge;

    keyboard u_keyboard (
        .clk(sys_clk),
        .rst(rst),
        .row(row),
        .col(col),
        .keyboard_en(keyboard_en),
        .keyboard_num(keyboard_num),
        .key_pose(key_posedge)
    );

    wire equal_pulse;
    wire save_pulse;
    wire up_pulse;
    wire down_pulse;

    debounce_button u_debounce_button1(
        .clk(sys_clk),
        .rst(rst),
        .key(equal),
        .key_pulse(equal_pulse)
    );

    debounce_button u_debounce_button2(
        .clk(sys_clk),
        .rst(rst),
        .key(save),
        .key_pulse(save_pulse)
    );

    debounce_button u_debounce_button3(
        .clk(sys_clk),
        .rst(rst),
        .key(up),
        .key_pulse(up_pulse)
    );

    debounce_button u_debounce_button4(
        .clk(sys_clk),
        .rst(rst),
        .key(down),
        .key_pulse(down_pulse)
    );

    wire [15: 0] out;

    calculate u_calculate(
        .clk(sys_clk),
        .rst(rst),
        .key_en(keyboard_en),
        .equal(equal_pulse),
        .save(save_pulse),
        .up(up_pulse),
        .down(down_pulse),
        .in(keyboard_num),
        .out(out)
    );

    led u_led (
        .clk(sys_clk),
        .rst(rst),
        .key_en(keyboard_en),
        .equal(equal_pulse),
        .keyboard_num(keyboard_num),
        .out(out),
        .led_en(led_en),
        .led_cx(led_cx)
    );

endmodule
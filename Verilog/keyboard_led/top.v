`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/17 10:36:53
// Design Name: 
// Module Name: top
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


module top(
    input         clk,
    input         reset,
    input  [3:0]  row,
    output [3:0]  col,
    output        keyboard_en,
    output [15:0] keyboard_led,
//    output [3:0]  keyboard_num,
    output [7:0]  led_en,
    output [7:0]  led_cx,
    output pass_led
);

keyboard u_keyboard(
    .clk(clk), 
    .reset(reset), 
    .row(row), 
    .col(col), 
    .keyboard_en(keyboard_en), 
    .keyboard_led(keyboard_led),   //按键DCBA#9630852*741对应GLD0-GLD7:YLD0-YLD7
//    .keyboard_num(keyboard_num),    // 因只亮一个周期，直接送到led显示将看不到灯亮
    .led_en(led_en),
    .led_cx(led_cx),
    .pass_led(pass_led)
);



endmodule

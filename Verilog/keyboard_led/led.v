`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/17 12:08:07
// Design Name: 
// Module Name: led
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


module led(
    input wire clk,
    input wire rst,
    input wire key_num,
    input wire en,
    output reg[7: 0] led_en,
    output reg[7: 0] led_cx
    );

    reg[31: 0] cnt;
    wire rst_n = ~rst;
    wire cnt_end = cnt == 32'd200000;
    reg[3: 0] num;
    
    
    always @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            cnt <= 32'd1;
        else if (cnt_end)
            cnt <= 32'd1;
        else
            cnt <= cnt + 32'd1;
    end
    
    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) 
            led_en <= 8'b11111111;
        else if (cnt_end)
            led_en <= {~en[7], en[6: 0]};
        else 
            led_en <= led_en;
    end

    always@(*) begin
        if (en && led_en == 8'b01111111)
            num <= key_num;
        else if (~en)
            num <= Z;
        else
            num <= 4'd0;
    end

    always @(*) begin
        case(num)
            4'h0: led_cx = 8'b00000011;
            4'h1: led_cx = 8'b10011111;
            4'h2: led_cx = 8'b00100101;
            4'h3: led_cx = 8'b00001101;
            4'h4: led_cx = 8'b10011001;
            4'h5: led_cx = 8'b01001001;
            4'h6: led_cx = 8'b01000001;
            4'h7: led_cx = 8'b00011111;
            4'h8: led_cx = 8'b00000001;
            4'h9: led_cx = 8'b00011001;
            4'ha: led_cx = 8'b;
            4'hb: led_cx = 8'b;
            4'hc: led_cx = 8'b;
            4'hd: led_cx = 8'b;
            4'he: led_cx = 8'b;
            4'hf: led_cx = 8'b;
            Z: led_cx = 8'b;
            default led_cx = 8'b00011001;
        endcase
    end
    
endmodule

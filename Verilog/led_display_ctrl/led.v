`timescale 1ns / 1ps

module led(
    input wire clk,
    input wire button1,
    input wire[6: 0] num21,
    input wire[6: 0] num22,
    output reg[7: 0] en,
    output reg[7: 0] cx
);
    
    
    reg[3: 0] num1 = 4'd0;
    reg[3: 0] num2 = 4'd5;
    reg[3: 0] num3 = 4'd1;
    reg[3: 0] num4 = 4'd5;
    reg[3: 0] num5;
    reg[3: 0] num6;
    reg[3: 0] num7;
    reg[3: 0] num8;

    reg[3: 0] num;

    wire rst_n = ~button1;
    
    always @(posedge clk) begin
        num5 <= num21 / 10;
        num6 <= num21 % 10;
        num7 <= num22 / 10;
        num8 <= num22 % 10;
    end
    
    reg[31: 0] cnt;
    wire cnt_end = cnt == 32'd200000;
    
    
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
            en <= 8'b01111111;
        else if (cnt_end)
            en <= {en[0], en[7: 1]};
        else 
            en <= en;
    end

    always @(*) begin
        case(en)
            8'b01111111: num = num1;
            8'b10111111: num = num2;
            8'b11011111: num = num3;
            8'b11101111: num = num4;
            8'b11110111: num = num5;
            8'b11111011: num = num6;
            8'b11111101: num = num7;
            8'b11111110: num = num8;
            default num = 4'd0;
        endcase
    end

    always @(*) begin
        case(num)
            4'd0: cx = 8'b00000011;
            4'd1: cx = 8'b10011111;
            4'd2: cx = 8'b00100101;
            4'd3: cx = 8'b00001101;
            4'd4: cx = 8'b10011001;
            4'd5: cx = 8'b01001001;
            4'd6: cx = 8'b01000001;
            4'd7: cx = 8'b00011111;
            4'd8: cx = 8'b00000001;
            4'd9: cx = 8'b00011001;
            default cx = 8'b00011001;
        endcase
    end

endmodule
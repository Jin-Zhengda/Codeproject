`timescale 1ns / 1ps

module led ( 
    input wire clk,
    input wire rst,
    input wire en,
    input wire[15: 0] out,
    output reg[7: 0] led_en,
    output reg[7: 0] led_cx
);

    wire cnt_end;

    counter #(20000, 32) u_counter (
        .clk(clk),
        .rst(rst),
        .cnt_inc(1),
        .cnt_end(cnt_end)
    );
    
    always @(posedge clk or posedge rst) begin
        if (rst) 
            led_en <= 8'b01111111;
        else if (cnt_end)
            led_en <= {en[4], en[7: 5], en[3: 0]};
        else 
            led_en <= led_en;
    end


    reg[3: 0] num1;
    reg[3: 0] num2;
    reg[3: 0] num3;
    reg[3: 0] num4;

    always @(*) begin
        num1 = out / 16'd1000;
        num2 = out / 16'd100 % 16'd10;
        num3 = out / 16'd10 % 16'd10;
        num4 = out % 16'd10;
    end

    reg[3: 0] num;

    always@(*) begin
        case (en)
            8'b01111111: num = num1;
            8'b10111111: num = num2;
            8'b11011111: num = num3;
            8'b11101111: num = num4;
        default num = 0;
        endcase
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
            4'ha: led_cx = 8'b00010001;
            4'hb: led_cx = 8'b11000001;
            4'hc: led_cx = 8'b11100101;
            4'hd: led_cx = 8'b10000101;
            4'he: led_cx = 8'b01100001;
            4'hf: led_cx = 8'b01110001;
            default led_cx = 8'b00011001;
        endcase
    end
    

endmodule
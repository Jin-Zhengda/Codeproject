`timescale 1ns / 1ps

module led ( 
    input wire clk,
    input wire rst,
    input wire[15: 0] key_en,
    input wire equal,
    input wire[3: 0] keyboard_num,
    input wire[15: 0] out,
    output reg[7: 0] led_en,
    output reg[7: 0] led_cx
);

    wire cnt_end;
    reg flag;

    counter #(20000, 32) u_counter (
        .clk(clk),
        .rst(rst),
        .cnt_inc(1),
        .cnt_end(cnt_end)
    );

    
    always @(posedge clk or posedge rst) begin
        if (rst) 
            led_en <= 8'b11111110;
        else if (cnt_end)
            led_en <= {led_en[0], led_en[7: 1]};
        else 
            led_en <= led_en;
    end


    reg[15: 0] mid_num1;
    reg[15: 0] mid_num2;
    
    always @(posedge clk or posedge rst) begin
        if (rst) mid_num1 <= 0;
        else if (key_en) mid_num1 <= {mid_num1[11: 0], keyboard_num};
        else mid_num1 <= mid_num1;
    end
    
    always @(*) begin
        if (rst) mid_num2 = 0;
        else begin
            mid_num2[15: 12] = out / 16'd1000;
            mid_num2[11: 8] = out / 16'd100 % 16'd10;
            mid_num2[7: 4] = out / 16'd10 % 16'd10;
            mid_num2[3: 0] = out % 16'd10;
        end
    end
    

    reg[3: 0] num;

    always@(*) begin
            case (led_en)
                8'b01111111: num = mid_num1[15: 12];
                8'b10111111: num = mid_num1[11: 8];
                8'b11011111: num = mid_num1[7: 4];
                8'b11101111: num = mid_num1[3: 0];
                8'b11110111: num = mid_num2[15: 12];
                8'b11111011: num = mid_num2[11: 8];
                8'b11111101: num = mid_num2[7: 4];
                8'b11111110: num = mid_num2[3: 0];
                default num = num;
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
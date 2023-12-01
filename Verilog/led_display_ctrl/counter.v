`timescale 1ns / 1ps

module counter(
    input wire clk,
    input wire button1,
    input wire button3,
    output reg[6: 0] num
);

    wire pos_edge;

    debounce_button u_debounce_button(
        .clk(clk),
        .button1(button1),
        .key(button3),
        .key_pulse(pos_edge)
    );
    
    wire rst_n = ~button1;
    
    always @(posedge clk or negedge rst_n) begin 
        if (~rst_n)
            num <= 7'd0;
        else if (pos_edge) begin
            if (num == 7'd99) 
                num <= 7'd0;
            else
                num <= num + 7'd1;
        end
        else
            num <= num;
    end

endmodule
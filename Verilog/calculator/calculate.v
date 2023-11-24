`timescale 1ns / 1ps

module calculate (
    input wire clk,
    input wire rst,
    input wire key_en,
    input wire equal,
    input wire [3: 0] in,
    output reg [15: 0] out
);

    parameter S0 = 3'b001;
    parameter S1 = 3'b010;
    parameter S2 = 3'b100;

    reg [7: 0] num1;
    reg [7: 0] num2;
    reg [3: 0] op;

    reg [2:0] current_state;
    reg [2:0] next_state;
    reg [1:0] out ;

    always @(posedge clk or negedge rst_n) begin
        if(~rst_n) current_state <= IDLE;
        else       current_state <= next_state;
    end

    always @(*) begin
        case (current_state)
            IDLE: if(...) next_state = S1;
                else    next_state = IDLE;
            S1: if(...) next_state = S2;
                else    next_state = S1;
            S2: if(...) next_state = IDLE;
                else    next_state = S2;
            default : next_state = IDLE;
        endcase
    end


    always @(posedge clk or negedge rst_n) begin
        if(~rst_n) out <= 2'b00;
        else begin
            case(current_state)
                S1 : out <= 2'b01;
                S2 : out <= 2'b10;
                default : out <=2'b00;
            endcase
        end
    end
    
endmodule
`timescale 1ns / 1ps

module save_nums(
    input wire clk,
    input wire rst,
    input wire equal,
    input wire save,
    input wire up,
    input wire down,
    input [15: 0] result,
    output reg [15: 0] last_out
);

    parameter S0 = 3'd0;
    parameter S1 = 3'd1;
    parameter S2 = 3'd2;
    parameter S3 = 3'd3;
    parameter S4 = 3'd4;

    reg [63: 0] num_saved;
    reg [2: 0] current_state;
    reg [2: 0] next_state;
    
    always @(posedge clk or posedge rst) begin
        if (rst) num_saved <= 0;
        else if (save) num_saved <= {num_saved[47: 0], result};
        else num_saved <= num_saved;
    end

    always @(posedge clk or posedge rst) begin
        if(rst) current_state <= S0;
        else current_state <= next_state;
    end

    always @(*) begin
        case(current_state)
            S0: if (up) next_state = S1;
                else next_state = S0;
            S1: if (equal) next_state = S0;
                else if (up) next_state = S2;
                else if (down) next_state = S0;
                else next_state = S1;
            S2: if (equal) next_state = S0;
                else if (up) next_state = S3;
                else if (down) next_state = S1;
                else next_state = S2;
            S3: if (equal) next_state = S0;
                else if (up) next_state = S4;
                else if (down) next_state = S2;
                else next_state = S3;
            S4: if (equal) next_state = S0;
                else if (down) next_state = S3;
                else next_state = S4;
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if (rst) last_out <= 0;
        else begin 
            case(current_state)
                S0: last_out <= result;
                S1: last_out <= num_saved[15: 0];
                S2: last_out <= num_saved[31: 16];
                S3: last_out <= num_saved[47: 32];
                S4: last_out <= num_saved[63: 48];
                default : last_out <= 0;
            endcase
        end
    end

endmodule
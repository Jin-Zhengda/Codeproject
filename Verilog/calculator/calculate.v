`timescale 1ns / 1ps

module calculate (
    input wire clk,
    input wire rst,
    input wire key_en,
    input wire equal,
    input wire save,
    input wire up,
    input wire down,
    input wire [3: 0] in,
    output reg [15: 0] out
);

    parameter S0 = 3'd0;
    parameter S1 = 3'd1;
    parameter S2 = 3'd2;
    parameter S3 = 3'd3;
    parameter S4 = 3'd4;
    parameter S5 = 3'd5;
    parameter S6 = 3'd6;

    reg [15: 0] num1 = 0;
    reg [15: 0] num2 = 0;
    reg [3: 0] op;

    reg [2: 0] current_state;
    reg [2: 0] next_state;
    wire [15: 0] last_out;
    reg [15: 0] result;

    wire cnt_end;

    counter #(2000, 32) u_counter(
        .clk(clk), 
        .rst(rst), 
        .cnt_inc(1),
        .cnt_end(cnt_end)
    );


    always @(posedge clk or posedge rst) begin
        if(rst) current_state <= S0;
        else current_state <= next_state;
    end


    always @(*) begin
        case (current_state)
            S0: if(key_en) begin
                    if (in <= 9) next_state = S1;
                    else next_state = S2;
                end 
                else next_state = S0;
            S1: if (key_en) begin 
                    if (in <= 9 ) next_state = S3;
                    else next_state = S2;
                end 
                else next_state = S1;
            S2: if(key_en && in <= 9) next_state = S4;
                else next_state = S2;
            S3: if (key_en) next_state = S2;
                else next_state = S3;
            S4: if(key_en) begin
                    if (in <= 9) next_state = S5;
                end
                else if (equal) next_state = S6;
                else next_state = S4;
            S5: if(equal) next_state = S6;
                else next_state = S5;
            S6: if (cnt_end) next_state = S0;
                else next_state = S6;
            default : next_state = S0;
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if(rst) result <= 16'd0;
        else begin
            case(current_state)
                S0: if(key_en) begin
                        if (in <= 9) num1 <= in;
                        else begin
                            op <= in;
                            num1 <= last_out;
                        end
                   end
                S1: if (key_en) begin
                        if (in <= 9 ) num1 <= num1 * 10 + in;
                        else op <= in;
                    end
                S2: if(key_en && in <= 9) num2 <= in;
                S3: if(key_en) op <= in;
                S4: if(key_en && in <= 9) num2 <= num2 * 10 + in;
                S6: begin
                    case (op)
                        4'ha: result <= num1 + num2;
                        4'hb: result <= num1 - num2;
                        4'hc: result <= num1 * num2;
                        4'hd: result <= num1 / num2;
                        default : result <= result;
                    endcase
                end
                default: result <= result;
            endcase     
        end
    end

    save_nums u_save_nums(
        .clk(clk),
        .rst(rst),
        .equal(equal),
        .save(save),
        .up(up),
        .down(down),
        .result(result),
        .last_out(last_out)
    );


    always @(posedge clk or posedge rst) begin
           if (rst) out <= 0;
           else out <= last_out;
    end
endmodule
`timescale 1ns / 1ps

module debounce_button(
        input wire clk,
        input wire rst,
        input wire key,                             
        output reg key_pulse      
);

        reg key_last;               
        reg key_now;
        reg [31:0] cnt;                                    
 
        always @(posedge clk or posedge rst) begin
            if (rst) begin
                key_last <= 1'b0;
                key_now <= 1'b0;
                key_pulse <= 1'b0;
            end       
            else begin
                if (key_last == key_now) begin
                    key_now <= key;
                    key_last <= key_now;
                    key_pulse <= 0;
                    cnt <= 32'd1;
                end
                else begin
                    if (cnt >= 32'd1500000) begin
                        key_pulse <= key_now & ~key_last;
                        key_now <= key;
                        key_last <= key_now;
                    end
                    else
                        cnt <= cnt + 32'd1;
                end
            end        
        end

endmodule



`timescale 1ns / 1ps

module debounce_button(
        input wire clk,
        input wire button1,
        input wire key,                             
        output reg key_pulse      
);

        wire rst_n = ~button1;
        reg key_last;               
        reg key_now;
        reg [31:0] cnt;                                    
 
        always @(posedge clk or negedge rst_n) begin
            if (~rst_n) begin
                key_last <= 1'b0;
                key_now <= 1'b0;
                key_pulse <= 1'b0;
            end       
            else begin
                if (key_last == key_now) begin
                    key_now <= key;
                    key_last <= key_now;
                    cnt <= 32'd1;
                end
                else begin
                    if (cnt >= 32d'1500000) begin
                        key_pulse <= 
                    end
                    else
                        cnt <= cnt + 32'd1;
                end
            end        
        end

endmodule



`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////////
//// Company: 
//// Engineer: 
//// 
//// Create Date: 2023/11/17 11:20:39
//// Design Name: 
//// Module Name: password
//// Project Name: 
//// Target Devices: 
//// Tool Versions: 
//// Description: 
//// 
//// Dependencies: 
//// 
//// Revision:
//// Revision 0.01 - File Created
//// Additional Comments:
//// 
////////////////////////////////////////////////////////////////////////////////////


module password(
   input wire clk,
   input wire keyboard_en,
   input wire [3:0] keyboard_num,
   input wire rst,
   output reg en
   );
    
   parameter S0 = 3'd0;
   parameter S1 = 3'd1;
   parameter S2 = 3'd2;
   parameter S3 = 3'd3;
   parameter S4 = 3'd4;
   parameter S5 = 3'd5;
   parameter S6 = 3'd6;
    
   reg [3:0] current_state;
   reg [3:0] next_state;
   wire rst_n = ~rst;
    

always @(posedge clk or negedge rst_n) begin
   if(~rst_n) current_state <= S0;
   else       current_state <= next_state;
end

reg [3:0] num_temp;
always @(*)
        if (keyboard_en)
            num_temp = keyboard_num;
        else 
            num_temp = num_temp;

wire cnt_end;
counter #(200, 32) m_counter(
    .clk(clk), 
    .reset(rst), 
    .cnt_inc(1),
    .cnt_end(cnt_end)
);


always @(*) begin
   case (current_state)
        S0: if (keyboard_en) begin
                if(num_temp == 4'h0) next_state = S1;
                else next_state = S4;
            end 
            else next_state = S0;
        S1: if (keyboard_en) begin
                if(num_temp == 4'h1) next_state = S2;
                else next_state = S5;
            end 
            else next_state = S1;
        S2: if (keyboard_en) begin
                if(num_temp == 4'h5) next_state = S3;
                else next_state = S6;
            end 
            else next_state = S2;
        S3: if (cnt_end) next_state = S3;
            else next_state = S3;
        S4: if (keyboard_en) next_state = S5;
            else next_state = S4;
        S5: if (keyboard_en) next_state = S6;
            else next_state = S5;
        S6: if (cnt_end) next_state = S0;
            else next_state = S6;
        default : next_state = S0;
   endcase
end


always @(posedge clk or negedge rst_n) begin
   if(~rst_n) en <= 1'bz;
   else begin
       case(current_state)
           S3: en <= 1'b1;
           S6: en <= 1'b0;
           default : en <= 1'bz;
       endcase
   end
end
    
endmodule

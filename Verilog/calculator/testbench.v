`timescale 1ns/1ps         

module keyboard_sim();    

reg        clk;
reg        reset;
reg        button;
reg  [3:0] row;
wire [3:0] col;
wire [15:0] keyboard_led;
wire [3:0]  keyboard_num;
wire        keyboard_en;
wire        cnt_end;
wire [7: 0] led_en;
wire [7: 0] led_cx;

reg [7:0] keycase_cnt;   //按键个数计数
wire keycase_inc;

parameter CNT_THRESHOLD=5;

counter #(CNT_THRESHOLD, 24) u_test_counter(     //用于生成时序匹配的row信号
    .clk(clk), 
    .rst(reset), 
    .cnt_inc(1), 
    .cnt_end(cnt_end)
);

top u_top(
    .clk(clk),
    .rst(reset),
    .equal(button),
    .row(row),
    .col(col),
    .led_en(led_en),
    .led_cx(led_cx)
);
   
always #10 clk = ~clk;

initial begin
    reset = 1'b1;  
    clk = 0; 
    button = 0;
    row = 4'b1111;
    # 10
    reset = 1'b0;
    #2400 button = 1;
    #20 button = 0;
    #1300 button = 1;
    #20 button = 0;
    #100
    $finish;
end
    

assign keycase_inc = cnt_end;

always @(posedge clk, posedge reset) begin
    if (reset) keycase_cnt <= 0;
    else if (keycase_inc) keycase_cnt <= keycase_cnt + 1;
end
    
always @(*) begin
    case(keycase_cnt[7:2])  
        8'b0000_00:
            if(col==4'b1011) row = 4'b0111;  
            else row = 4'b1111;
        8'b0000_01: 
            if(col==4'b1101) row = 4'b0111;
            else row = 4'b1111;
        8'b0000_10: 
            if(col==4'b1110) row = 4'b1101;
            else row = 4'b1111;
        8'b0000_11:
            if(col==4'b0111) row = 4'b0111;
            else row = 4'b1111;
        8'b0001_00: 
            if(col==4'b1011) row = 4'b0111;
            else row = 4'b1111;      
        8'b0001_01:                          
            if(col==4'b1110) row = 4'b1110;
            else row = 4'b1111;
        8'b0001_10:
            if(col==4'b0111) row = 4'b0111;
            else row = 4'b1111;
        8'b0001_11: 
            if(col==4'b1011) row = 4'b1101;
            else row = 4'b1111; 
//        8'b0001_11: 
//            if(col==4'b1101) row = 4'b0111;
//            else row = 4'b1111; 
        default:
            row = 4'b1111; 
    endcase
end

   
endmodule
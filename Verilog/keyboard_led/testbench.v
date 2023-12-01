`timescale 1ns/1ps         

module keyboard_sim();    

reg        clk;
reg        reset;
reg  [3:0] row;
wire [3:0] col;
wire [15:0] keyboard_led;
wire [3:0]  keyboard_num;
wire        keyboard_en;
wire        cnt_end;

reg [7:0] keycase_cnt;   //������������
wire keycase_inc;

parameter CNT_THRESHOLD=5;

counter #(CNT_THRESHOLD, 24) u_test_counter(     //��������ʱ��ƥ���row�ź�
    .clk(clk), 
    .reset(reset), 
    .cnt_inc(1), 
    .cnt_end(cnt_end)
);

keyboard #(CNT_THRESHOLD) u_keyboard(   
    .clk(clk), 
    .reset(reset), 
    .row(row), 
    .col(col), 
    .keyboard_en(keyboard_en), 
    .keyboard_led(keyboard_led)
);
   
always #5 clk = ~clk;

initial begin
    reset = 1'b1;  
    clk = 0; 
    row = 4'b1111;
    # 10
    reset = 1'b0;
    # 10000
    $finish;
end
    

assign keycase_inc = cnt_end;

always @(posedge clk, posedge reset) begin
    if (reset) keycase_cnt <= 0;
    else if (keycase_inc) keycase_cnt <= keycase_cnt + 1;
end
    
always @(*) begin
    case(keycase_cnt[7:2])  //ÿ��4��ɨ�裬ȥ����2λ���ڼ���������������
        8'b0000_00:
            if(col==4'b1110) row = 4'b1110;  // �����ұߵ�һ�а�������
            else row = 4'b1111;
        8'b0000_01: 
            if(col==4'b1110) row = 4'b1101;
            else row = 4'b1111;
        8'b0000_10:
            if(col==4'b1110) row = 4'b1011;
            else row = 4'b1111;
        8'b0000_11: 
            if(col==4'b1110) row = 4'b0111;
            else row = 4'b1111;      
        8'b0001_00:                           //�����ұߵڶ��а�������
            if(col==4'b1101) row = 4'b1110;
            else row = 4'b1111;
        8'b0001_01:
            if(col==4'b1101) row = 4'b1101;
            else row = 4'b1111;
        8'b0001_10: 
            if(col==4'b1101) row = 4'b1011;
            else row = 4'b1111; 
        8'b0001_11: 
            if(col==4'b1101) row = 4'b0111;
            else row = 4'b1111; 
        default:
            row = 4'b1111; 
    endcase
end

/*
      case ({col, row})  // ����������Դ˽�������������
        8'b1110_1110 : keyboard_num <= 4'hd;   // key_posedge[0]
        8'b1110_1101 : keyboard_num <= 4'hc;   // key_posedge[1]
        8'b1110_1011 : keyboard_num <= 4'hb;   // key_posedge[2]
        8'b1110_0111 : keyboard_num <= 4'ha;   // key_posedge[3]  �����Դ����ƣ�

        8'b1101_1110 : keyboard_num <= 4'hf;  // #��
        8'b1101_1101 : keyboard_num <= 4'h9;
        8'b1101_1011 : keyboard_num <= 4'h6;
        8'b1101_0111 : keyboard_num <= 4'h3;

        8'b1011_1110 : keyboard_num <= 4'h0;
        8'b1011_1101 : keyboard_num <= 4'h8;
        8'b1011_1011 : keyboard_num <= 4'h5;
        8'b1011_0111 : keyboard_num <= 4'h2;

        8'b0111_1110 : keyboard_num <= 4'he;  // *��
        8'b0111_1101 : keyboard_num <= 4'h7;
        8'b0111_1011 : keyboard_num <= 4'h4;
        8'b0111_0111 : keyboard_num <= 4'h1;        
      endcase
   */
   
endmodule

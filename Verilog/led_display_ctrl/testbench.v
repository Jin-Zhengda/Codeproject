`timescale 1ns / 1ps

module testbench(
    );
    
    reg clk = 0;
    reg button1;
    reg button2;
    reg button3;
    wire[7: 0] en;
    wire[7: 0] cx;
    
    led_display_ctrl u_led_display_ctrl(
        .clk(clk),
        .button1(button1),
        .button2(button2),
        .button3(button3),
        .en(en),
        .cx(cx)
    );
    
    
    always #5 clk = ~clk;
    
    initial begin
        button1 = 0; button2 = 0;button3 = 0;
        #5 begin button1 = 1;end
        #5 begin button1 = 0;end
        #5 begin button3 = 1;button2 = 1;end
        #1 begin button2 = 0;end
        #1 begin button2 = 1;end
        #1 begin button2 = 0;end
        #1 begin button2 = 1;end
        #1 begin button3 = 0;button2 = 0;end
        #2 begin button2 = 1;end
        #2 begin button2 = 0;end
        #2 begin button2 = 1;end
        #10 begin button2 = 0;end
        #34 begin button3 = 1;end
        #5 begin button3 = 0;end
        #20 begin button3 = 1;end
        #5 begin button3 = 0;end
        #220 begin button3 = 1;end
        #5 begin button3 = 0;end
        #25 $finish;
    end
    
endmodule

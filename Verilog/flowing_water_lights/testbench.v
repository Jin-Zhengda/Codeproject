`timescale 1ns/1ps         

module testbench(); 
    reg clk = 0;
    reg rst;
    reg button;
    reg [1:0] freq_set;
    wire [7: 0] led;

    always #5 clk = ~clk;

    flowing_water_lights u_flowing_water_lights(
        .clk(clk),
        .rst(rst),
        .button(button),
        .freq_set(freq_set),
        .led(led)
    );  

    initial   
    begin
        rst = 0; button = 0; freq_set = 2'b01;
        #5 begin rst = 1;end
        #5 begin rst = 0;end
        #10 begin button = 1;end
        #10 begin button = 0;end
        #230 begin button = 1;end
        #10 begin button = 0;end
        #20 begin freq_set = 2'b10; end
        #10 begin rst = 1;end
        #5 begin rst = 0;end
        #10 begin button = 1;end
        #10 begin button = 0;end
        #300 $finish; 
    end

endmodule
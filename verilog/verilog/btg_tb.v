`timescale 1ps/1ps

module binary_to_gray_tb();
    reg [3:0] binary;

    wire [3:0] gray;

    // instantiate
    binary_to_gray_4bit uut (
        .binary(binary),
        .gray(gray)
    );

    initial begin
        $dumpfile("binary_to_gray.vcd");
        $dumpvars(0,binary_to_gray_tb);

        $display("-----------------------------------------------------");
        $display("Time | binary | Gray Code");
        $display("-----------------------------------------------------");

        // monitering changes
        $monitor("%0t | %b | %b" , $time , binary , gray);

        // test all possible\

        for (integer i = 0;i < 16 ; i = i +1) begin
            #10;
            binary = i;
        end

        $display("----------------------------------------------------");
        $finish;


    end

endmodule
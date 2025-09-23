`timescale 1ps/1ps

module fulle_adder_tb();

    reg a , b ,cin ;
    wire sum, cout;


    full_adder_gate uut(
        .a(a),
        .b(b),
        .cin(cin),
        .sum(sum),
        .cout(cout)
    );

    initial begin
        $dumpfile("full_adder.vcd");
        $dumpvars(0,fulle_adder_tb);

        $display("------------------------------------");
        $display("Time | a | b | cin | sum | cout");
        $display("------------------------------------");

        $monitor("%0t | %b | %b | %b | %b | %b", $time, a,b,cin ,sum , cout);

        a = 1'b0; b = 1'b0; cin = 1'b0;
        #10;

        // a=0, b=0, cin=1
        a = 1'b0; b = 1'b0; cin = 1'b1;
        #10;

        // a=0, b=1, cin=0
        a = 1'b0; b = 1'b1; cin = 1'b0;
        #10;

        // a=0, b=1, cin=1
        a = 1'b0; b = 1'b1; cin = 1'b1;
        #10;

        // a=1, b=0, cin=0
        a = 1'b1; b = 1'b0; cin = 1'b0;
        #10;

        // a=1, b=0, cin=1
        a = 1'b1; b = 1'b0; cin = 1'b1;
        #10;

        // a=1, b=1, cin=0
        a = 1'b1; b = 1'b1; cin = 1'b0;
        #10;

        // a=1, b=1, cin=1
        a = 1'b1; b = 1'b1; cin = 1'b1;
        #10;
        
        $display("---------------------------------------");
        $finish;

    end

endmodule

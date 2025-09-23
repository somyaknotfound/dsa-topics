
`timescale 1ps/1ps

module circ1_behav_tb;

    reg a,b,c;
    wire f_original,f_simplified;

    circ1_behav uut(
        .a(a),
        .b(b),
        .c(c),
        .f_original(f_original),
        .f_simplified(f_simplified)
    );

    initial begin
        $dumpfile("circ1behav.vcd");
        $dumpvars(0,circ1_behav_tb);

        $display("----------------------------------------------------------");
        $display("Time | a | b | c | f_original | f_simplified");
        $display("----------------------------------------------------------");

        $monitor("%0t  | %b | %b | %b |   %b   |   %b  ", $time,a,b,c,f_original,f_simplified);

        for (integer i = 0 ; i < 8 ; i = i+1) begin
            {a,b,c} = i;
            #10;
        end

        $display("-------------------------------------------------------------");
        $finish;
    end


endmodule
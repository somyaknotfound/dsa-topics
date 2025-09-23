module excess3_to_bcd_tb();

    reg [3:0] excess3;
    wire [3:0] bcd;

    excess3_to_bcd uut (
        .excess3(excess3),
        .bcd(bcd)
    );
    initial begin
        $dumpfile("excess3_to_bcd.vcd");
        $dumpvars(0,excess3_to_bcd_tb);

        $display("------------------------------------------");
        $display("Time | excess3 | BCD");
        $display("------------------------------------------");

        $monitor("%0t | %b | %b" , $time , excess3 , bcd);

        for (integer i = 3 ; i <= 12 ; i = i+1) begin
            #10
            excess3 = i;
        end


        $display("------------------------------------------");
        $finish;
    end

endmodule
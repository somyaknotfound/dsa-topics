module bcd_to_excess3_tb();

    reg [3:0] bcd;
    wire [3:0] excess3;

    bcd_to_excess3 uut (
        .bcd(bcd),
        .excess3(excess3)
    );

    initial begin
        $dumpfile("bcd_to_excess3.vcd");
        $dumpvars(0,bcd_to_excess3_tb);

        $display("--------------------------------------------------");
        $display("Time | BCD | EXCESS3");
        $display("--------------------------------------------------");

        $monitor("%0t | %b | %b", $time,bcd,excess3);

        for (integer i = 0;i < 16;i = i+1) begin
            #10;
            bcd = i;
        end

        $display("--------------------------------------------------");
        $finish;
    end



endmodule
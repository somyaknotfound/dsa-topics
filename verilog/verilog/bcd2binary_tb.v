module bcd_to_binary_tb();

    reg [3:0] bcd;
    wire [3:0] binary;

    bcd_to_binary uut (
        .bcd(bcd),
        .binary(binary)
    );
    
    initial begin
        
        $dumpfile("bcd_to_binary.vcd");
        $dumpvars(0,bcd_to_binary_tb);

        $display("-----------------------------------------------------------------");
        $display("Time | BCD | Binary");
        $display("-----------------------------------------------------------------");

        $monitor("%0t | %b | %b", $time , bcd , binary);

        for (integer i = 0 ; i < 16 ; i = i+1) begin
            #10;
            bcd = i;
        end

        $display("------------------------------------------------------------------");
        $finish;
    end

endmodule
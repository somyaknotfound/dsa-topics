module gray_to_binary_tb();
    reg [3:0] gray;
    wire [3:0] binary;

    gray_to_binary_4bit uut (
        .gray(gray),
        .binary(binary)
    );
    
    initial begin
        
        $dumpfile("gray_to_binary.vcd");
        $dumpvars(0,gray_to_binary_tb);

        $display("---------------------------------------------------");
        $display("Time | gray | binary");
        $display("---------------------------------------------------");

        // testing all possible gray codes

        $monitor("%0t | %b | %b",$time,gray,binary);

        gray = 4'b0000; #10;
        gray = 4'b0001; #10;
        gray = 4'b0011; #10;
        gray = 4'b0010; #10;
        gray = 4'b0110; #10;
        gray = 4'b0111; #10;
        gray = 4'b0101; #10;
        gray = 4'b0100; #10;
        gray = 4'b1100; #10;
        gray = 4'b1101; #10;
        gray = 4'b1111; #10;
        gray = 4'b1110; #10;
        gray = 4'b1010; #10;
        gray = 4'b1001; #10;
        gray = 4'b1000; #10;

        $display("--------------------------------------------------");
        $finish;

    end

endmodule
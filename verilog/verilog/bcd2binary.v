module bcd_to_binary(
    input [3:0] bcd,
    output reg [3:0] binary
);

    always @(*) begin
        if (bcd<= 4'd9)
            binary = bcd;
        else 
            binary = 4'bxxxx;
    end

endmodule
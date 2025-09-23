module excess3_to_bcd(
    input [3:0] excess3,
    output [3:0] bcd
);

    assign bcd = excess3 - 4'd3;
    

endmodule
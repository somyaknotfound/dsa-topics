module bcd_to_excess3(
    input [3:0] bcd,
    output [3:0] excess3
);

    assign excess3 = bcd + 4'd3;
    

endmodule

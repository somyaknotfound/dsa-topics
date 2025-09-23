module half_adder(
    input a,b,
    output sum,carry
);

    xor x1(sum,a,b);
    and a1(carry,a,b);

endmodule
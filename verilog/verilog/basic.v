module basic_gates(
    input a,b,
    output and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out
);


    and g1(and_out,a,b);
    or g2(or_out,a,b);
    not g3(not_out, a);
    nand g4(nand_out, a, b);
    nor g5(nor_out, a, b);
    xor g6(xor_out, a, b);
    xnor g7(xnor_out, a, b);

endmodule


module xor_using_nand(
    input a,b,
    output y
);

    wire nand_out1 , nand_out2 , nand_out3;

    nand n1(nand_out1,a,b);
    nand n2(nand_out2,a,nand_out1);
    nand n3(nand_out2,b,nand_out1);
    nand n4(y,nand_out2,nand_out3);
    


endmodule
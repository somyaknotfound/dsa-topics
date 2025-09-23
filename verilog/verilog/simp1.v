module circ1_behav(
    input a,b,c,
    output reg f_original , f_simplified
);

    always @(*) begin
        f_original = (~a & b & c) | (a & b & ~c) | (a & b & c) | (~a & ~b & ~c);
        f_simplified = (b & c) | (~a & ~b & ~c);
        
    end


endmodule
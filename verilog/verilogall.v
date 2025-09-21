// ====================================================================
// VERILOG PRACTICE - BASIC GATES, ADDERS & CODE CONVERTERS
// ====================================================================

// ====================================================================
// 1. BASIC GATES (Gate Level Modeling)
// ====================================================================

module basic_gates(
    input a, b,
    output and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out
);
    // Gate level implementation
    and g1(and_out, a, b);
    or g2(or_out, a, b);
    not g3(not_out, a);
    nand g4(nand_out, a, b);
    nor g5(nor_out, a, b);
    xor g6(xor_out, a, b);
    xnor g7(xnor_out, a, b);
endmodule

// ====================================================================
// 2. BOOLEAN SIMPLIFICATION EXAMPLES
// ====================================================================

// Example: F = A'B + AB' + AB = A'B + A (Simplified)
module boolean_simplification_1(
    input a, b,
    output f_original, f_simplified
);
    // Original expression: A'B + AB' + AB
    wire ab_bar, a_bar_b, ab;
    
    not n1(a_bar, a);
    and a1(a_bar_b, a_bar, b);
    and a2(ab_bar, a, b_bar);
    and a3(ab, a, b);
    not n2(b_bar, b);
    or o1(f_original, a_bar_b, ab_bar, ab);
    
    // Simplified: A'B + A
    or o2(f_simplified, a_bar_b, a);
endmodule

// Example: F = AB + A'B + A'B' = A' + B (Simplified using De Morgan's)
module boolean_simplification_2(
    input a, b,
    output f_original, f_simplified
);
    // Original: AB + A'B + A'B'
    wire ab, a_bar_b, a_bar_b_bar, a_bar, b_bar;
    
    not n1(a_bar, a);
    not n2(b_bar, b);
    and a1(ab, a, b);
    and a2(a_bar_b, a_bar, b);
    and a3(a_bar_b_bar, a_bar, b_bar);
    or o1(f_original, ab, a_bar_b, a_bar_b_bar);
    
    // Simplified: A' + B
    or o2(f_simplified, a_bar, b);
endmodule

// Example: XOR gate using NAND gates only
module xor_using_nand(
    input a, b,
    output y
);
    wire nand1_out, nand2_out, nand3_out;
    
    nand n1(nand1_out, a, b);
    nand n2(nand2_out, a, nand1_out);
    nand n3(nand3_out, b, nand1_out);
    nand n4(y, nand2_out, nand3_out);
endmodule

// ====================================================================
// 3. HALF ADDER - Multiple Implementation Styles
// ====================================================================

// Gate Level Half Adder
module half_adder_gate(
    input a, b,
    output sum, carry
);
    xor x1(sum, a, b);
    and a1(carry, a, b);
endmodule

// Behavioral Half Adder
module half_adder_behavioral(
    input a, b,
    output reg sum, carry
);
    always @(*) begin
        sum = a ^ b;
        carry = a & b;
    end
endmodule

// Dataflow Half Adder
module half_adder_dataflow(
    input a, b,
    output sum, carry
);
    assign sum = a ^ b;
    assign carry = a & b;
endmodule

// ====================================================================
// 4. FULL ADDER - Multiple Implementation Styles
// ====================================================================

// Gate Level Full Adder
module full_adder_gate(
    input a, b, cin,
    output sum, cout
);
    wire s1, c1, c2;
    
    xor x1(s1, a, b);
    xor x2(sum, s1, cin);
    and a1(c1, a, b);
    and a2(c2, s1, cin);
    or o1(cout, c1, c2);
endmodule

// Behavioral Full Adder
module full_adder_behavioral(
    input a, b, cin,
    output reg sum, cout
);
    always @(*) begin
        {cout, sum} = a + b + cin;
    end
endmodule

// Structural Full Adder (using half adders)
module full_adder_structural(
    input a, b, cin,
    output sum, cout
);
    wire s1, c1, c2;
    
    half_adder_gate ha1(.a(a), .b(b), .sum(s1), .carry(c1));
    half_adder_gate ha2(.a(s1), .b(cin), .sum(sum), .carry(c2));
    or o1(cout, c1, c2);
endmodule

// ====================================================================
// 5. 4-BIT RIPPLE CARRY ADDER
// ====================================================================

module ripple_carry_adder_4bit(
    input [3:0] a, b,
    input cin,
    output [3:0] sum,
    output cout
);
    wire c1, c2, c3;
    
    full_adder_gate fa0(.a(a[0]), .b(b[0]), .cin(cin), .sum(sum[0]), .cout(c1));
    full_adder_gate fa1(.a(a[1]), .b(b[1]), .cin(c1), .sum(sum[1]), .cout(c2));
    full_adder_gate fa2(.a(a[2]), .b(b[2]), .cin(c2), .sum(sum[2]), .cout(c3));
    full_adder_gate fa3(.a(a[3]), .b(b[3]), .cin(c3), .sum(sum[3]), .cout(cout));
endmodule

// ====================================================================
// 6. 4-BIT ADDER/SUBTRACTOR
// ====================================================================

module adder_subtractor_4bit(
    input [3:0] a, b,
    input mode,  // 0 for add, 1 for subtract
    output [3:0] result,
    output cout,
    output overflow
);
    wire [3:0] b_xor;
    
    // XOR b with mode for 2's complement subtraction
    assign b_xor = b ^ {4{mode}};
    
    // Use ripple carry adder
    ripple_carry_adder_4bit rca(
        .a(a), 
        .b(b_xor), 
        .cin(mode), 
        .sum(result), 
        .cout(cout)
    );
    
    // Overflow detection for signed numbers
    assign overflow = (a[3] == b_xor[3]) && (a[3] != result[3]);
endmodule

// ====================================================================
// 7. CODE CONVERTERS
// ====================================================================

// Binary to Gray Code Converter (4-bit)
module binary_to_gray_4bit(
    input [3:0] binary,
    output [3:0] gray
);
    assign gray[3] = binary[3];
    assign gray[2] = binary[3] ^ binary[2];
    assign gray[1] = binary[2] ^ binary[1];
    assign gray[0] = binary[1] ^ binary[0];
endmodule

// Gray to Binary Code Converter (4-bit)
module gray_to_binary_4bit(
    input [3:0] gray,
    output [3:0] binary
);
    assign binary[3] = gray[3];
    assign binary[2] = binary[3] ^ gray[2];
    assign binary[1] = binary[2] ^ gray[1];
    assign binary[0] = binary[1] ^ gray[0];
endmodule

// BCD to Excess-3 Code Converter
module bcd_to_excess3(
    input [3:0] bcd,
    output [3:0] excess3
);
    // Simply add 3 to BCD to get Excess-3
    assign excess3 = bcd + 4'd3;
endmodule

// Excess-3 to BCD Code Converter
module excess3_to_bcd(
    input [3:0] excess3,
    output [3:0] bcd
);
    // Simply subtract 3 from Excess-3 to get BCD
    assign bcd = excess3 - 4'd3;
endmodule

// BCD to Binary Converter (for single BCD digit)
module bcd_to_binary(
    input [3:0] bcd,
    output reg [3:0] binary
);
    always @(*) begin
        if(bcd <= 4'd9)
            binary = bcd;  // BCD and binary same for single digit
        else
            binary = 4'bxxxx;  // Invalid BCD
    end
endmodule

// ====================================================================
// 8. CARRY LOOK-AHEAD ADDER (4-bit) - Advanced
// ====================================================================

module carry_lookahead_adder_4bit(
    input [3:0] a, b,
    input cin,
    output [3:0] sum,
    output cout
);
    wire [3:0] g, p;  // Generate and Propagate
    wire c1, c2, c3;
    
    // Generate and Propagate signals
    assign g = a & b;      // Generate
    assign p = a ^ b;      // Propagate
    
    // Carry calculations
    assign c1 = g[0] | (p[0] & cin);
    assign c2 = g[1] | (p[1] & g[0]) | (p[1] & p[0] & cin);
    assign c3 = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & cin);
    assign cout = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]) | (p[3] & p[2] & p[1] & g[0]) | (p[3] & p[2] & p[1] & p[0] & cin);
    
    // Sum calculation
    assign sum[0] = p[0] ^ cin;
    assign sum[1] = p[1] ^ c1;
    assign sum[2] = p[2] ^ c2;
    assign sum[3] = p[3] ^ c3;
endmodule

// ====================================================================
// COMPREHENSIVE TESTBENCH
// ====================================================================

module testbench;
    // Test signals
    reg [3:0] a, b;
    reg cin, mode;
    wire [3:0] sum_rca, sum_cla, result_as, gray_out, binary_out, excess3_out, bcd_out;
    wire cout_rca, cout_cla, cout_as, overflow;
    wire sum_ha, carry_ha, sum_fa, cout_fa;
    wire f_orig1, f_simp1, f_orig2, f_simp2, xor_nand;
    wire and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out;
    
    // Instantiate modules for testing
    basic_gates bg(.a(a[0]), .b(b[0]), 
                   .and_out(and_out), .or_out(or_out), .not_out(not_out),
                   .nand_out(nand_out), .nor_out(nor_out), .xor_out(xor_out), .xnor_out(xnor_out));
    
    boolean_simplification_1 bs1(.a(a[0]), .b(b[0]), .f_original(f_orig1), .f_simplified(f_simp1));
    boolean_simplification_2 bs2(.a(a[0]), .b(b[0]), .f_original(f_orig2), .f_simplified(f_simp2));
    xor_using_nand xor_nand_inst(.a(a[0]), .b(b[0]), .y(xor_nand));
                   
    half_adder_behavioral ha(.a(a[0]), .b(b[0]), .sum(sum_ha), .carry(carry_ha));
    full_adder_behavioral fa(.a(a[0]), .b(b[0]), .cin(cin), .sum(sum_fa), .cout(cout_fa));
    
    ripple_carry_adder_4bit rca(.a(a), .b(b), .cin(cin), .sum(sum_rca), .cout(cout_rca));
    carry_lookahead_adder_4bit cla(.a(a), .b(b), .cin(cin), .sum(sum_cla), .cout(cout_cla));
    adder_subtractor_4bit ads(.a(a), .b(b), .mode(mode), .result(result_as), .cout(cout_as), .overflow(overflow));
    
    binary_to_gray_4bit btg(.binary(a), .gray(gray_out));
    gray_to_binary_4bit gtb(.gray(a), .binary(binary_out));
    bcd_to_excess3 bte(.bcd(a), .excess3(excess3_out));
    excess3_to_bcd etb(.excess3(a), .bcd(bcd_out));
    
    // Test procedure
    initial begin
        $display("=== VERILOG BASIC CIRCUITS TEST ===\n");
        
        // Initialize
        a = 4'b0000; b = 4'b0000; cin = 0; mode = 0;
        #10;
        
        $display("=== 1. BASIC GATES TEST ===");
        $display("A\tB\tAND\tOR\tNOT\tNAND\tNOR\tXOR\tXNOR");
        for(integer i = 0; i < 4; i = i + 1) begin
            {a[0], b[0]} = i;
            #10;
            $display("%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b", 
                     a[0], b[0], and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out);
        end
        
        $display("\n=== 2. BOOLEAN SIMPLIFICATION TEST ===");
        $display("A\tB\tF1_Orig\tF1_Simp\tF2_Orig\tF2_Simp\tXOR_NAND");
        for(integer i = 0; i < 4; i = i + 1) begin
            {a[0], b[0]} = i;
            #10;
            $display("%b\t%b\t%b\t%b\t%b\t%b\t%b", 
                     a[0], b[0], f_orig1, f_simp1, f_orig2, f_simp2, xor_nand);
        end
        
        $display("\n=== 3. HALF ADDER TEST ===");
        $display("A\tB\tSum\tCarry");
        for(integer i = 0; i < 4; i = i + 1) begin
            {a[0], b[0]} = i;
            #10;
            $display("%b\t%b\t%b\t%b", a[0], b[0], sum_ha, carry_ha);
        end
        
        $display("\n=== 4. FULL ADDER TEST ===");
        $display("A\tB\tCin\tSum\tCout");
        for(integer i = 0; i < 8; i = i + 1) begin
            {a[0], b[0], cin} = i;
            #10;
            $display("%b\t%b\t%b\t%b\t%b", a[0], b[0], cin, sum_fa, cout_fa);
        end
        
        $display("\n=== 5. 4-BIT ADDERS COMPARISON ===");
        $display("A\t\tB\t\tCin\tRCA_Sum\t\tRCA_Cout\tCLA_Sum\t\tCLA_Cout");
        cin = 0;
        a = 4'b0101; b = 4'b0011; #10;
        $display("%b(%d)\t%b(%d)\t%b\t%b(%d)\t%b\t\t%b(%d)\t%b", 
                 a, a, b, b, cin, sum_rca, sum_rca, cout_rca, sum_cla, sum_cla, cout_cla);
        
        a = 4'b1111; b = 4'b0001; #10;
        $display("%b(%d)\t%b(%d)\t%b\t%b(%d)\t%b\t\t%b(%d)\t%b", 
                 a, a, b, b, cin, sum_rca, sum_rca, cout_rca, sum_cla, sum_cla, cout_cla);
        
        a = 4'b1010; b = 4'b0110; cin = 1; #10;
        $display("%b(%d)\t%b(%d)\t%b\t%b(%d)\t%b\t\t%b(%d)\t%b", 
                 a, a, b, b, cin, sum_rca, sum_rca, cout_rca, sum_cla, sum_cla, cout_cla);
        
        $display("\n=== 6. 4-BIT ADDER/SUBTRACTOR TEST ===");
        $display("A\t\tB\t\tMode\tResult\t\tCout\tOverflow");
        
        // Addition tests
        mode = 0; cin = 0;
        a = 4'b0101; b = 4'b0011; #10;
        $display("%b(%d)\t%b(%d)\tADD\t%b(%d)\t%b\t%b", a, a, b, b, result_as, result_as, cout_as, overflow);
        
        a = 4'b0111; b = 4'b0001; #10;
        $display("%b(%d)\t%b(%d)\tADD\t%b(%d)\t%b\t%b", a, a, b, b, result_as, result_as, cout_as, overflow);
        
        // Subtraction tests
        mode = 1;
        a = 4'b0101; b = 4'b0011; #10;
        $display("%b(%d)\t%b(%d)\tSUB\t%b(%d)\t%b\t%b", a, a, b, b, result_as, result_as, cout_as, overflow);
        
        a = 4'b0011; b = 4'b0101; #10;
        $display("%b(%d)\t%b(%d)\tSUB\t%b(%d)\t%b\t%b", a, a, b, b, result_as, result_as, cout_as, overflow);
        
        $display("\n=== 7. CODE CONVERTERS TEST ===");
        
        // Binary to Gray
        $display("Binary to Gray Conversion:");
        $display("Binary\t\tDecimal\tGray");
        for(integer i = 0; i < 16; i = i + 1) begin
            a = i; #10;
            $display("%b\t%d\t%b", a, a, gray_out);
        end
        
        // Gray to Binary (test few values)
        $display("\nGray to Binary Conversion:");
        $display("Gray\t\tBinary\t\tDecimal");
        a = 4'b0000; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        a = 4'b0001; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        a = 4'b0011; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        a = 4'b0010; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        a = 4'b0110; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        a = 4'b0111; #10; $display("%b\t%b\t%d", a, binary_out, binary_out);
        
        // BCD to Excess-3
        $display("\nBCD to Excess-3 Conversion:");
        $display("BCD\t\tDecimal\tExcess-3");
        for(integer i = 0; i < 10; i = i + 1) begin
            a = i; #10;
            $display("%b\t%d\t%b", a, a, excess3_out);
        end
        
        // Excess-3 to BCD
        $display("\nExcess-3 to BCD Conversion:");
        $display("Excess-3\tBCD\t\tDecimal");
        for(integer i = 3; i < 13; i = i + 1) begin
            a = i; #10;
            $display("%b\t%b\t%d", a, bcd_out, bcd_out);
        end
        
        $display("\n=== TEST COMPLETED ===");
        $finish;
    end
    
    // Generate VCD file for waveform viewing
    initial begin
        $dumpfile("basic_circuits.vcd");
        $dumpvars(0, testbench);
    end
    
endmodule

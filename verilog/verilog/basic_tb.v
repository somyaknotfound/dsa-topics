// Test bench for the basic_gates and xor_using_nand modules

// Includes the design file containing the modules.
`include "basic.v" 

`timescale 1ns/1ps

module test_bench_gates();

    // Declare registers for inputs
    reg a, b;

    // Declare wires for outputs from the basic_gates module
    wire and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out;

    // Declare a wire for the output of the xor_using_nand module
    wire xor_nand_out;

    // Instantiate the Device Under Test (DUT) modules
    basic_gates UUT1 (
        .a(a),
        .b(b),
        .and_out(and_out),
        .or_out(or_out),
        .not_out(not_out),
        .nand_out(nand_out),
        .nor_out(nor_out),
        .xor_out(xor_out),
        .xnor_out(xnor_out)
    );

    xor_using_nand UUT2 (
        .a(a),
        .b(b),
        .y(xor_nand_out)
    );

    // Initial block for the test sequence
    initial begin
        // Setup for waveform viewing (VCD file)
        $dumpfile("gates_tb.vcd");
        $dumpvars(0, test_bench_gates);

        // Display header
        $display("---------------------------------------------------------------------------------------------------------------------------------------------------");
        $display("Time | a | b | and_out | or_out | not_out | nand_out | nor_out | xor_out | xnor_out | xor_nand_out");
        $display("---------------------------------------------------------------------------------------------------------------------------------------------------");

        // Use a monitor to print values whenever a variable changes
        $monitor("%0t | %b | %b |    %b    |   %b    |    %b    |    %b     |    %b    |    %b    |     %b    |      %b",
                  $time, a, b, and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out, xor_nand_out);

        // Test case 1: a=0, b=0
        a = 1'b0;
        b = 1'b0;
        #10;

        // Test case 2: a=0, b=1
        a = 1'b0;
        b = 1'b1;
        #10;

        // Test case 3: a=1, b=0
        a = 1'b1;
        b = 1'b0;
        #10;

        // Test case 4: a=1, b=1
        a = 1'b1;
        b = 1'b1;
        #10;

        // End the simulation
        $display("---------------------------------------------------------------------------------------------------------------------------------------------------");
        $finish;
    end

endmodule

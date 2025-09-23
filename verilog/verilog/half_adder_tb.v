// Test bench for the half_adder module
`timescale 1ns/1ps

module half_adder_tb();

    // Declare registers for inputs
    reg a, b;

    // Declare wires for outputs
    wire sum, carry;

    // Instantiate the Device Under Test (DUT)
    // The module name here must match the one in your halfadder.v file.
    half_adder UUT (
        .a(a),
        .b(b),
        .sum(sum),
        .carry(carry)
    );

    // Initial block for the test sequence
    initial begin
        // Setup for waveform viewing (VCD file)
        // You can view this file with a tool like GTKWave
        $dumpfile("half_adder_tb.vcd");
        $dumpvars(0, half_adder_tb);

        // Display header for the console output
        $display("------------------------------");
        $display("Time | a | b | sum | carry");
        $display("------------------------------");

        // Use a monitor to print values whenever a variable changes
        $monitor("%0t | %b | %b |  %b  |   %b", $time, a, b, sum, carry);

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
        $display("------------------------------");
        $finish;
    end

endmodule

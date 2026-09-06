//------------------------------------------------------------------------------
// Module: adder
//
// Solution:
//   Parameterized combinational adder for two WIDTH-bit packed vectors.
//
// How to create it:
//   1. Use packed vector ports: logic [WIDTH-1:0].
//      The original beginner bug was input a[7:0], which is an unpacked array
//      of one-bit elements, not an 8-bit arithmetic vector.
//   2. Use output, not out, in the port list.
//   3. End the module port list with ); before writing assignments.
//   4. Add one extra bit internally so carry_out is not lost.
//   5. Signed overflow for addition happens when inputs have the same sign but
//      the sum has the opposite sign.
//------------------------------------------------------------------------------
module adder #(
    parameter int WIDTH = 8
) (
    input  logic [WIDTH-1:0] a,
    input  logic [WIDTH-1:0] b,
    input  logic             carry_in,
    output logic [WIDTH-1:0] sum,
    output logic             carry_out,
    output logic             overflow
);

    logic [WIDTH:0] full_sum;

    always_comb begin
        full_sum  = {1'b0, a} + {1'b0, b} + {{WIDTH{1'b0}}, carry_in};
        sum       = full_sum[WIDTH-1:0];
        carry_out = full_sum[WIDTH];
        overflow  = (a[WIDTH-1] == b[WIDTH-1]) && (sum[WIDTH-1] != a[WIDTH-1]);
    end

endmodule

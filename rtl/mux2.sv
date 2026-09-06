//------------------------------------------------------------------------------
// Module: mux2
//
// Solution:
//   Parameterized 2:1 multiplexer.
//
// How to create it:
//   1. Make both data inputs the same packed width.
//   2. Use a one-bit select signal.
//   3. A continuous assign is enough because this is purely combinational.
//------------------------------------------------------------------------------
module mux2 #(
    parameter int WIDTH = 8
) (
    input  logic [WIDTH-1:0] in0,
    input  logic [WIDTH-1:0] in1,
    input  logic             sel,
    output logic [WIDTH-1:0] out
);

    assign out = sel ? in1 : in0;

endmodule

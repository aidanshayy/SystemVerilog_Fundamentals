//------------------------------------------------------------------------------
// Module: subtractor
//
// Solution:
//   Parameterized combinational subtractor for a - b.
//
// How to create it:
//   1. Keep the operands as packed vectors so arithmetic works naturally.
//   2. Compute one extra result bit to expose borrow_out.
//   3. For unsigned subtraction, borrow_out is true when a < b.
//   4. Signed overflow for subtraction happens when operands have different
//      signs and the result sign differs from a.
//------------------------------------------------------------------------------
module subtractor #(
    parameter int WIDTH = 8
) (
    input  logic [WIDTH-1:0] a,
    input  logic [WIDTH-1:0] b,
    output logic [WIDTH-1:0] difference,
    output logic             borrow_out,
    output logic             overflow
);

    always_comb begin
        difference = a - b;
        borrow_out = (a < b);
        overflow   = (a[WIDTH-1] != b[WIDTH-1]) &&
                     (difference[WIDTH-1] != a[WIDTH-1]);
    end

endmodule

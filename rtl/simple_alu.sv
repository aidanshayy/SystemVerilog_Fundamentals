//------------------------------------------------------------------------------
// Module: simple_alu
//
// Solution:
//   Small combinational ALU with add, subtract, bitwise logic, shifts, and set
//   less-than operations.
//
// How to create it:
//   1. Define operation encodings as localparams so the interface is readable.
//   2. Use always_comb and drive default outputs first.
//   3. Implement each operation in a case statement.
//   4. Produce common flags: zero, negative, carry, and signed overflow.
//------------------------------------------------------------------------------
module simple_alu #(
    parameter int WIDTH = 8
) (
    input  logic [WIDTH-1:0] a,
    input  logic [WIDTH-1:0] b,
    input  logic [2:0]       op,
    output logic [WIDTH-1:0] result,
    output logic             zero,
    output logic             negative,
    output logic             carry,
    output logic             overflow
);

    localparam logic [2:0] ALU_ADD = 3'd0;
    localparam logic [2:0] ALU_SUB = 3'd1;
    localparam logic [2:0] ALU_AND = 3'd2;
    localparam logic [2:0] ALU_OR  = 3'd3;
    localparam logic [2:0] ALU_XOR = 3'd4;
    localparam logic [2:0] ALU_SLL = 3'd5;
    localparam logic [2:0] ALU_SRL = 3'd6;
    localparam logic [2:0] ALU_SLT = 3'd7;

    logic [WIDTH:0] add_result;
    logic [WIDTH:0] sub_result;

    always_comb begin
        add_result = {1'b0, a} + {1'b0, b};
        sub_result = {1'b0, a} - {1'b0, b};
        result     = '0;
        carry      = 1'b0;
        overflow   = 1'b0;

        unique case (op)
            ALU_ADD: begin
                result   = add_result[WIDTH-1:0];
                carry    = add_result[WIDTH];
                overflow = (a[WIDTH-1] == b[WIDTH-1]) &&
                           (result[WIDTH-1] != a[WIDTH-1]);
            end
            ALU_SUB: begin
                result   = sub_result[WIDTH-1:0];
                carry    = !sub_result[WIDTH];
                overflow = (a[WIDTH-1] != b[WIDTH-1]) &&
                           (result[WIDTH-1] != a[WIDTH-1]);
            end
            ALU_AND: result = a & b;
            ALU_OR:  result = a | b;
            ALU_XOR: result = a ^ b;
            ALU_SLL: result = a << b[$clog2(WIDTH)-1:0];
            ALU_SRL: result = a >> b[$clog2(WIDTH)-1:0];
            ALU_SLT: result = {{(WIDTH-1){1'b0}}, ($signed(a) < $signed(b))};
            default: result = '0;
        endcase

        zero     = (result == '0);
        negative = result[WIDTH-1];
    end

endmodule

//------------------------------------------------------------------------------
// Module: counter
//
// Solution:
//   Parameterized up/down counter with synchronous clear and enable.
//
// How to create it:
//   1. Counters are sequential, so use always_ff.
//   2. Keep reset behavior explicit.
//   3. Give clear priority over enable so software/testbenches can force zero.
//   4. Let packed vector arithmetic wrap naturally at the width boundary.
//------------------------------------------------------------------------------
module counter #(
    parameter int WIDTH = 8
) (
    input  logic             clk,
    input  logic             rst_n,
    input  logic             clear,
    input  logic             enable,
    input  logic             up,
    output logic [WIDTH-1:0] count
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count <= '0;
        end else if (clear) begin
            count <= '0;
        end else if (enable) begin
            if (up) begin
                count <= count + {{(WIDTH-1){1'b0}}, 1'b1};
            end else begin
                count <= count - {{(WIDTH-1){1'b0}}, 1'b1};
            end
        end
    end

endmodule

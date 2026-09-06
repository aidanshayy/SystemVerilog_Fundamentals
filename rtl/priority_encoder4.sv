//------------------------------------------------------------------------------
// Module: priority_encoder4
//
// Solution:
//   4-bit priority encoder where bit 3 has highest priority.
//
// How to create it:
//   1. Use always_comb because outputs depend only on current inputs.
//   2. Drive all outputs on every path to avoid inferred latches.
//   3. Check input bits from highest priority to lowest priority.
//   4. valid tells downstream logic whether code contains meaningful data.
//------------------------------------------------------------------------------
module priority_encoder4 (
    input  logic [3:0] in,
    output logic [1:0] code,
    output logic       valid
);

    always_comb begin
        code  = 2'b00;
        valid = 1'b1;

        unique casez (in)
            4'b1???: code = 2'd3;
            4'b01??: code = 2'd2;
            4'b001?: code = 2'd1;
            4'b0001: code = 2'd0;
            default: valid = 1'b0;
        endcase
    end

endmodule

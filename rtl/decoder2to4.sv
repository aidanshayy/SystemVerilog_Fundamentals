//------------------------------------------------------------------------------
// Module: decoder2to4
//
// Solution:
//   2-bit to 4-bit one-hot decoder with enable.
//
// How to create it:
//   1. Start the output at zero in always_comb so disabled means no bits set.
//   2. When enable is asserted, set exactly one bit indexed by the input.
//   3. This pattern scales to larger decoders when the output width is 2**N.
//------------------------------------------------------------------------------
module decoder2to4 (
    input  logic [1:0] in,
    input  logic       enable,
    output logic [3:0] out
);

    always_comb begin
        out = 4'b0000;
        if (enable) begin
            out[in] = 1'b1;
        end
    end

endmodule



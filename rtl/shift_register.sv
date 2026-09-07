//------------------------------------------------------------------------------
// Module: shift_register
//
// Solution:
//   Parameterized shift register with parallel load and serial input/output.
//
// How to create it:
//   1. Use a register vector to store the current shifted value.
//   2. Reset first, then load, then shift when enabled.
//   3. Concatenation is the cleanest way to drop one bit and insert another.
//   4. serial_out is just the bit that would leave the register next.
//------------------------------------------------------------------------------

module shift_register #(
       parameter int WIDTH = 8 
       ) (       
	input logic clk,
	input logic rst_n, 
	input logic load,
	input logic shift_en, 
	input logic serial_in, 
	input logic [WIDTH-1:0]parallel_in, 
	output logic [WIDTH-1:0]parallel_out, 
	output logic serial_out
	);	

	always_ff @(posedge clk or negedge rst_n) begin 
		if (!rst_n) begin 
			parallel_out <= '0; 
		end else if (load) begin 
			parallel_out <= parallel_in; 
		end else if (shift_en) begin 
			parallel_out <= {parallel_out[WIDTH-2:0], serial_in}; 
	end
end

	assign serial_out = parallel_out[WIDTH-1]; 


	endmodule

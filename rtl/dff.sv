//------------------------------------------------------------------------------
// Module: dff
//
// Solution:
//   Parameterized D flip-flop with asynchronous active-low reset and clock
//   enable.
//
// How to create it:
//   1. Sequential storage belongs in always_ff.
//   2. Put clk and async reset in the event control.
//   3. Reset gets priority, then enable, then hold the previous value.
//   4. Use nonblocking assignments (<=) for sequential logic.
//------------------------------------------------------------------------------


module dff #( 
	parameter int WIDTH = 8, 
	parameter logic [WIDTH-1:0]RESET_VALUE = '0
	)(
		input logic clk, 
		input logic rst_n, 
		input logic en, 
		input logic [WIDTH-1:0] d,
		output logic [WIDTH-1:0] q
		);

		always_ff @(posedge clk or negedge rst_n) begin 
			if(!rst_n) begin 
				q<= RESET_VALUE; 
			end else if (en) begin 
				q <= d; 
			end
		end
		endmodule


		


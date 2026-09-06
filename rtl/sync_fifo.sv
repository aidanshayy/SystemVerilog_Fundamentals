//------------------------------------------------------------------------------
// Module: sync_fifo
//
// Solution:
//   Simple synchronous FIFO with one clock, valid write/read controls, full,
//   empty, and count.
//
// How to create it:
//   1. Store entries in an unpacked memory: logic [WIDTH-1:0] mem [DEPTH].
//   2. Track write and read pointers separately.
//   3. Track occupancy with count; full means count == DEPTH, empty means zero.
//   4. Only accept writes when not full and only accept reads when not empty.
//   5. Simultaneous read and write keeps count unchanged when both are accepted.
//------------------------------------------------------------------------------
module sync_fifo #(
    parameter int WIDTH = 8,
    parameter int DEPTH = 4,
    localparam int PTR_WIDTH = (DEPTH <= 2) ? 1 : $clog2(DEPTH),
    localparam int COUNT_WIDTH = $clog2(DEPTH + 1)
) (
    input  logic                   clk,
    input  logic                   rst_n,
    input  logic                   wr_en,
    input  logic                   rd_en,
    input  logic [WIDTH-1:0]       wr_data,
    output logic [WIDTH-1:0]       rd_data,
    output logic                   full,
    output logic                   empty,
    output logic [COUNT_WIDTH-1:0] count
);

    logic [WIDTH-1:0]     mem [DEPTH];
    logic [PTR_WIDTH-1:0] wr_ptr;
    logic [PTR_WIDTH-1:0] rd_ptr;
    logic                 do_write;
    logic                 do_read;

    assign full     = (count == COUNT_WIDTH'(DEPTH));
    assign empty    = (count == '0);
    assign do_write = wr_en && !full;
    assign do_read  = rd_en && !empty;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr  <= '0;
            rd_ptr  <= '0;
            rd_data <= '0;
            count   <= '0;
        end else begin
            if (do_write) begin
                mem[wr_ptr] <= wr_data;
                if (wr_ptr == PTR_WIDTH'(DEPTH - 1)) begin
                    wr_ptr <= '0;
                end else begin
                    wr_ptr <= wr_ptr + {{(PTR_WIDTH-1){1'b0}}, 1'b1};
                end
            end

            if (do_read) begin
                rd_data <= mem[rd_ptr];
                if (rd_ptr == PTR_WIDTH'(DEPTH - 1)) begin
                    rd_ptr <= '0;
                end else begin
                    rd_ptr <= rd_ptr + {{(PTR_WIDTH-1){1'b0}}, 1'b1};
                end
            end

            unique case ({do_write, do_read})
                2'b10: count <= count + {{(COUNT_WIDTH-1){1'b0}}, 1'b1};
                2'b01: count <= count - {{(COUNT_WIDTH-1){1'b0}}, 1'b1};
                default: count <= count;
            endcase
        end
    end

endmodule

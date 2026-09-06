//------------------------------------------------------------------------------
// Smoke test for the study RTL modules.
//
// This is intentionally simple: it is not a full verification environment yet.
// It gives you a fast Verilator check that the modules compile and basic
// behavior is sane before you start writing deeper directed/random/formal tests.
//------------------------------------------------------------------------------
module smoke_tb;

    localparam int WIDTH = 8;

    logic clk;
    logic rst_n;

    logic [WIDTH-1:0] add_a;
    logic [WIDTH-1:0] add_b;
    logic             carry_in;
    logic [WIDTH-1:0] sum;
    logic             carry_out;
    logic             add_overflow;

    logic [WIDTH-1:0] diff;
    logic             borrow_out;
    logic             sub_overflow;

    logic [WIDTH-1:0] mux_out;
    logic [3:0]       dec_out;
    logic [1:0]       enc_code;
    logic             enc_valid;
    logic [WIDTH-1:0] q;
    logic [WIDTH-1:0] count;
    logic [WIDTH-1:0] shift_out;
    logic             serial_out;
    logic [WIDTH-1:0] fifo_rd_data;
    logic             fifo_full;
    logic             fifo_empty;
    logic [2:0]       fifo_count;
    logic [WIDTH-1:0] alu_result;
    logic             alu_zero;
    logic             alu_negative;
    logic             alu_carry;
    logic             alu_overflow;

    logic             dff_en;
    logic [WIDTH-1:0] dff_d;
    logic             counter_clear;
    logic             counter_enable;
    logic             counter_up;
    logic             shift_load;
    logic             shift_en;
    logic             serial_in;
    logic [WIDTH-1:0] shift_parallel_in;
    logic             fifo_wr_en;
    logic             fifo_rd_en;
    logic [WIDTH-1:0] fifo_wr_data;
    logic [2:0]       alu_op;

    adder #(.WIDTH(WIDTH)) u_adder (
        .a(add_a),
        .b(add_b),
        .carry_in(carry_in),
        .sum(sum),
        .carry_out(carry_out),
        .overflow(add_overflow)
    );

    subtractor #(.WIDTH(WIDTH)) u_subtractor (
        .a(add_a),
        .b(add_b),
        .difference(diff),
        .borrow_out(borrow_out),
        .overflow(sub_overflow)
    );

    mux2 #(.WIDTH(WIDTH)) u_mux2 (
        .in0(add_a),
        .in1(add_b),
        .sel(carry_in),
        .out(mux_out)
    );

    decoder2to4 u_decoder (
        .in(add_a[1:0]),
        .enable(carry_in),
        .out(dec_out)
    );

    priority_encoder4 u_priority_encoder (
        .in(add_b[3:0]),
        .code(enc_code),
        .valid(enc_valid)
    );

    dff #(.WIDTH(WIDTH)) u_dff (
        .clk(clk),
        .rst_n(rst_n),
        .en(dff_en),
        .d(dff_d),
        .q(q)
    );

    counter #(.WIDTH(WIDTH)) u_counter (
        .clk(clk),
        .rst_n(rst_n),
        .clear(counter_clear),
        .enable(counter_enable),
        .up(counter_up),
        .count(count)
    );

    shift_register #(.WIDTH(WIDTH)) u_shift_register (
        .clk(clk),
        .rst_n(rst_n),
        .load(shift_load),
        .shift_en(shift_en),
        .serial_in(serial_in),
        .parallel_in(shift_parallel_in),
        .parallel_out(shift_out),
        .serial_out(serial_out)
    );

    sync_fifo #(.WIDTH(WIDTH), .DEPTH(4)) u_sync_fifo (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(fifo_wr_en),
        .rd_en(fifo_rd_en),
        .wr_data(fifo_wr_data),
        .rd_data(fifo_rd_data),
        .full(fifo_full),
        .empty(fifo_empty),
        .count(fifo_count)
    );

    simple_alu #(.WIDTH(WIDTH)) u_simple_alu (
        .a(add_a),
        .b(add_b),
        .op(alu_op),
        .result(alu_result),
        .zero(alu_zero),
        .negative(alu_negative),
        .carry(alu_carry),
        .overflow(alu_overflow)
    );

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n             = 1'b0;
        add_a             = 8'd0;
        add_b             = 8'd0;
        carry_in          = 1'b0;
        dff_en            = 1'b0;
        dff_d             = 8'd0;
        counter_clear     = 1'b0;
        counter_enable    = 1'b0;
        counter_up        = 1'b1;
        shift_load        = 1'b0;
        shift_en          = 1'b0;
        serial_in         = 1'b0;
        shift_parallel_in = 8'd0;
        fifo_wr_en        = 1'b0;
        fifo_rd_en        = 1'b0;
        fifo_wr_data      = 8'd0;
        alu_op            = 3'd0;

        repeat (2) @(posedge clk);
        rst_n = 1'b1;

        add_a    = 8'd10;
        add_b    = 8'd22;
        carry_in = 1'b1;
        #1;
        assert(sum == 8'd33);
        assert(carry_out == 1'b0);
        assert(add_overflow == 1'b0);
        assert(diff == 8'd244);
        assert(borrow_out == 1'b1);
        assert(sub_overflow == 1'b0);
        assert(mux_out == 8'd22);
        assert(dec_out == 4'b0100);
        assert(enc_valid == 1'b1);
        assert(enc_code == 2'd2);

        alu_op = 3'd0;
        #1;
        assert(alu_result == 8'd32);
        assert(alu_zero == 1'b0);
        assert(alu_negative == 1'b0);
        assert(alu_carry == 1'b0);
        assert(alu_overflow == 1'b0);
        alu_op = 3'd2;
        #1;
        assert(alu_result == (8'd10 & 8'd22));

        dff_en = 1'b1;
        dff_d  = 8'hA5;
        @(posedge clk);
        #1;
        assert(q == 8'hA5);

        counter_enable = 1'b1;
        counter_up     = 1'b1;
        @(posedge clk);
        @(posedge clk);
        #1;
        assert(count == 8'd2);

        shift_parallel_in = 8'b1010_0101;
        shift_load        = 1'b1;
        @(posedge clk);
        shift_load = 1'b0;
        shift_en   = 1'b1;
        serial_in  = 1'b1;
        @(posedge clk);
        #1;
        assert(serial_out == 1'b0);
        assert(shift_out == 8'b0100_1011);

        fifo_wr_data = 8'h11;
        fifo_wr_en   = 1'b1;
        @(posedge clk);
        fifo_wr_data = 8'h22;
        @(posedge clk);
        fifo_wr_en = 1'b0;
        #1;
        assert(fifo_count == 3'd2);
        assert(fifo_empty == 1'b0);
        assert(fifo_full == 1'b0);

        fifo_rd_en = 1'b1;
        @(posedge clk);
        #1;
        assert(fifo_rd_data == 8'h11);
        @(posedge clk);
        #1;
        assert(fifo_rd_data == 8'h22);
        fifo_rd_en = 1'b0;

        $display("SMOKE TEST PASSED");
        $finish;
    end

endmodule

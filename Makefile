VERILATOR ?= verilator

RTL := adder.sv \
       rtl/subtractor.sv \
       rtl/mux2.sv \
       rtl/decoder2to4.sv \
       rtl/priority_encoder4.sv \
       rtl/dff.sv \
       rtl/counter.sv \
       rtl/shift_register.sv \
       rtl/sync_fifo.sv \
       rtl/simple_alu.sv

TB := tb/smoke_tb.sv
TOP := smoke_tb

.PHONY: all lint sim clean

all: lint sim

lint:
	$(VERILATOR) --lint-only -Wall --timing --top-module $(TOP) $(RTL) $(TB)

sim:
	$(VERILATOR) --binary --timing --top-module $(TOP) $(RTL) $(TB)
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir *.vcd *.fst *.log

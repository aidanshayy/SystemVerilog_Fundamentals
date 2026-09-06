# SystemVerilog RTL Fundamentals

This repository is a practice space for SystemVerilog fundamentals used in
digital design, functional verification, and formal verification interviews.
The current focus is small, readable RTL blocks that teach syntax, datatypes,
combinational logic, sequential logic, and basic microarchitecture.

## Verilator

You already installed Verilator. Confirm it with:

```bash
verilator --version
```

Run a syntax/lint check:

```bash
make lint
```

Build and run the smoke test:

```bash
make sim
```

Run both:

```bash
make
```

## Module Map

| File | Concept |
| --- | --- |
| `adder.sv` | Packed vectors, combinational arithmetic, carry, signed overflow |
| `rtl/subtractor.sv` | Borrow, wraparound arithmetic, subtraction overflow |
| `rtl/mux2.sv` | Ternary operator and simple combinational selection |
| `rtl/decoder2to4.sv` | One-hot decode, enable gating, vector indexing |
| `rtl/priority_encoder4.sv` | Priority logic, `casez`, `valid` output |
| `rtl/dff.sv` | `always_ff`, nonblocking assignment, async reset, enable |
| `rtl/counter.sv` | Sequential arithmetic, synchronous clear, up/down control |
| `rtl/shift_register.sv` | Concatenation, parallel load, serial shift |
| `rtl/sync_fifo.sv` | Memory arrays, read/write pointers, occupancy count |
| `rtl/simple_alu.sv` | `always_comb`, operation decode, flags |

Each RTL file starts with a comment block that explains the solution and the
construction steps. Read those before reading the implementation.


## Study Order

1. `adder.sv`: packed vectors, parameters, carry, overflow.
2. `rtl/mux2.sv`, `rtl/decoder2to4.sv`, `rtl/priority_encoder4.sv`:
   pure combinational logic.
3. `rtl/dff.sv`, `rtl/counter.sv`, `rtl/shift_register.sv`:
   clocked logic, resets, and nonblocking assignments.
4. `rtl/sync_fifo.sv`: pointers, memory, full/empty, and count.
5. `rtl/simple_alu.sv`: operation decode and flags.
6. `tb/smoke_tb.sv`: basic simulation structure.

## Interview Notes

- Use `logic` for most RTL signals unless you specifically need a net type.
- Use `always_comb` for combinational procedural logic.
- Use `always_ff @(posedge clk ...)` for sequential logic.
- Use blocking assignments (`=`) in combinational procedural logic.
- Use nonblocking assignments (`<=`) in sequential logic.
- Packed vectors look like `logic [7:0] data` and behave like numbers.
- Unpacked arrays look like `logic data [8]` and behave like memories/arrays.
- Avoid inferred latches by assigning every combinational output on every path.
- Know the difference between unsigned carry/borrow and signed overflow.
- FIFOs usually need storage, a write pointer, a read pointer, and occupancy or
  pointer comparison logic.

## Next Practice Steps

Good follow-up exercises:

- Add self-checking directed testbenches for every module.
- Add constrained-random tests for the adder, subtractor, ALU, and FIFO.
- Add SystemVerilog assertions for FIFO safety: no read when empty, no write
  when full, count never above depth.
- Write a formal harness for the FIFO and prove ordering.
- Extend the ALU with comparisons, arithmetic shift right, and flag assertions.

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsmoke_tb.h for the primary calling header

#ifndef VERILATED_VSMOKE_TB___024ROOT_H_
#define VERILATED_VSMOKE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsmoke_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsmoke_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ smoke_tb__DOT__clk;
    CData/*0:0*/ __Vtrigprevexpr___TOP__smoke_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h255290b6__0;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsmoke_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsmoke_tb___024root(Vsmoke_tb__Syms* symsp, const char* v__name);
    ~Vsmoke_tb___024root();
    VL_UNCOPYABLE(Vsmoke_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

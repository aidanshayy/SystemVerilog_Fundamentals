// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsmoke_tb.h for the primary calling header

#include "Vsmoke_tb__pch.h"
#include "Vsmoke_tb__Syms.h"
#include "Vsmoke_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsmoke_tb___024root___dump_triggers__act(Vsmoke_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsmoke_tb___024root___eval_triggers__act(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->smoke_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__smoke_tb__DOT__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__smoke_tb__DOT__clk__0 
        = vlSelf->smoke_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsmoke_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

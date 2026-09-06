// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsmoke_tb.h for the primary calling header

#include "Vsmoke_tb__pch.h"
#include "Vsmoke_tb___024root.h"

VL_ATTR_COLD void Vsmoke_tb___024root___eval_static(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsmoke_tb___024root___eval_final(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vsmoke_tb___024root___eval_settle(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsmoke_tb___024root___dump_triggers__act(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge smoke_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsmoke_tb___024root___dump_triggers__nba(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge smoke_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsmoke_tb___024root___ctor_var_reset(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->smoke_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__smoke_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
}

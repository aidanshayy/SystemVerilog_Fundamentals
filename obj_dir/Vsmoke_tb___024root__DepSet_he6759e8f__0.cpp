// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsmoke_tb.h for the primary calling header

#include "Vsmoke_tb__pch.h"
#include "Vsmoke_tb___024root.h"

VlCoroutine Vsmoke_tb___024root___eval_initial__TOP__Vtiming__0(Vsmoke_tb___024root* vlSelf);
VlCoroutine Vsmoke_tb___024root___eval_initial__TOP__Vtiming__1(Vsmoke_tb___024root* vlSelf);

void Vsmoke_tb___024root___eval_initial(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_initial\n"); );
    // Body
    Vsmoke_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsmoke_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__smoke_tb__DOT__clk__0 
        = vlSelf->smoke_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vsmoke_tb___024root___eval_initial__TOP__Vtiming__0(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->smoke_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "tb/smoke_tb.sv", 
                                           147);
        vlSelf->smoke_tb__DOT__clk = (1U & (~ (IData)(vlSelf->smoke_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vsmoke_tb___024root___eval_initial__TOP__Vtiming__1(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       169);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       169);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       175);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       188);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       195);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       200);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       201);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       206);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       207);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       208);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       213);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       217);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       218);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       226);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       228);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       234);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       235);
    co_await vlSelf->__VtrigSched_h255290b6__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge smoke_tb.clk)", 
                                                       "tb/smoke_tb.sv", 
                                                       237);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb/smoke_tb.sv", 
                                       238);
    VL_WRITEF("SMOKE TEST PASSED\n");
    VL_FINISH_MT("tb/smoke_tb.sv", 243, "");
}

void Vsmoke_tb___024root___eval_act(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_act\n"); );
}

void Vsmoke_tb___024root___eval_nba(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_nba\n"); );
}

void Vsmoke_tb___024root___timing_resume(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h255290b6__0.resume("@(posedge smoke_tb.clk)");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vsmoke_tb___024root___timing_commit(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h255290b6__0.commit("@(posedge smoke_tb.clk)");
    }
}

void Vsmoke_tb___024root___eval_triggers__act(Vsmoke_tb___024root* vlSelf);

bool Vsmoke_tb___024root___eval_phase__act(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsmoke_tb___024root___eval_triggers__act(vlSelf);
    Vsmoke_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsmoke_tb___024root___timing_resume(vlSelf);
        Vsmoke_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsmoke_tb___024root___eval_phase__nba(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsmoke_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsmoke_tb___024root___dump_triggers__nba(Vsmoke_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsmoke_tb___024root___dump_triggers__act(Vsmoke_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsmoke_tb___024root___eval(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsmoke_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/smoke_tb.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsmoke_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/smoke_tb.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsmoke_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsmoke_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsmoke_tb___024root___eval_debug_assertions(Vsmoke_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsmoke_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsmoke_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

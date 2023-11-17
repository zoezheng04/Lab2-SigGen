// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsinegen.h"
#include "Vsinegen__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsinegen::Vsinegen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsinegen__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , incr{vlSymsp->TOP.incr}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsinegen::Vsinegen(const char* _vcname__)
    : Vsinegen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsinegen::~Vsinegen() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG
void Vsinegen___024root___eval_static(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval_initial(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval_settle(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval(Vsinegen___024root* vlSelf);

void Vsinegen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsinegen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsinegen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsinegen___024root___eval_static(&(vlSymsp->TOP));
        Vsinegen___024root___eval_initial(&(vlSymsp->TOP));
        Vsinegen___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsinegen___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsinegen::eventsPending() { return false; }

uint64_t Vsinegen::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsinegen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsinegen___024root___eval_final(Vsinegen___024root* vlSelf);

VL_ATTR_COLD void Vsinegen::final() {
    Vsinegen___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsinegen::hierName() const { return vlSymsp->name(); }
const char* Vsinegen::modelName() const { return "Vsinegen"; }
unsigned Vsinegen::threads() const { return 1; }
void Vsinegen::prepareClone() const { contextp()->prepareClone(); }
void Vsinegen::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsinegen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsinegen___024root__trace_init_top(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen___024root*>(voidSelf);
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsinegen___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsinegen___024root__trace_register(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsinegen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsinegen::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsinegen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

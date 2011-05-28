/**
 * @file xmulticore\private\x_barrier_x86_win32.h
 * X86 (32 and 64 bit) specific barriers.
 * @warning do not include directly. @see xmulticore\x_barrier.h
 */

// Memory barriers
// This version requires SSE capable CPU.
force_inline void barrier::comp()		{ __asm { }; }

force_inline void barrier::memr()		{ __asm { __asm lfence }; }
force_inline void barrier::memw()		{ __asm { __asm sfence }; }
force_inline void barrier::memrw()		{ __asm { __asm mfence }; }

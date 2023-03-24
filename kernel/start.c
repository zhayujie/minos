#include "types.h"
#include "riscv.h"
#include "trap.h"
#include "defs.h"

// app start address
extern uint64 _app_0_start;

extern void userret(uint64 trap_context);
extern void usertrap(uint64 trap_context);

// kernel stack
char kstack[4096];

// user stack
char ustack[4096];


void start(void)
{
  #ifdef D1_BOARD
    printf("[kernel] Hello Minos in D1-board!\r\n");
  #else
    printf("[kernel] Hello Minos!\r\n");
  #endif

  w_medeleg(0xffff);
  w_mideleg(0xffff);
  
  unsigned long x = r_sstatus();
  x &= ~SSTATUS_SPP;  // clear SPP to 0 for user mode
  x |= SSTATUS_SPIE;  // enable interrupts in user mode
  w_sstatus(x);
  
  w_stvec((uint64) usertrap);
  w_sepc((uint64) &_app_0_start);

  printf("[kernel] start first application\r\n");

  // sp
  get_trap_context()->sp = (uint64) &ustack + 4096;
  usertrapret();
}

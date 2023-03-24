#include "types.h"
#include "riscv.h"
#include "trap.h"
#include "defs.h"

extern void userret(uint64 trap_context);
extern char kstack[4096];

// trap context
struct trap_context trap_context;

void trap_handle(void) {
  // uint64 cause = r_scause();

  syscall();

  w_sepc(r_sepc() + 4); 
  usertrapret();
}

void usertrapret(void) {
  // initial kernel stack top
  trap_context.kernel_sp = (uint64) kstack + 4096;

  // switch to trapentry.S
  userret((uint64) get_trap_context());
}

struct trap_context * get_trap_context(void) {
  return &trap_context;
}

#include "types.h"
#include "trap.h"
#include "defs.h"
#include "syscall.h"

uint64 sys_write(void) 
{
  uint64 c = (uint64) get_trap_context()->a0;
  putc(c);
  return 0;
}

void sched(void) 
{
  while (1) { 
  }
}

uint64 sys_exit(void) 
{
  printf("[kernel] application exit\r\n");
  sched();
  return 0;
}

static uint64 (*syscalls[])(void) = {
  [SYS_write] = sys_write,
  [SYS_exit]  = sys_exit,
};

void syscall(void) 
{
  int num = get_trap_context()->a7;
  syscalls[num]();
}

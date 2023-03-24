#include "types.h"

#define THR 0
// #define LSR 0x7c              // line status register
#define LSR 5              // line status register
#define LSR_RX_READY (1<<0)   // input is waiting to be read from RHR
// #define LSR_TX_IDLE 0x02      // THR can accept another character to send
#define LSR_TX_IDLE (1<<5)     // THR can accept another character to send

#define UART0 0x10000000

#define Reg(reg) ((volatile unsigned char *)(UART0 + reg))
#define ReadReg(reg) (*(Reg(reg)))
#define WriteReg(reg, v) (*(Reg(reg)) = (v))

void putc(char c) {
  // asm("li t1, 0x10000000");
  // asm("li t1, 0x02500000");
  // asm("mv t0, %0" : : "r" (c));
  // asm("sb t0, 0(t1)");
  // volatile unsigned char * p_lsr = (volatile unsigned char *) (UART0 + LSR);
  // volatile unsigned char * uart0 = (volatile unsigned char *) (UART0);

  // while ((*p_lsr & LSR_TX_IDLE) == 0) {
  //   ;
  // }
  // *uart0 = c;
  while((ReadReg(LSR) & LSR_TX_IDLE) == 0)
    ;
  WriteReg(THR, c);
}

void printf(char * st) {
  int i;

  for (i = 0; st[i]; i++) 
  {
    putc(st[i]);
  }
  return;
}

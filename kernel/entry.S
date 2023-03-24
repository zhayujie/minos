.section .text

  la sp, kstack
  li a0, 4096
  add sp, sp, a0
  call start

.section .data
.global _app_0_start
_app_0_start:
  .incbin "user/app.bin"

struct trap_context {
  /*   0 */ uint64 x0;
  /*   8 */ uint64 ra;
  /*  16 */ uint64 sp;
  /*  24 */ uint64 gp;
  /*  32 */ uint64 tp;
  /*  40 */ uint64 t0;
  /*  48 */ uint64 t1;
  /*  56 */ uint64 t2;
  /*  64 */ uint64 s0;
  /*  72 */ uint64 s1;
  /*  80 */ uint64 a0;
  /*  88 */ uint64 a1;
  /*  96 */ uint64 a2;
  /* 104 */ uint64 a3;
  /* 112 */ uint64 a4;
  /* 120 */ uint64 a5;
  /* 128 */ uint64 a6;
  /* 136 */ uint64 a7;
  /* 144 */ uint64 s2;
  /* 152 */ uint64 s3;
  /* 160 */ uint64 s4;
  /* 168 */ uint64 s5;
  /* 176 */ uint64 s6;
  /* 184 */ uint64 s7;
  /* 192 */ uint64 s8;
  /* 200 */ uint64 s9;
  /* 208 */ uint64 s10;
  /* 216 */ uint64 s11;
  /* 224 */ uint64 t3;
  /* 232 */ uint64 t4;
  /* 240 */ uint64 t5;
  /* 248 */ uint64 t6;

  /* 256 */ uint64 kernel_sp;
};

struct trap_context * get_trap_context(void);
void trap_handle(void);
void usertrapret(void);
void syscall(void);

// util
void printf(char * st);
void putc(uint64 c);

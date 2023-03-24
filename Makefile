K=kernel
U=user

CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy

CFLAGS = -mcmodel=medany -g -march=rv64g -nostdlib -Wall -Werror
CFLAGS += -ffreestanding -fno-common -nostdlib -mno-relax
CFLAGS += -I. -MD

ASFLAGS = -g -I.

-include kernel/*.d user/*.d

# Kernel build
K_OBJS = \
  $K/entry.o \
  $K/start.o \
	$K/trapentry.o \
	$K/trap.o \
	$K/syscall.o \
	$K/util.o

$K/entry.o: $U/app.bin
	$(CC) $(CFLAGS) -c $K/entry.S -o $K/entry.o

kernel: $(K_OBJS)
	$(LD) $(K_OBJS) -T $K/kernel.ld -o $K/kernel

# User build
U_OBJS = \
  $U/app.o \
	$U/usys.o \
	$U/util.o

user: $(U_OBJS)
	$(LD) $(U_OBJS) -T $U/user.ld -o $U/app
	$(OBJCOPY) -O binary $U/app $U/app.bin

# run on QEMU
qemu: user kernel
	qemu-system-riscv64 -machine virt -smp 1 -m 128M -bios none -nographic -kernel kernel/kernel

qemu-gdb: user kernel
	qemu-system-riscv64 -machine virt -smp 1 -m 128M -bios none -nographic -kernel kernel/kernel -s -S
    
clean:
	rm kernel/*.o user/*.o kernel/kernel user/app user/app.bin kernel/*.d user/*.d

# run on D1 board
kernel-d1: CFLAGS += -D D1_BOARD
kernel-d1: $(K_OBJS)
	$(LD) $(K_OBJS) -T $K/kernel-d1.ld -o $K/kernel

d1-board: user kernel-d1
	riscv64-unknown-elf-objcopy -O binary kernel/kernel kernel/kernel.bin

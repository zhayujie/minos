# 编译和链接
entry:
	riscv64-unknown-elf-gcc -c kernel/entry.S -o kernel/kernel.o
	riscv64-unknown-elf-ld kernel/kernel.o -T kernel/kernel.ld -o kernel/kernel

# 使用qemu运行kernel
qemu: entry
	qemu-system-riscv64 -machine virt -smp 1 -m 128M -bios none -nographic -kernel kernel/kernel

# 使用qemu调试kernel
qemu-gdb: entry
	qemu-system-riscv64 -machine virt -smp 1 -m 128M -bios none -nographic -kernel kernel/kernel -s -S
    
# 删除编译产物
clean:
	rm kernel/kernel.o kernel/kernel

# 生成能运行于D1-H开发板二进制文件
d1-board: entry
	riscv64-unknown-elf-objcopy -O binary kernel/kernel kernel/kernel.bin

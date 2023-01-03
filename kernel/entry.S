.section .text

li t1, 0x10000000    # 将UART起始地址加载到t1
li t0, 'H'           # 将'H' 加载到t0
sb t0, 0(t1)         # 向UART起始地址写入t0中的值，即字符 'H'

# 输出剩余字符
li t0, 'e' 
sb t0, 0(t1)
li t0, 'l' 
sb t0, 0(t1)
li t0, 'l' 
sb t0, 0(t1)
li t0, 'o' 
sb t0, 0(t1)
li t0, ' ' 
sb t0, 0(t1)
li t0, 'M' 
sb t0, 0(t1)
li t0, 'i' 
sb t0, 0(t1)
li t0, 'n' 
sb t0, 0(t1)
li t0, 'O' 
sb t0, 0(t1)
li t0, 'S' 
sb t0, 0(t1)
li t0, '!' 
sb t0, 0(t1)

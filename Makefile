OBJECTS = start.o main.o
LDFLAGS=-nostartfiles -nostdlib -nostdlib --build-id=none --gc-sections
CFLAGS=-fno-builtin -nostartfiles -std=c11

# デフォルト動作
default :
	make kernel.bin

# ファイル生成規則

kernel.bin : kernel.elf Makefile
	aarch64-none-elf-objcopy -O binary kernel.elf kernel.bin

kernel.elf : ldscript.ld $(OBJECTS) Makefile
	aarch64-none-elf-ld $(LDFLAGS) -T ldscript.ld $(OBJECTS) -o kernel.elf

.c.o :
	aarch64-none-elf-gcc $(CFLAGS) -c $<
.S.o :
	aarch64-none-elf-gcc $(CFLAGS) -c $<

# コマンド
run :
	make kernel.elf
	qemu-system-aarch64 -M raspi3  -nographic -kernel kernel.elf

clean:
	- rm kernel.elf
	- rm kernel.bin
	- rm $(OBJECTS)


; Prepare header constants
MAGIC		equ 0x1BADB002
; FLAGS		equ 1 | 1 << 1
FLAGS equ 0 | 0b11
CHECKSUM	equ - (MAGIC + FLAGS)

; Insert magic headers
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

; Create kernel's stack
section .bootstrap_stack, "aw", @nobits
;align 4
stack_bottom: ; I'm not convinced this does anything
resb 16384 ; 16 KiB
stack_top:

section .bss, "aw", @nobits
align 4096
boot_page_directory:
resb 4096
boot_page_table_0:
resb 4096

; save the stack pointer and call the kernel
section .text
global _start:function (_start.end - _start)
_start:
	extern _init
	extern kernel_main
	extern _kernel_start
	extern _kernel_end
	mov edi, boot_page_table_0 - 0xC0000000
	mov esi, 0
	mov ecx, 1023

.a:
	cmp esi, _kernel_start - 0xC0000000
	jl .b
	cmp esi, _kernel_end - 0xC0000000
	jge .c

	mov edx, esi
	or edx, 0x003
	mov [edi], edx

.b:
	add esi, 4096
	add edi, 4
	loop .a ; loop for 1023 pages

.c:
	
	; remap VGA buffer memory into last page
	mov [boot_page_table_0 - 0xC0000000 + 1023 * 4], dword (0x000B8000 | 0x003)

	mov [boot_page_directory - 0xC0000000], dword (boot_page_table_0 - 0xC0000000 + 0x003)
	mov [boot_page_directory - 0xC0000000 + (768 * 4)], dword (boot_page_table_0 - 0xC0000000 + 0x003)

	mov ecx, (boot_page_directory - 0xC0000000)
	mov cr3, ecx
	mov ecx, cr0
	or ecx, 0x80010000
	mov cr0, ecx
	lea ecx, [.d]
	jmp ecx

.d:
	mov [boot_page_directory + 0], dword 0
	;reload cr3 to Flush TLB
	mov ecx, cr3
	mov cr3, ecx
	
	; set up stack
	mov esp, stack_top
	call _init
	call kernel_main
	; infinite loop after the kernel is done
	cli
.hang:	hlt
	jmp .hang
; Label for setting size of _start
.end:

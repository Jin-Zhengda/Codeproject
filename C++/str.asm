.data
	str: .string "1qab9a0bcabcds13"
	substr: .string "bcds"
	
.macro push %a
	addi	sp, sp, -4
	sw 		%a, 0(sp) 
.end_macro

.macro pop %a
	lw 		%a, 0(sp) 
	addi	sp, sp, 4
.end_macro

.text
.global _start

find_substr:
	push s1
	ori s1, zero, -1
	ori t1, zero, 0x0
	outer_loop: 
		bge t1, a4, exit
		ori t2, zero, 0x0
		inner_loop:
			bge t2, a5, outer_loop
			add t3, t1, t2
			add t3, t3, a2
			add t4, t2, a2
			push s2
			push s3
			lbu s2, 0(t3)
			lbu s3, 0(t4)
			bne s2, s3, break
			ori t5, zero, 0x1
			sub t5, a5, t5
			bne t2, t5, outer_if
			add s1, zero, t1
			b break
			outer_if:
				ori t6, zero, 0x1
				sub t6, zero, t6
				bne s1, t6, break
				addi t2, t2, 0x1
				b inner_loop
		break:
			pop s2
			pop s3
			addi t1, t1, 0x1
			b outer_loop
	exit:
		add a0, zero, s1
		pop s1
		jr ra

_start:
	lui a2, 0x10010
	addi a3, a0, 0x11
	ori a4, zero, 0x11
	ori a5, zero, 0x4
	jal ra, find_substr 
	 

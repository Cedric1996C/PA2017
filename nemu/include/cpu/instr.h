#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

#include "nemu.h"
#include "cpu/cpu.h"
#include "cpu/fpu.h"
#include "cpu/modrm.h"
#include "cpu/operand.h"
#include "cpu/instr_helper.h"
#include "memory/memory.h"

#include <stdio.h>
 
extern uint8_t data_size;

#include "cpu/instr/mov.h"
#include "cpu/instr/jmp.h"
#include "cpu/instr/shift.h"
#include "cpu/instr/flags.h"
#include "cpu/instr/group.h"
#include "cpu/instr/special.h"
#include "cpu/instr/x87.h"

/* TODO: add more instructions here */
int jmp_rel_v(uint32_t eip, uint8_t opcode);
int cmp_i2rm_bv(uint32_t eip, uint8_t opcode);
int push_ebp_v(uint32_t eip, uint8_t opcode);
int call_rel_v(uint32_t eip, uint8_t opcode);
int ret_v(uint32_t eip, uint8_t opcode);
int add_i2rm_v(uint32_t eip, uint8_t opcode);
int test_r2rm_v(uint32_t eip, uint8_t opcode);
int jz_b(uint32_t eip, uint8_t opcode);
int jnle_b(uint32_t eip, uint8_t opcode);
int jle_b(uint32_t eip, uint8_t opcode);
int jne_b(uint32_t eip, uint8_t opcode);
// int add_rm2r_b(uint32_t eip, uint8_t opcode);
int jmp_rel_b(uint32_t eip, uint8_t opcode);

int push_ebx_v(uint32_t eip, uint8_t opcode);
int sub_i2rm_bv(uint32_t eip, uint8_t opcode);

#endif

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
int push_REG_EBP_v(uint32_t eip, uint8_t opcode);
int call_rel_v(uint32_t eip, uint8_t opcode);
int ret_v(uint32_t eip, uint8_t opcode);
int add_i2rm_v(uint32_t eip, uint8_t opcode);
int test_r2rm_v(uint32_t eip, uint8_t opcode);
int je_b(uint32_t eip, uint8_t opcode);
int jnle_b(uint32_t eip, uint8_t opcode);
int jle_b(uint32_t eip, uint8_t opcode);
int jne_b(uint32_t eip, uint8_t opcode);
int add_rm2r_b(uint32_t eip, uint8_t opcode);

int push_REG_EBX_v(uint32_t eip, uint8_t opcode);
int sub_i2rm_bv(uint32_t eip, uint8_t opcode);
int jmp_rel_b(uint32_t eip, uint8_t opcode);
int jbe_b(uint32_t eip, uint8_t opcode);
int push_REG_EDX_v(uint32_t eip, uint8_t opcode);
int push_REG_EAX_v(uint32_t eip, uint8_t opcode);
int add_i2eax_v(uint32_t eip, uint8_t opcode);
int add_r2rm_v(uint32_t eip, uint8_t opcode);
int leave_v(uint32_t eip, uint8_t opcode);
int add_i2rm_bv(uint32_t eip, uint8_t opcode);
int lea_rm2r_v(uint32_t eip, uint8_t opcode);
int cmp_r2rm_v(uint32_t eip, uint8_t opcode);
int inc_rm_v(uint32_t eip, uint8_t opcode);

int and_i2rm_bv(uint32_t eip, uint8_t opcode);
int push_rm_v(uint32_t eip, uint8_t opcode);
int push_REG_EDI_v(uint32_t eip, uint8_t opcode);
int push_REG_ECX_v(uint32_t eip, uint8_t opcode);
int push_REG_ESI_v(uint32_t eip, uint8_t opcode);
int push_REG_ESP_v(uint32_t eip, uint8_t opcode);
int jbe_v(uint32_t eip, uint8_t opcode);
int adc_r2rm_v(uint32_t eip, uint8_t opcode);
int pop_ebx_v(uint32_t eip, uint8_t opcode);
int pop_ebp_v(uint32_t eip, uint8_t opcode);
int xor_r2rm_v(uint32_t eip, uint8_t opcode);
int or_r2rm_v(uint32_t eip, uint8_t opcode);

int cmp_i2rm_v(uint32_t eip, uint8_t opcode);
int dec_REG_EAX_v(uint32_t eip, uint8_t opcode);
int sub_rm2r_v(uint32_t eip, uint8_t opcode);
int cmp_rm2r_v(uint32_t eip, uint8_t opcode);
int inc_REG_EDX_v(uint32_t eip, uint8_t opcode);
int push_i_b(uint32_t eip, uint8_t opcode);
int jge_b(uint32_t eip, uint8_t opcode);
int jl_v(uint32_t eip, uint8_t opcode);
int cmp_rm2r_b(uint32_t eip, uint8_t opcode);
int dec_rm_v(uint32_t eip, uint8_t opcode);
int inc_REG_EAX_v(uint32_t eip, uint8_t opcode);
int sub_r2rm_v(uint32_t eip, uint8_t opcode);

int jle_v(uint32_t eip, uint8_t opcode);
int jl_b(uint32_t eip, uint8_t opcode);
int and_rm2r_b(uint32_t eip, uint8_t opcode);
int test_r2rm_b(uint32_t eip, uint8_t opcode);
int setne_b(uint32_t eip, uint8_t opcode);
int cmp_i2al_b(uint32_t eip, uint8_t opcode);
int cmp_i2rm_b(uint32_t eip, uint8_t opcode);
int or_rm2r_b(uint32_t eip, uint8_t opcode);
int or_rm2r_v(uint32_t eip, uint8_t opcode);
int not_rm_v(uint32_t eip, uint8_t opcode);
int and_r2rm_v(uint32_t eip, uint8_t opcode);

int sbb_rm2r_v(uint32_t eip, uint8_t opcode);
int imul_rm2r_v(uint32_t eip, uint8_t opcode);
int idiv_rm2a_v(uint32_t eip, uint8_t opcode);
int idiv_rm2a_b(uint32_t eip, uint8_t opcode);
int mul_rm2a_v(uint32_t eip, uint8_t opcode);
int mul_rm2a_b(uint32_t eip, uint8_t opcode);
int imul_rm2a_b(uint32_t eip, uint8_t opcode);
int imul_rm2a_v(uint32_t eip, uint8_t opcode);

int sub_i2rm_v(uint32_t eip, uint8_t opcode);
int pop_esi_v(uint32_t eip, uint8_t opcode);
int pop_edi_v(uint32_t eip, uint8_t opcode);
int ret_i_v(uint32_t eip, uint8_t opcode);
int and_i2rm_v(uint32_t eip, uint8_t opcode);
int test_i2rm_v(uint32_t eip, uint8_t opcode);
int test_i2eax_v(uint32_t eip, uint8_t opcode);

int add_i2rm_b(uint32_t eip, uint8_t opcode);
int stos_b(uint32_t eip, uint8_t opcode);
int test_i2al_b(uint32_t eip, uint8_t opcode);
int cmps_v(uint32_t eip, uint8_t opcode);
int cmps_b(uint32_t eip, uint8_t opcode);

int inc_REG_EDI_v(uint32_t eip, uint8_t opcode);
int test_i2rm_b(uint32_t eip, uint8_t opcode);
int je_v(uint32_t eip, uint8_t opcode);
int jne_v(uint32_t eip, uint8_t opcode);
int ja_v(uint32_t eip, uint8_t opcode);
int jmp_rm_v(uint32_t eip, uint8_t opcode);
int js_v(uint32_t eip, uint8_t opcode);
int jns_v(uint32_t eip, uint8_t opcode);
int jp_v(uint32_t eip, uint8_t opcode);
int jnp_v(uint32_t eip, uint8_t opcode);
int jge_v(uint32_t eip, uint8_t opcode);
int jg_v(uint32_t eip, uint8_t opcode);
int jo_v(uint32_t eip, uint8_t opcode);
int jno_v(uint32_t eip, uint8_t opcode);
int jb_v(uint32_t eip, uint8_t opcode);
int jae_v(uint32_t eip, uint8_t opcode);
int ja_b(uint32_t eip, uint8_t opcode);
int je_b(uint32_t eip, uint8_t opcode);
int jne_b(uint32_t eip, uint8_t opcode);
int ja_b(uint32_t eip, uint8_t opcode);
int js_b(uint32_t eip, uint8_t opcode);
int jns_b(uint32_t eip, uint8_t opcode);
int jp_b(uint32_t eip, uint8_t opcode);
int jnp_b(uint32_t eip, uint8_t opcode);
int jge_b(uint32_t eip, uint8_t opcode);
int jg_b(uint32_t eip, uint8_t opcode);
int jo_b(uint32_t eip, uint8_t opcode);
int jno_b(uint32_t eip, uint8_t opcode);
int jb_b(uint32_t eip, uint8_t opcode);
int jae_b(uint32_t eip, uint8_t opcode);

int inc_REG_ESP_v(uint32_t eip, uint8_t opcode);
int inc_REG_EBP_v(uint32_t eip, uint8_t opcode);
int inc_REG_ESI_v(uint32_t eip, uint8_t opcode);
int dec_REG_EBP_v(uint32_t eip, uint8_t opcode);
int and_i2rm_b(uint32_t eip, uint8_t opcode);



#endif

#include "cpu/instr.h"

static void instr_execute_2op_and()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_and(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
  cpu.eflags.OF = 0;
  cpu.eflags.CF = 0;
}

make_instr_impl_2op_and(i, rm, v);

make_instr_func(and_i2rm_bv)
{
  OPERAND imm, rm;
  int len = 1;
  imm.data_size = 8;
  rm.data_size = data_size;

  len += modrm_opcode_rm(eip+len, &opcode, &rm);
  operand_read(&rm);
  imm.type = OPR_IMM;
  imm.addr = eip+len;
  operand_read(&imm);
  len += 1;

  if(data_size == 16)
    imm.val = (uint16_t)(imm.val << 8) >> 8;
  else
    imm.val = (uint32_t)(imm.val << 24) >> 24;

  rm.val = alu_and(imm.val, rm.val);
  print_asm_2("and", "", len, &imm, &rm);
  operand_write(&rm);
  cpu.eflags.OF = 0;
  cpu.eflags.CF = 0;

  return len;
}
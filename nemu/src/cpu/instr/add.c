#include "cpu/instr.h"

make_instr_func(add_i2rm_v)
{
  OPERAND imm, rm;
  int len = 1;
  int data_byte = data_size / 8;
  len += modrm_opcode_rm(eip + 1, &opcode, &rm);

  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip + len;
  operand_read(&imm);

  rm.data_size = data_size;
  operand_read(&rm);
  print_asm_2("add", "", len+data_byte, &imm, &rm);
  rm.val = alu_add(imm.val, rm.val);

  return len+data_byte;
}

make_instr_func(add_rm2r_b)
{
  OPERAND reg, rm;
  int len = 1;
  reg.data_size = 8;
  rm.data_size = 8;
  len += modrm_r_rm(eip+1, &reg, &rm);

  operand_read(&reg);
  operand_read(&rm);

  alu_add(rm.val, reg.val);
  operand_write(&reg);

  return len;
}
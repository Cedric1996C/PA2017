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
  print_asm_2("add", "", len + data_byte, &imm, &rm);
  rm.val = alu_add(imm.val, rm.val);
  operand_write(&rm);
  
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

  reg.val = alu_add(rm.val, reg.val);
  operand_write(&reg);

  return len;
}

make_instr_func(add_i2eax_v)
{
  OPERAND reg, imm;
  int len = 1 + data_size / 8;

  reg.type = OPR_REG;
  reg.data_size = data_size;
  reg.addr = REG_EAX;
  operand_read(&reg);

  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip+1;
  operand_read(&imm);
  print_asm_2("add", "", len, &imm, &reg);
  reg.val = alu_add(imm.val, reg.val);
  operand_write(&reg);

  return len;
}

make_instr_func(add_r2rm_v)
{
  OPERAND reg, rm;
  int len = 1;
  reg.data_size = data_size;
  rm.data_size = data_size;
  len += modrm_r_rm(eip+1, &reg, &rm);
  
  operand_read(&reg);
  operand_read(&rm);
  rm.val = alu_add(reg.val, rm.val);
  operand_write(&rm);

  return len;
}

make_instr_func(add_i2rm_bv)
{
  OPERAND rm, imm;
  int len = 1;
  len += modrm_opcode_rm(eip+1, &opcode, &rm);
  rm.data_size = data_size;
  operand_read(&rm);

  imm.type = OPR_IMM;
  imm.data_size = 8;
  imm.addr = eip + len;
  len += 1;
  operand_read(&imm);

  imm.data_size = 32;
  imm.val = sign_ext(imm.val, 8);
  rm.val = alu_add(imm.val, rm.val);
  operand_write(&rm);
  print_asm_2("add", "", len, &imm, &rm);

  return len;
}

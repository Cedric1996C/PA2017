#include "cpu/instr.h"

static void instr_execute_2op()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_sub(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
}

make_instr_impl_2op(sub, rm, r, v);
make_instr_impl_2op(sub, r, rm, v);
make_instr_impl_2op(sub, i, rm, v);

make_instr_func(sub_i2rm_bv)
{
  OPERAND imm,rm;
  int len = 1;
  
  rm.data_size = data_size;
  len += modrm_opcode_rm(eip+1, &opcode, &rm);
  operand_read(&rm);
  
  imm.type = OPR_IMM;
  imm.data_size = 8;
  imm.addr = eip + len;
  operand_read(&imm);
  len += 1;

  imm.data_size = 32;
  imm.val = sign_ext(imm.val, 8);
  rm.val = alu_sub(imm.val, rm.val);
  operand_write(&rm);

  print_asm_2("sub", "", len, &imm, &rm);

  return len;
}


#include "cpu/instr.h"

static void instr_execute_2op()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_adc(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
}

make_instr_impl_2op(adc, r, rm ,v);

make_instr_func(adc_i2al_b)
{
  OPERAND imm, al;
  int len = 1;
  imm.type = OPR_IMM;
  imm.data_size = 8;
  imm.addr = eip+len;
  len += 1;
  operand_read(&imm);

  al.type = OPR_REG;
  al.data_size = 8;
  al.addr = REG_AL;
  operand_read(&al);

  al.val = alu_adc(imm.val, al.val);
  operand_write(&al);
  print_asm_2("adc", "", len, &imm, &al);

  return len;
}

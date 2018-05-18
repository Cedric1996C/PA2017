#include "cpu/instr.h"

static void instr_execute_2op()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_and(opr_src.val, opr_dest.val);
  cpu.eflags.OF = 0;
  cpu.eflags.CF = 0;
}

make_instr_impl_2op(test, r, rm, b)
make_instr_impl_2op(test, r, rm, v)
make_instr_impl_2op(test, i, rm, v)
make_instr_impl_2op(test, i, rm, b)

make_instr_func(test_i2eax_v){
  OPERAND imm, eax;
  int len = 1;
  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip + len;
  len += data_size / 8;
  eax.type = OPR_REG;
  eax.addr = REG_EAX;
  eax.data_size = data_size;

  print_asm_2("test", "", len, &imm, &eax);
  operand_read(&imm);
  operand_read(&eax);
  imm.val = alu_and(imm.val, eax.val);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;

  return len;
}

make_instr_func(test_i2al_b)
{
  OPERAND imm, al;
  int len = 1;
  imm.type = OPR_IMM;
  imm.data_size = 8;
  imm.addr = eip + len;
  len += 1;
  al.type = OPR_REG;
  al.addr = REG_AL;
  al.data_size = 8;

  print_asm_2("test", "", len, &imm, &al);
  operand_read(&imm);
  operand_read(&al);
  imm.val = alu_and(imm.val, al.val);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;

  return len;
}

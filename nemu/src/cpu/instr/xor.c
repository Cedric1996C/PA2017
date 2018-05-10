#include "cpu/instr.h"

static void instr_execute_2op_xor()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_xor(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
}

static void instr_execute_2op_or()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  print_asm_2("or", "", 2, &opr_src, &opr_dest);
  opr_dest.val = alu_or(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
  
}

make_instr_impl_2op_or(xor, r, rm, v);
make_instr_impl_2op_or(or, r, rm, v);
make_instr_impl_2op_or(or, r, rm, b);

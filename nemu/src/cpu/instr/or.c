#include "cpu/instr.h"

static void instr_execute_2op()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  print_asm_2("or", "", 2, &opr_src, &opr_dest);
  opr_dest.val = alu_or(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
}

make_instr_impl_2op(or, r, rm, v);
make_instr_impl_2op(or, rm, r, b);
make_instr_impl_2op(or, rm, r, v);
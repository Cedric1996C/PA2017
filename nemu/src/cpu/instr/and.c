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

make_instr_impl_2op_and(i, rm, bv);
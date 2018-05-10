#include "cpu/instr.h"

static void instr_execute_1op()
{
  opr_src.val = ~opr_src.val;
  operand_write(&opr_src);
}

make_instr_impl_1op(not, rm, v)
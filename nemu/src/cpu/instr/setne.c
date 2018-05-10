# include "cpu/instr.h"

static void instr_execute_1op_cc_pass(){
  opr_src.val = 1;
  operand_write(&opr_src);
}

static void instr_execute_1op_cc_fail(){
  opr_src.val = 0;
  operand_write(&opr_src);
}


make_instr_impl_1op_cc(set, rm, b, ne);
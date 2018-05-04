#include "cpu/instr.h"

static void instr_execute_1op_dec_reg()
{
  operand_read(&opr_src);
  uint32_t temp_CF = cpu.eflags.CF;
  opr_src.val = alu_sub(1, opr_src.val);
  operand_write(&opr_src);
  cpu.eflags.CF = temp_CF;
}

make_instr_impl_1op_dec_reg(eax, v);
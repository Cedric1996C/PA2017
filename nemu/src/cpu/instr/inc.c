#include "cpu/instr.h"

static void instr_execute_1op_inc()
{
  operand_read(&opr_src);
  uint32_t temp_CF = cpu.eflags.CF;
  opr_src.val = alu_add(1, opr_src.val);
  cpu.eflags.CF = temp_CF;
  operand_write(&opr_src);
}

static void instr_execute_1op_inc_reg()
{
  uint32_t temp_CF = cpu.eflags.CF;
  opr_src.val = alu_add(1, opr_src.val);
  cpu.eflags.CF = temp_CF;
}

make_instr_impl_1op_inc(rm, v);
make_instr_impl_1op_inc_reg(edx, v);

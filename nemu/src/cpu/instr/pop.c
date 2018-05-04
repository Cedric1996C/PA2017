#include "cpu/instr.h"

// static void instr_execute_1op_pop()
// {
//   cpu.esp -= data_size / 8;
//   operand_read(&opr_src);
//   OPERAND reg;
//   reg.type = OPR_MEM;
//   reg.data_size = data_size;
//   reg.val = opr_src.val;
//   reg.addr = cpu.esp;
//   operand_write(&reg);
// }

static void instr_execute_1op_pop_reg()
{
  opr_src.type = OPR_MEM;
  opr_src.data_size = data_size;
  // temp_ebp.sreg = SREG_SS;
  opr_src.addr = cpu.esp;
  operand_read(&opr_src);
  cpu.esp += data_size / 8;
}

make_instr_impl_1op_pop_reg(ebx, v);
make_instr_impl_1op_pop_reg(ebp, v);
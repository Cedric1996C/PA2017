#include "cpu/instr.h"

static void instr_execute_1op(){
  operand_read(&opr_src);
  cpu.esp += data_size / 8;
  opr_dest.val = opr_src.val;
  operand_write(&opr_dest);
}

// static void instr_execute_1op_pop_reg()
// {
//   opr_src.type = OPR_MEM;
//   opr_src.data_size = data_size;
//   // temp_ebp.sreg = SREG_SS;
//   opr_src.addr = cpu.esp;
//   operand_read(&opr_src);
//   cpu.esp += data_size / 8;
// }

make_instr_impl_1op_reg(pop, REG_EBX, v);
make_instr_impl_1op_reg(pop, REG_EBP, v);
make_instr_impl_1op_reg(pop, REG_ESI, v);
make_instr_impl_1op_reg(pop, REG_EDI, v);
#include "cpu/instr.h"

static void instr_execute_2op()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_and(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
  cpu.eflags.OF = 0;
  cpu.eflags.CF = 0;
}

make_instr_impl_2op(test, r, rm, b)
make_instr_impl_2op(test, r, rm, v)

// make_instr_func(test_r2rm_v)
// {
//   OPERAND reg, rm;
//   int len = 1;
  
//   reg.data_size = data_size;
//   rm.data_size = data_size;
//   len += modrm_r_rm(eip+1, &reg, &rm);
//   operand_read(&reg);
//   operand_read(&rm);
//   print_asm_2("test", "", len, &reg, &rm);
//   rm.val = alu_and(reg.val, rm.val);
//   cpu.eflags.CF = 0;
//   cpu.eflags.OF = 0;
  
//   return len;
// }

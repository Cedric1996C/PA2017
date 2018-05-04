#include "cpu/instr.h"

static void instr_execute_2op_cmp()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_sub(reg.val, rm.val);
}

make_instr_impl_2op_cmp(r, rm, v);
make_instr_impl_2op_cmp(i ,rm ,v);

// make_instr_func(cmp_r2rm_v)
// {
//   OPERAND reg, rm;
//   int len = 1;
//   reg.data_size = data_size;
//   rm.data_size = data_size;
//   len += modrm_r_rm(eip + 1, &reg, &rm);

//   operand_read(&reg);
//   operand_read(&rm);

//   rm.val = alu_sub(reg.val, rm.val);
//   print_asm_2("cmp", "", len, &reg, &rm);

//   return len;
// }

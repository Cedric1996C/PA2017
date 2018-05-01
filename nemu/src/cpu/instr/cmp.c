#include "cpu/instr.h"

make_instr_func(cmp_r2rm_v)
{
  PERAND reg, rm;
  int len = 1;
  reg.data_size = data_size;
  rm.data_size = data_size;
  len += modrm_r_rm(eip + 1, &reg, &rm);

  operand_read(&reg);
  operand_read(&rm);

  alu_sub(reg.val, rm.val);

  return len;
}
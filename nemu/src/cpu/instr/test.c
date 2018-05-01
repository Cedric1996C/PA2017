#include "cpu/instr.h"

make_instr_func(test_r2rm_v)
{
  OPERAND reg, rm;
  int len = 1;
  
  reg.data_size = data_size;
  rm.data_size = data_size;
  len += modrm_r_rm(eip+1, &reg, &rm);
  operand_read(&reg);
  operand_read(&rm);
  print_asm_2("test", "", len, &reg, &rm);
  alu_add(reg.val, rm.val);
  
  return len;
}
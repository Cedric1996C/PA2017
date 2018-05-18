#include "cpu/instr.h"

static void instr_execute_1op()
{
  operand_read(&opr_src);
  // uint32_t temp_CF = cpu.eflags.CF;
  opr_src.val = alu_add(1, opr_src.val);
  // cpu.eflags.CF = temp_CF;
  operand_write(&opr_src);
}

make_instr_func(inc_rm_v){
  OPERAND rm;
  int len = 1;

  rm.data_size = data_size;
  len += modrm_rm(eip + len, &rm);
  operand_read(&rm);

  rm.val = alu_add(1, rm.val);
  operand_write(&rm);
  print_asm_1("inc", "", len, &rm);

  return len;
}

// make_instr_impl_1op(inc, rm, v);
make_instr_impl_1op_reg(inc, REG_EDX, v);
make_instr_impl_1op_reg(inc, REG_EAX, v);
make_instr_impl_1op_reg(inc, REG_EDI, v);
make_instr_impl_1op_reg(inc, REG_ESP, v);
make_instr_impl_1op_reg(inc, REG_EBP, v);
make_instr_impl_1op_reg(inc, REG_ESI, v);
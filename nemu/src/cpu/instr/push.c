#include "cpu/instr.h"

make_instr_func(push_ebp_v)
{
  OPERAND temp_ebp;
  cpu.esp -= data_size / 8;
  int len = 1;

  temp_ebp.type = OPR_MEM;
  temp_ebp.data_size = data_size;
  temp_ebp.val = cpu.ebp;
  // temp_ebp.sreg = SREG_SS;
  temp_ebp.addr = cpu.esp;

  operand_write(&temp_ebp);
  print_asm_0("push	ebp", "", len);
  return len;
}

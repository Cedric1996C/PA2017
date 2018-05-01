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

  return len;
}

make_instr_func(push_ebx_v)
{
  OPERAND temp_ebx;
  cpu.esp -= data_size / 8;
  int len = 1;

  temp_ebx.type = OPR_MEM;
  temp_ebx.data_size = data_size;
  temp_ebx.val = cpu.ebx;
  // temp_ebp.sreg = SREG_SS;
  temp_ebx.addr = cpu.esp;

  operand_write(&temp_ebx);

  return len;
}

make_instr_func(push_edx_v)
{
  OPERAND temp_edx;
  cpu.esp -= data_size / 8;
  int len = 1;

  temp_edx.type = OPR_MEM;
  temp_edx.data_size = data_size;
  temp_edx.val = cpu.edx;
  // temp_ebp.sreg = SREG_SS;
  temp_edx.addr = cpu.esp;

  operand_write(&temp_edx);

  return len;
}

#include "cpu/instr.h"

make_instr_func(push_ebp_v)
{
  OPERAND reg;
  cpu.esp -= data_size / 8;
  int len = 1;

  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = cpu.ebp;
  // temp_ebp.sreg = SREG_SS;
  reg.addr = cpu.esp;

  operand_write(&reg);

  return len;
}

make_instr_func(push_ebx_v)
{
  // OPERAND reg;
  cpu.esp -= data_size / 8;
  int len = 1;

  // reg.type = OPR_MEM;
  // reg.data_size = data_size;
  // reg.val = cpu.ebx;
  // // temp_ebp.sreg = SREG_SS;
  // reg.addr = cpu.esp;

  // operand_write(&reg);

  return len;
}

make_instr_func(push_edx_v)
{
  OPERAND reg;
  cpu.esp -= data_size / 8;
  int len = 1;

  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = cpu.edx;
  // temp_ebp.sreg = SREG_SS;
  reg.addr = cpu.esp;

  operand_write(&reg);

  return len;
}

make_instr_func(push_eax_v)
{
  OPERAND reg;
  cpu.esp -= data_size / 8;
  int len = 1;

  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = cpu.eax;
  // temp_ebp.sreg = SREG_SS;
  reg.addr = cpu.esp;

  operand_write(&reg);

  return len;
}

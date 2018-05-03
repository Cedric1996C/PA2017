#include "cpu/instr.h"

static void instr_execute_1op_push()
{
  cpu.eip -= data_size / 8;
  opr_src.val = opr_src.addr;
  opr_src.addr = cpu.esp;
  operand_write(&opr_src);
}

make_instr_impl_1op_push(rm, v);

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
  OPERAND reg;
  cpu.esp -= data_size / 8;
  int len = 1;

  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = cpu.ebx;
  // temp_ebp.sreg = SREG_SS;
  reg.addr = cpu.esp;

  operand_write(&reg);

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

#include "cpu/instr.h"

static void instr_execute_1op_push()
{
  cpu.eip -= data_size / 8;
  opr_src.val = opr_src.addr;
  opr_src.addr = cpu.esp;
  operand_write(&opr_src);
}

make_instr_impl_1op_push(r, v);

make_instr_func(push_rm_v)
{
  OPERAND rm, reg;
  int len = 1;
  cpu.eip -= data_size / 8;

  rm.data_size = data_size;
  len -= modrm_opcode_rm(eip+1, &opcode, &rm);
  operand_read(&rm);

  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = rm.val;
  reg.addr = cpu.esp;
  operand_write(&reg);
  print_asm_1("pushl", "", len, &rm);

  return len;
}

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

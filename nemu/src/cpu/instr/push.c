#include "cpu/instr.h"

static void instr_execute_1op()
{
  cpu.esp -= data_size / 8;
  operand_read(&opr_src);
  OPERAND reg;
  reg.type = OPR_MEM;
  reg.data_size = data_size;
  reg.val = opr_src.val;
  reg.addr = cpu.esp;
  operand_write(&reg);
}

make_instr_impl_1op(push, rm, v);

make_instr_impl_1op_reg(push, REG_EBP, v);
make_instr_impl_1op_reg(push, REG_EBX, v);
make_instr_impl_1op_reg(push, REG_EDX, v);
make_instr_impl_1op_reg(push, REG_EAX, v);
make_instr_impl_1op_reg(push, REG_ECX, v);
make_instr_impl_1op_reg(push, REG_EDI, v);
make_instr_impl_1op_reg(push, REG_ESI, v);
make_instr_impl_1op_reg(push, REG_ESP, v);

make_instr_func(push_i_b)
{
  OPERAND imm;
  int len = 1;

  imm.type = OPR_IMM;
  imm.data_size = 8;
  imm.addr = eip+1;
  len += 1;
  operand_read(&imm);

  cpu.esp -= 4;
  imm.addr = cpu.esp;
  imm.type = OPR_MEM;
  imm.data_size = 32;
  // imm.sreg = SREG_SS;
  operand_write(&imm);

  return len;
}

make_instr_func(push_i_v)
{
  OPERAND imm;
  int len = 1;

  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip + 1;
  len += data_size/8;
  operand_read(&imm);

  cpu.esp -= 4;
  imm.addr = cpu.esp;
  imm.type = OPR_MEM;
  imm.data_size = 32;
  // imm.sreg = SREG_SS;
  operand_write(&imm);

  return len;
}

// make_instr_func(push_ebx_v)
// {
//   OPERAND reg;
//   cpu.esp -= data_size / 8;
//   int len = 1;

//   reg.type = OPR_MEM;
//   reg.data_size = data_size;
//   reg.val = cpu.ebx;
//   // temp_ebp.sreg = SREG_SS;
//   reg.addr = cpu.esp;

//   operand_write(&reg);

//   return len;
// }

// make_instr_func(push_edx_v)
// {
//   OPERAND reg;
//   cpu.esp -= data_size / 8;
//   int len = 1;

//   reg.type = OPR_MEM;
//   reg.data_size = data_size;
//   reg.val = cpu.edx;
//   // temp_ebp.sreg = SREG_SS;
//   reg.addr = cpu.esp;

//   operand_write(&reg);

//   return len;
// }

// make_instr_func(push_eax_v)
// {
//   OPERAND reg;
//   cpu.esp -= data_size / 8;
//   int len = 1;

//   reg.type = OPR_MEM;
//   reg.data_size = data_size;
//   reg.val = cpu.eax;
//   // temp_ebp.sreg = SREG_SS;
//   reg.addr = cpu.esp;

//   operand_write(&reg);

//   return len;
// }

// make_instr_func(push_edi_v)
// {
//   OPERAND reg;
//   cpu.esp -= data_size / 8;
//   int len = 1;

//   reg.type = OPR_MEM;
//   reg.data_size = data_size;
//   reg.val = cpu.edi;
//   // temp_ebp.sreg = SREG_SS;
//   reg.addr = cpu.esp;

//   operand_write(&reg);

//   return len;
// }

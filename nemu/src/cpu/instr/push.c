#include "cpu/instr.h"

static void instr_execute_1op_push()
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

static void instr_execute_1op_push_reg()
{
  cpu.esp -= data_size / 8;
  opr_src.type = OPR_MEM;
  opr_src.data_size = data_size;
  // temp_ebp.sreg = SREG_SS;
  opr_src.addr = cpu.esp;
}

make_instr_impl_1op_push(rm, v);

make_instr_impl_1op_push_reg(ebp, v);
make_instr_impl_1op_push_reg(ebx, v);
make_instr_impl_1op_push_reg(edx, v);
make_instr_impl_1op_push_reg(eax, v);
make_instr_impl_1op_push_reg(ecx, v);
make_instr_impl_1op_push_reg(edi, v);
make_instr_impl_1op_push_reg(esi, v);
make_instr_impl_1op_push_reg(esp, v);

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

#include "cpu/instr.h"

// make_instr_func(call_rel_v)
// {
//   OPERAND temp_eip, rel;
//   int data_byte = data_size / 8;
//   int len = 1 + data_byte;
//   cpu.esp -= data_byte;

//   temp_eip.type = OPR_MEM;
//   temp_eip.data_size = data_size;
//   temp_eip.val = cpu.eip;
//   temp_eip.addr = cpu.esp;
//   operand_write(&temp_eip);

//   rel.type = OPR_IMM;
//   rel.data_size = data_size;
//   rel.addr = eip + 1;
//   operand_read(&rel);

//   if(data_size == 16){
//     cpu.eip = (cpu.eip + rel.val)&0x0000ffff;
//   } else {
//     cpu.eip += rel.val;
//   }
//   return len;
// }

make_instr_func(call_rel_v)
{
  OPERAND opr_eip, imm;
  int len = 1 + data_size / 8;
  cpu.esp -= data_size / 8;

  opr_eip.type = OPR_MEM;
  opr_eip.data_size = data_size;
  opr_eip.val = eip + len;
  opr_eip.addr = cpu.esp;
  opr_eip.sreg = SREG_SS;
  operand_write(&opr_eip);

  imm.data_size = data_size;
  imm.type = OPR_IMM;
  imm.addr = eip + 1;
  operand_read(&imm);
  print_asm_1("call", "", len, &imm);

  assert(data_size == 16 || data_size == 32);
  if (data_size == 16)
  {
    imm.val = (int32_t)(imm.val << 16) >> 16;
  }
  len += (int32_t)imm.val;
  return len;
}
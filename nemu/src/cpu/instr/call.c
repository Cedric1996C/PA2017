#include "cpu/instr.h"

make_instr_func(call_rel_v)
{
  OPERAND temp_eip, imm;
  int data_byte = data_size / 8;
  int len = 1 + data_byte;
  cpu.esp -= data_byte;

  temp_eip.type = OPR_MEM;
  temp_eip.data_size = data_size;
  temp_eip.val = cpu.eip;
  temp_eip.addr = cpu.esp;
  operand_read(&temp_eip);

  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip + 1;
  operand_read(&imm);

  if(data_size == 16){
    cpu.eip = (cpu.eip + imm.val)&0x0000ffff;
  } else {
    cpu.eip += imm.val;
  }
  return len;
}
#include "cpu/instr.h"

make_instr_func(call_rel_v)
{
  OPERAND temp_eip, rel;
  int data_byte = data_size / 8;
  int len = 1 + data_byte;
  cpu.esp -= data_byte;

  temp_eip.type = OPR_MEM;
  temp_eip.data_size = data_size;
  print_asm_1("call","",len,&temp_eip);
  temp_eip.val = cpu.eip;
  temp_eip.addr = cpu.esp;
  operand_write(&temp_eip);

  rel.type = OPR_IMM;
  rel.data_size = data_size;
  rel.addr = eip + 1;
  operand_read(&rel);

  if(data_size == 16){
    cpu.eip = (cpu.eip + rel.val)&0x0000ffff;
  } else {
    cpu.eip += rel.val;
  }
  return len;
}
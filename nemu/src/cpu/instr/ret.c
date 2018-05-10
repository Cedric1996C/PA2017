#include "cpu/instr.h"

make_instr_func(ret_v)
{
  OPERAND rel;

  rel.type = OPR_MEM;
  rel.addr = cpu.esp;
  rel.data_size = data_size;
  operand_read(&rel);
  cpu.esp += data_size / 8;
  if(data_size == 16){
    cpu.eip = rel.val & 0x0000ffff;
  } else {
    cpu.eip = rel.val;
  }
  
  return 0;
}

make_instr_func(ret_i_v)
{
  OPERAND imm, rel;
  int len = 1;

  imm.type = OPR_IMM;
  imm.data_size = 16;
  imm.addr = eip + len;
  len += 1;
  operand_read(&imm);

  rel.type = OPR_IMM;
  rel.addr = cpu.esp;
  rel.data_size = data_size;
  operand_read(&rel);

  cpu.esp += sign_ext(imm.val, 32);
  cpu.esp += data_size / 8;
  cpu.eip = rel.val;

  return 0;
}

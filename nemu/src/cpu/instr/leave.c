#include "cpu/instr.h"

make_instr_func(leave_v)
{
  OPERAND ebp;
  int len = 1;
  cpu.esp = cpu.ebp;

  ebp.type = OPR_MEM;
  ebp.data_size = data_size;
  ebp.addr = cpu.ebp;
  operand_read(&ebp);

  cpu.ebp = ebp.val;
  cpu.esp += data_size / 8;

  return len;
}

make_instr_func(lea_rm2r_v)
{
  OPERAND rm, r;
  int len = 1;
  len += modrm_r_rm(eip + len, &r, &rm);

  rm.data_size = data_size;
  r.data_size = data_size;
  r.val = rm.addr;
  operand_write(&r);
  print_asm_2("lea", "", len, &rm, &r);

  return len;
}
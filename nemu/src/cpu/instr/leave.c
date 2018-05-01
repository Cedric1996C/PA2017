#include "cpu/instr.h"

make_instr_func(leave_v){
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
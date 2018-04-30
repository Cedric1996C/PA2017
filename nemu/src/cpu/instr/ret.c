#include "cpu/instr.h"

// make_instr_func(ret_v)
// {
//   OPERAND rel;
//   cpu.esp -= data_size / 8;

//   rel.type = OPR_MEM;
//   rel.addr = cpu.esp;
//   rel.data_size = data_size;
//   operand_read(&rel);
//   if(data_size == 16){
//     cpu.eip = rel.val & 0x0000ffff;
//   } else {
//     cpu.eip = rel.val;
//   }
//   return 0;
// }

make_instr_func(ret_v)
{
  OPERAND addr;
  int len = 1;

  addr.type = OPR_MEM;
  addr.data_size = data_size;
  addr.addr = cpu.esp;
  addr.sreg = SREG_SS;
  operand_read(&addr);
  cpu.esp += data_size / 8;
  print_asm_0("ret", "", len);

  assert(data_size == 16 || data_size == 32);
  if (data_size == 16)
    cpu.eip = addr.val & 0xffff;
  else
    cpu.eip = addr.val;

  return 0;
}
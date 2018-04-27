#include "cpu/instr.h"

make_instr_func(push_ebp_v)
{
  int len = 1;
  uint8_t op = instr_fetch(eip + 1, 1);
  len += opcode_2_byte_entry[op](eip + 1, op);
  return len;
}

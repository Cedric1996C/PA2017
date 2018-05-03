#include "cpu/instr.h"

make_instr_func(jmp_near)
{
  OPERAND rel;
  rel.type = OPR_IMM;
  rel.sreg = SREG_CS;
  rel.data_size = data_size;
  rel.addr = eip + 1;

  operand_read(&rel);

  int offset = sign_ext(rel.val, data_size);
  print_asm_1("jmp", "", 1 + data_size / 8, &rel);

  cpu.eip += offset;

  return 1 + data_size / 8;
}

make_instr_func(jmp_rel_v)
{
  OPERAND imm;

  int len = 1;
  imm.type = OPR_IMM;
  imm.addr = eip + len;
  len += data_size / 8;
  imm.data_size = data_size;
  operand_read(&imm);
  if (imm.data_size == 16)
          len += (int32_t)(imm.val << 16) >> 16;
  else
          len += imm.val;
  return len;
}

make_instr_func(jmp_rel_b)
{
  // OPERAND imm;

  int len = 1;
  // imm.type = OPR_IMM;
  // imm.addr = eip + len;
  // len += 1;
  // imm.data_size = 8;
  // operand_read(&imm);
  // len += (uint8_t)imm.val;
  return len;
}

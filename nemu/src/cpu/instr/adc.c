#include "cpu/instr.h"

static void instr_execute_2op_adc()
{
  operand_read(&opr_src);
  operand_read(&opr_dest);
  opr_dest.val = alu_adc(opr_src.val, opr_dest.val);
  operand_write(&opr_dest);
}

make_instr_impl_2op_adc(adc, r, rm ,v);

// make_instr_func(adc_r2rm_v)
// {
//   OPERAND reg, rm;
//   int len = 1;
//   int data_byte = data_size / 8;
//   len += modrm_opcode_rm(eip + 1, &opcode, &rm);

//   reg.type = OPR_reg;
//   reg.data_size = data_size;
//   reg.addr = eip + len;
//   operand_read(&reg);

//   rm.data_size = data_size;
//   operand_read(&rm);
//   rm.val = alu_add(reg.val, rm.val);
//   operand_write(&rm);
//   print_asm_2("adc", "", len + data_byte, &reg, &rm);

//   return len + data_byte;
// }

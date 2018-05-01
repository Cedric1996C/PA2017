# include "cpu/instr"

make_instr_func(sub_i2rm_bv)
{
  OPERAND imm,rm;
  int len = 1;
  
  rm.data_size = data_size;
  len += modrm_opcode_rm(eip+1, opcode, &rm);
  operand_read(&rm);
  
  imm.type = OPR_IMM;
  imm.data_size = data_size;
  imm.addr = eip + len;
  operand_read(&imm);

  alu_sub(imm.val, rm.val);
  operand_write(&rm);

  return len;
}


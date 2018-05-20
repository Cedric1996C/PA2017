#include "cpu/cpu.h"

/*
void set_CF_add(uint32_t result, uint32_t src){
  cpu.eflags.CF = result < src;
}

void set_CF_adc(uint32_t result, uint32_t src, uint32_t dest){
  if(cpu.eflags.CF){
    if(result <= src || result <= dest)
      cpu.eflags.CF = 1;
    else
      cpu.eflags.CF = 0;
  }
  else
    set_CF_add(result, src);
}

void set_PF(uint32_t result){
  int zero_num = 0;
  for(int i=0;i<8;i++){
    if(result%2 == 1)
      zero_num++;
    result >>= 1;
  }
  cpu.eflags.PF = zero_num%2 == 0;
}

void set_ZF(uint32_t result){
  cpu.eflags.ZF = result == 0;
}

void set_SF(uint32_t result){
  cpu.eflags.SF = sign(result);
}

void set_OF_add(uint32_t result, uint32_t src, uint32_t dest){
  if(sign(src) == sign(dest)){
    cpu.eflags.OF = sign(result)!=sign(src);
  } else {
    cpu.eflags.OF = 0;
  }
}

uint32_t alu_add(uint32_t src, uint32_t dest) {
	uint32_t result = src + dest;
  set_CF_add(result, src);
  set_PF(result);
  set_ZF(result);
  set_SF(result);
  set_OF_add(result, src, dest);
	return result;
}

uint32_t alu_adc(uint32_t src, uint32_t dest) {
  uint32_t result = src + dest + cpu.eflags.CF;
  set_CF_adc(result, src, dest);
  set_PF(result);
  set_ZF(result);
  set_SF(result);
  set_OF_add(result, src, dest);
	return result;
}

void set_CF_sub(uint32_t src, uint32_t dest){
  cpu.eflags.CF = dest < src;
}

void set_OF_sub(uint32_t src, uint32_t dest){
  uint32_t src_neg = ~(src+1) + 1;
  set_OF_add(dest-src, src_neg, dest);
}

uint32_t alu_sub(uint32_t src, uint32_t dest) {
	uint32_t result = dest - src;
  set_CF_sub(src, dest);
  set_PF(result);
  set_ZF(result);
  set_SF(result);
  set_OF_sub(src, dest);
	return result;
}

void set_CF_sbb(uint32_t src, uint32_t dest){
  if(!cpu.eflags.CF){
    set_CF_sub(src, dest);
  } else {
    cpu.eflags.CF = src >= dest;
  }
}

void set_OF_sbb(uint32_t src, uint32_t dest){
  if(!cpu.eflags.CF){
    set_OF_sub(src, dest);
  } else {
    uint32_t src_neg = ~(src+1) + 1;
    set_OF_add(src_neg + dest, src_neg, dest);
  }
}

uint32_t alu_sbb(uint32_t src, uint32_t dest) {
  uint32_t result = dest - (src + cpu.eflags.CF);
  set_PF(result);
  set_ZF(result);
  set_SF(result);
  set_OF_sbb(src, dest);
  set_CF_sbb(result, dest);
	return result;
}


uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size) {
	uint64_t result = (uint64_t)src * (uint64_t)dest;
  bool res=0;
  uint8_t high_8_bits;
  uint16_t high_16_bits;
  uint32_t high_32_bits;
  switch(data_size){
    case 8:
      high_8_bits = (result & 0xff00) >> 8;
      res = high_8_bits ? 1:0;
      break;
    case 16:
      high_16_bits = (result & 0xffff0000) >> 16;
      res = high_16_bits ? 1:0;
      break;
    case 32:
      high_32_bits = (result & 0xffffffff00000000) >> 32;
      res = high_32_bits ? 1:0;
      break;
    default:
      break;
  }
  cpu.eflags.OF = res ? 1:0;
  cpu.eflags.CF = res ? 1:0;
	return result;
}

int64_t alu_imul(int32_t src, int32_t dest, size_t data_size) {
  uint64_t result = (uint64_t)src * (uint64_t)dest;
	return result;
}

uint32_t alu_div(uint64_t src, uint64_t dest, size_t data_size) {
  if(src==0) assert(0);
  uint64_t low_16_bits,low_32_bits;
  switch(data_size){
    case 8:
      low_16_bits = dest & 0xffff;
      src = src & 0xff;
      dest = low_16_bits / src;
      break;
    case 16:
      low_32_bits = dest & 0xffffffff;
      src = src & 0xffff;
      dest = low_32_bits / src;
      break;
    case 32:
      dest = dest / src;
      break;
    default:
      break;
  }
	return dest;
}

int32_t alu_idiv(int64_t src, int64_t dest, size_t data_size) {
	if(src==0) assert(0);
  uint64_t low_16_bits,low_32_bits;
  switch(data_size){
    case 8:
      low_16_bits = dest & 0xffff;
      src = src & 0xff;
      dest = low_16_bits / src;
      break;
    case 16:
      low_32_bits = dest & 0xffffffff;
      src = src & 0xffff;
      dest = low_32_bits / src;
      break;
    case 32:
      dest = dest / src;
      break;
    default:
      break;
  }
	return dest;
}

uint32_t alu_mod(uint64_t src, uint64_t dest) {
	uint64_t result = dest % src;
	return result;
}

int32_t alu_imod(int64_t src, int64_t dest) {
	uint64_t result = dest % src;
	return result;
}

uint32_t alu_and(uint32_t src, uint32_t dest) {
  uint32_t result = src & dest;
  set_PF(result);
  set_SF(result);
  set_ZF(result);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
	return result;
}

uint32_t alu_xor(uint32_t src, uint32_t dest) {
  uint32_t result = src ^ dest;
  set_PF(result);
  set_SF(result);
  set_ZF(result);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
	return result;
}

uint32_t alu_or(uint32_t src, uint32_t dest) {
  uint32_t result = src | dest;
  set_PF(result);
  set_SF(result);
  set_ZF(result);
  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
	return result;
}

uint32_t alu_shl(uint32_t src, uint32_t dest, size_t data_size) {
	uint32_t result = dest;
  if(src<0) return dest;
  switch(data_size){
    case 8:
    result = (dest & 0xff) << 24;
    dest = (dest & 0xffffff00) | ((dest << src) & 0xff);
    break;
    case 16: 
    result = (dest & 0xffff) << 16;
    dest = (dest & 0xffff0000) | ((dest << src) & 0xffff);
    break;
    default:
    dest = dest << src;
    break;
  }
  if(src == 0){
    set_PF(dest);
    set_SF(result);
    set_ZF(result);
  } else {
    result <<= src-1;
    uint32_t CF_flag = (result & 0x80000000) >> 31;
    result <<= 1;
    uint32_t OF_flag = (result & 0x80000000) >> 31;
    cpu.eflags.CF = CF_flag;
    if(src==1){
      cpu.eflags.OF = OF_flag == CF_flag ? 0:1;
    }
    set_PF(dest);
    set_SF(result);
    set_ZF(result);
  }
	return dest;
}

uint32_t alu_sal(uint32_t src, uint32_t dest, size_t data_size) {
	return alu_shl(src, dest, data_size);
}

uint32_t alu_shr(uint32_t src, uint32_t dest, size_t data_size) {
	uint32_t result = dest;
  uint32_t OF_flag = 0;
  uint32_t CF_flag = 0;
  if(src<0) return dest;
  switch(data_size){
    case 8:
    result = dest & 0xffffff00;
    uint8_t low_8_bits = dest & 0xff;
    OF_flag = low_8_bits >> 7;
    if(src > 0){
      low_8_bits >>= (src-1);
      CF_flag = low_8_bits & 0x1;
      low_8_bits >>= 1;
      dest = result | low_8_bits;
    }
    set_SF(low_8_bits);
    set_ZF(low_8_bits);
    break;
    case 16: 
    result = dest & 0xffff0000;
    uint16_t low_16_bits = dest & 0xffff;
    OF_flag = low_16_bits >> 15;
    if(src > 0){
      low_16_bits >>= (src-1);
      CF_flag = low_16_bits & 0x1;
      low_16_bits >>= 1;
      dest = result | low_16_bits;
    }
    set_SF(low_16_bits);
    set_ZF(low_16_bits);;
    break;
    default:
    OF_flag = dest >> 31;
    if(src > 0){
      CF_flag = (dest >> (src-1)) & 0x1;
      dest = dest >> src;
    }
    set_SF(dest);
    set_ZF(dest);
    break;
  }
  if(src == 1){
    cpu.eflags.OF = OF_flag;
  }
  cpu.eflags.CF = CF_flag;
  set_PF(dest);
	return dest;
}

uint32_t alu_sar(uint32_t src, uint32_t dest, size_t data_size) {
	uint32_t result = dest;
  uint32_t CF_flag = 0;
  uint32_t sign_bit = 0;
  if(src<0) return dest;
  switch(data_size){
    case 8:
    result = dest & 0xffffff00;
    uint32_t low_8_bits = dest & 0xff;
    sign_bit = low_8_bits & 0x80;
    if(src > 0){
      for(int i=0; i<src; i++){
        CF_flag = low_8_bits & 0x1;
        low_8_bits >>= 1;
        low_8_bits = low_8_bits | sign_bit;
      }
      dest = result | low_8_bits;
    }
    set_SF(low_8_bits << 24);
    set_ZF(low_8_bits);
    break;
    case 16: 
    result = dest & 0xffff0000;
    uint32_t low_16_bits = dest & 0xffff;
    sign_bit = low_16_bits & 0x8000;
    if(src > 0){
      for(int i=0; i<src; i++){
        CF_flag = low_16_bits & 0x1;
        low_16_bits >>= 1;
        low_16_bits = low_16_bits | sign_bit;
      }
      dest = result | low_16_bits;
    }
    set_SF(low_16_bits << 16);
    set_ZF(low_16_bits);;
    break;
    default:
    sign_bit = dest & 0x80000000;
    if(src > 0){
      for(int i=0; i<src; i++){
        CF_flag = dest & 0x1;
        dest >>= 1;
        dest = dest | sign_bit;
      }
    }
    set_SF(dest);
    set_ZF(dest);
    break;
  }
  cpu.eflags.OF = 0;
  cpu.eflags.CF = CF_flag;
  set_PF(dest);
	return dest;
}

*/

void set_CF_add(uint32_t result, uint32_t src)
{
  cpu.eflags.CF = result < src;
  return;
}

void set_CF_adc(uint32_t result, uint32_t src, uint32_t dest)
{
  if (!cpu.eflags.CF)
    set_CF_add(result, src);
  else
  {
    if (result <= src || result <= dest)
      cpu.eflags.CF = 1;
    else
      cpu.eflags.CF = 0;
  }
  return;
}

void set_PF(uint32_t result)
{
  uint32_t res_low_8_bits = result & 0xff;
  uint32_t num_1_low_8_bits = 0;
  for (int i = 0; i < 8; i++)
  {
    num_1_low_8_bits += res_low_8_bits & 0x1;
    res_low_8_bits >>= 1;
  }
  cpu.eflags.PF = !(num_1_low_8_bits % 2);
  return;
}

void set_ZF(uint32_t result)
{
  cpu.eflags.ZF = (result == 0);
  return;
}

void set_SF(uint32_t result)
{
  cpu.eflags.SF = sign(result);
  return;
}

void set_OF_add(uint32_t result, uint32_t src, uint32_t dest)
{
  if (sign(src) == sign(dest))
  {
    if (sign(src) != sign(result))
      cpu.eflags.OF = 1;
    else
      cpu.eflags.OF = 0;
  }
  else
  {
    cpu.eflags.OF = 0;
  }
  return;
}

uint32_t alu_add(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = src + dest;

  set_CF_add(res, src);
  set_PF(res);
  set_ZF(res);
  set_SF(res);
  set_OF_add(res, src, dest);
  return res;
}

uint32_t alu_adc(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = src + dest + cpu.eflags.CF;

  set_PF(res);
  set_ZF(res);
  set_SF(res);
  set_OF_add(res, src, dest);
  set_CF_adc(res, src, dest);
  return res;
}

void set_CF_sub(uint32_t result, uint32_t dest)
{
  cpu.eflags.CF = dest < result;
  return;
}

void set_OF_sub(uint32_t result, uint32_t src, uint32_t dest)
{
  uint32_t src_CF_neg = ~(src + 1) + 1;
  set_OF_add(result, src_CF_neg, dest);
  return;
}

void set_CF_sbb(uint32_t result, uint32_t src, uint32_t dest)
{
  if (!cpu.eflags.CF)
    set_CF_sub(result, dest);
  else
  {
    if (result >= dest)
      cpu.eflags.CF = 1;
    else
      cpu.eflags.CF = 0;
  }
  return;
}

uint32_t alu_sub(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = dest - src;

  set_PF(res);
  set_ZF(res);
  set_SF(res);
  set_CF_sub(res, dest);
  set_OF_sub(res, src, dest);
  return res;
}

uint32_t alu_sbb(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = dest - (src + cpu.eflags.CF);

  set_PF(res);
  set_ZF(res);
  set_SF(res);
  set_OF_sub(res, src, dest);
  set_CF_sbb(res, src, dest);
  return res;
}

uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint64_t res = 0;
  res = (uint64_t)src * (uint64_t)dest;
  //printf("src:%u\tdest:%u\tdata_size:%u\nresult:%llu\n", src, dest, data_size, res);
  if (data_size == 8)
  {
    uint8_t res_high_8_bits = (res & 0xff00) >> 8;
    if (res_high_8_bits)
    {
      cpu.eflags.CF = 1;
      cpu.eflags.OF = 1;
    }
    else
    {
      cpu.eflags.CF = 0;
      cpu.eflags.OF = 0;
    }
  }
  else if (data_size == 16)
  {
    uint16_t res_high_16_bits = (res & 0xffff0000) >> 16;
    if (res_high_16_bits)
    {
      cpu.eflags.CF = 1;
      cpu.eflags.OF = 1;
    }
    else
    {
      cpu.eflags.CF = 0;
      cpu.eflags.OF = 0;
    }
  }
  else
  {
    uint32_t res_high_32_bits = (res & 0xffffffff00000000) >> 32;
    //printf("res:%llx\tres_high_32_bits:%x\n", res, res_high_32_bits);
    if (res_high_32_bits)
    {
      cpu.eflags.CF = 1;
      cpu.eflags.OF = 1;
    }
    else
    {
      cpu.eflags.CF = 0;
      cpu.eflags.OF = 0;
    }
  }
  return res;
}

int64_t alu_imul(int32_t src, int32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  int64_t res = 0;
  res = (int64_t)src * (int64_t)dest;
  return res;
}

uint32_t alu_div(uint64_t src, uint64_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = dest / src;
  return res;
}

int32_t alu_idiv(int64_t src, int64_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  int32_t res = 0;
  res = dest / src;
  return res;
}

uint32_t alu_mod(uint64_t src, uint64_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = dest % src;
  return res;
}

int32_t alu_imod(int64_t src, int64_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  int32_t res = 0;
  res = dest % src;
  return res;
}

uint32_t alu_and(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = src & dest;

  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
  set_PF(res);
  set_SF(res);
  set_ZF(res);
  return res;
}

uint32_t alu_xor(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = src ^ dest;

  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
  set_PF(res);
  set_SF(res);
  set_ZF(res);
  return res;
}

uint32_t alu_or(uint32_t src, uint32_t dest)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  res = src | dest;

  cpu.eflags.CF = 0;
  cpu.eflags.OF = 0;
  set_PF(res);
  set_SF(res);
  set_ZF(res);
  return res;
}

uint32_t alu_shl(uint32_t src, uint32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res = 0;
  if (src == 0)
  {
    if (data_size == 8)
    {
      res = (dest & 0xff) << 24;
    }
    else if (data_size == 16)
    {
      res = (dest & 0xffff) << 16;
    }
    else
    {
      res = dest;
    }
    set_PF(dest);
    set_SF(res);
    set_ZF(res);
    return dest;
  }
  if (data_size == 8)
  {
    uint8_t dest_low_8_bits = dest & 0xff;
    dest_low_8_bits <<= src - 1;
    uint8_t CF_flag = (dest_low_8_bits & 0x80) >> 7;
    dest_low_8_bits <<= 1;
    uint8_t OF_flag = (dest_low_8_bits & 0x80) >> 7;
    res = dest_low_8_bits << 24;
    dest = dest & 0xffffff00;
    dest = dest | dest_low_8_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else if (data_size == 16)
  {
    uint16_t dest_low_16_bits = dest & 0xffff;
    dest_low_16_bits <<= src - 1;
    uint16_t CF_flag = (dest_low_16_bits & 0x8000) >> 15;
    dest_low_16_bits <<= 1;
    uint16_t OF_flag = (dest_low_16_bits & 0x8000) >> 15;
    dest = dest & 0xffff0000;
    res = dest_low_16_bits << 16;
    dest = dest | dest_low_16_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else
  {
    dest <<= src - 1;
    uint32_t CF_flag = (dest & 0x80000000) >> 31;
    dest <<= 1;
    uint32_t OF_flag = (dest & 0x80000000) >> 31;
    res = dest;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  set_PF(dest);
  set_SF(res);
  set_ZF(res);
  return dest;
}

uint32_t alu_shr(uint32_t src, uint32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res;
  if (src == 0)
  {
    if (data_size == 8)
    {
      res = (dest & 0xff) << 24;
    }
    else if (data_size == 16)
    {
      res = (dest & 0xffff) << 16;
    }
    else
    {
      res = dest;
    }
    set_PF(dest);
    set_SF(res);
    set_ZF(res);
    return dest;
  }
  if (data_size == 8)
  {
    uint8_t dest_low_8_bits = dest & 0xff;
    dest_low_8_bits >>= src - 1;
    uint8_t CF_flag = dest_low_8_bits & 0x1;
    dest_low_8_bits >>= 1;
    uint8_t OF_flag = dest_low_8_bits & 0x1;
    res = dest_low_8_bits << 24;
    dest = dest & 0xffffff00;
    dest = dest | dest_low_8_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else if (data_size == 16)
  {
    uint16_t dest_low_16_bits = dest & 0xffff;
    dest_low_16_bits >>= src - 1;
    uint16_t CF_flag = dest_low_16_bits & 0x1;
    dest_low_16_bits >>= 1;
    uint16_t OF_flag = dest_low_16_bits & 0x1;
    res = dest_low_16_bits << 16;
    dest = dest & 0xffff0000;
    dest = dest | dest_low_16_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else
  {
    dest >>= src - 1;
    uint32_t CF_flag = dest & 0x1;
    dest >>= 1;
    uint32_t OF_flag = dest & 0x1;
    res = dest;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  set_PF(dest);
  set_SF(res);
  set_ZF(res);
  return dest;
}

uint32_t alu_sar(uint32_t src, uint32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  uint32_t res;
  if (src == 0)
  {
    if (data_size == 8)
    {
      res = (dest & 0xff) << 24;
    }
    else if (data_size == 16)
    {
      res = (dest & 0xffff) << 16;
    }
    else
    {
      res = dest;
    }
    set_PF(dest);
    set_SF(res);
    set_ZF(res);
    return dest;
  }
  if (data_size == 8)
  {
    uint8_t dest_low_8_bits = dest & 0xff;
    dest_low_8_bits = (int8_t)dest_low_8_bits >> (src - 1);
    uint8_t CF_flag = dest_low_8_bits & 0x1;
    dest_low_8_bits = (int8_t)dest_low_8_bits >> 1;
    uint8_t OF_flag = dest_low_8_bits & 0x1;
    res = dest_low_8_bits << 24;
    dest = dest & 0xffffff00;
    dest = dest | dest_low_8_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else if (data_size == 16)
  {
    uint16_t dest_low_16_bits = dest & 0xffff;
    dest_low_16_bits = (int16_t)dest_low_16_bits >> (src - 1);
    uint16_t CF_flag = dest_low_16_bits & 0x1;
    dest_low_16_bits = (int16_t)dest_low_16_bits >> 1;
    uint16_t OF_flag = dest_low_16_bits & 0x1;
    res = dest_low_16_bits << 16;
    dest = dest & 0xffff0000;
    dest = dest | dest_low_16_bits;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  else
  {
    dest = (int32_t)dest >> (src - 1);
    uint32_t CF_flag = dest & 0x1;
    dest = (int32_t)dest >> 1;
    uint32_t OF_flag = dest & 0x1;
    res = dest;

    cpu.eflags.CF = CF_flag;
    if (src == 1)
      cpu.eflags.OF = CF_flag != OF_flag;
  }
  set_PF(dest);
  set_SF(res);
  set_ZF(res);
  return dest;
}

uint32_t alu_sal(uint32_t src, uint32_t dest, size_t data_size)
{
  /*printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);*/
  return alu_shl(src, dest, data_size);
}

#include "cpu/instr.h"

static void instr_execute_1op_cc_pass() {
	operand_read(&opr_src);
	cpu.eip += sign_ext(opr_src.val, opr_src.data_size);
}

static void instr_execute_1op_cc_fail() {/* Do nothing */}

#define jcc_helper(suffix) \
	make_instr_impl_1op_cc(j, i, suffix, e) \
	make_instr_impl_1op_cc(j, i, suffix, a) \
	make_instr_impl_1op_cc(j, i, suffix, b) \
	make_instr_impl_1op_cc(j, i, suffix, g) \
	make_instr_impl_1op_cc(j, i, suffix, l) \
	make_instr_impl_1op_cc(j, i, suffix, o) \
	make_instr_impl_1op_cc(j, i, suffix, p) \
	make_instr_impl_1op_cc(j, i, suffix, s) \
	make_instr_impl_1op_cc(j, i, suffix, ae) \
	make_instr_impl_1op_cc(j, i, suffix, ge) \
	make_instr_impl_1op_cc(j, i, suffix, le) \
	make_instr_impl_1op_cc(j, i, suffix, na) \
	make_instr_impl_1op_cc(j, i, suffix, ne) \
	make_instr_impl_1op_cc(j, i, suffix, no) \
	make_instr_impl_1op_cc(j, i, suffix, np) \
	make_instr_impl_1op_cc(j, i, suffix, ns) \

jcc_helper(near)
jcc_helper(short_)
make_instr_impl_1op_cc(j, i, short_, ecxz);

make_instr_impl_1op_cc(j, i, v, be);
make_instr_impl_1op_cc(j, i, v, l);
make_instr_impl_1op_cc(j, i, v, le);
make_instr_impl_1op_cc(j, i, v, e);
make_instr_impl_1op_cc(j, i, v, ne);
make_instr_impl_1op_cc(j, i, v, a);
make_instr_impl_1op_cc(j, i, v, s);
make_instr_impl_1op_cc(j, i, v, ns);
make_instr_impl_1op_cc(j, i, v, p);
make_instr_impl_1op_cc(j, i, v, np);
make_instr_impl_1op_cc(j, i, v, ge);
make_instr_impl_1op_cc(j, i, v, g);
make_instr_impl_1op_cc(j, i, v, o);
make_instr_impl_1op_cc(j, i, v, no);
make_instr_impl_1op_cc(j, i, v, b);
make_instr_impl_1op_cc(j, i, v, ae);

// make_instr_impl_1op_cc(j, i, b, a);
make_instr_impl_1op_cc(j, i, b, be);
make_instr_impl_1op_cc(j, i, b, l);
make_instr_impl_1op_cc(j, i, b, le);
make_instr_impl_1op_cc(j, i, b, e);
make_instr_impl_1op_cc(j, i, b, ne);
make_instr_impl_1op_cc(j, i, b, s);
make_instr_impl_1op_cc(j, i, b, ns);
make_instr_impl_1op_cc(j, i, b, p);
make_instr_impl_1op_cc(j, i, b, np);
make_instr_impl_1op_cc(j, i, b, ge);
make_instr_impl_1op_cc(j, i, b, g);
make_instr_impl_1op_cc(j, i, b, o);
make_instr_impl_1op_cc(j, i, b, no);
make_instr_impl_1op_cc(j, i, b, b);
make_instr_impl_1op_cc(j, i, b, ae);

/*
make_instr_func(ja_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("ja", "", len, &imm);

	if (cpu.eflags.CF == 0 && cpu.eflags.OF == 0)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(je_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;
	
	print_asm_1("je", "", len, &imm);

	if (cpu.eflags.ZF == 1)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(jge_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("jge", "", len, &imm);

	if (cpu.eflags.SF == cpu.eflags.OF)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(jnle_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("jnle", "", len, &imm);

	if (cpu.eflags.ZF == 0 && cpu.eflags.SF == cpu.eflags.OF)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(jle_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("jle", "", len, &imm);

	if (cpu.eflags.ZF == 1 || cpu.eflags.SF != cpu.eflags.OF)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(jne_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("jne", "", len, &imm);

	if (cpu.eflags.ZF == 0)
		len += (int8_t)imm.val;

	return len;
}

make_instr_func(jbe_b)
{
	OPERAND imm;
	int len = 1;

	imm.type = OPR_IMM;
	imm.data_size = 8;
	imm.addr = eip + 1;
	operand_read(&imm);

	len += 1;

	print_asm_1("jbe", "", len, &imm);

	if (cpu.eflags.CF == 1 || cpu.eflags.ZF == 1)
		len += (int8_t)imm.val;

	return len;
}

*/
Dump of assembler code for function main:
   0x00030030 <+0>:	55	push   %ebp
   0x00030031 <+1>:	89 e5	mov    %esp,%ebp
   0x00030033 <+3>:	53	push   %ebx
   0x00030034 <+4>:	83 ec 10	sub    $0x10,%esp
   0x00030037 <+7>:	e8 83 00 00 00	call   0x300bf <__x86.get_pc_thunk.bx>
   0x0003003c <+12>:	81 c3 c4 1f 00 00	add    $0x1fc4,%ebx
   0x00030042 <+18>:	c7 45 f0 00 00 00 00	movl   $0x0,-0x10(%ebp)
   0x00030049 <+25>:	c7 45 f8 00 00 00 00	movl   $0x0,-0x8(%ebp)
   0x00030050 <+32>:	eb 51	jmp    0x300a3 <main+115>
   0x00030052 <+34>:	c7 45 f4 00 00 00 00	movl   $0x0,-0xc(%ebp)
   0x00030059 <+41>:	eb 3d	jmp    0x30098 <main+104>
   0x0003005b <+43>:	8b 45 f4	mov    -0xc(%ebp),%eax
   0x0003005e <+46>:	8b 94 83 20 00 00 00	mov    0x20(%ebx,%eax,4),%edx
   0x00030065 <+53>:	8b 45 f8	mov    -0x8(%ebp),%eax
   0x00030068 <+56>:	8b 84 83 20 00 00 00	mov    0x20(%ebx,%eax,4),%eax
   0x0003006f <+63>:	52	push   %edx
   0x00030070 <+64>:	50	push   %eax
   0x00030071 <+65>:	e8 8f ff ff ff	call   0x30005 <max>
   0x00030076 <+70>:	83 c4 08	add    $0x8,%esp
   0x00030079 <+73>:	89 c1	mov    %eax,%ecx
   0x0003007b <+75>:	8b 45 f0	mov    -0x10(%ebp),%eax
   0x0003007e <+78>:	8d 50 01	lea    0x1(%eax),%edx
   0x00030081 <+81>:	89 55 f0	mov    %edx,-0x10(%ebp)
   0x00030084 <+84>:	8b 84 83 40 00 00 00	mov    0x40(%ebx,%eax,4),%eax
   0x0003008b <+91>:	39 c1	cmp    %eax,%ecx
   0x0003008d <+93>:	74 06	je     0x30095 <main+101>
   0x0003008f <+95>:	b8 01 00 00 00	mov    $0x1,%eax
   0x00030094 <+100>:	82	(bad)  
   0x00030095 <+101>:	ff 45 f4	incl   -0xc(%ebp)
   0x00030098 <+104>:	8b 45 f4	mov    -0xc(%ebp),%eax
   0x0003009b <+107>:	83 f8 07	cmp    $0x7,%eax
   0x0003009e <+110>:	76 bb	jbe    0x3005b <main+43>
   0x000300a0 <+112>:	ff 45 f8	incl   -0x8(%ebp)
   0x000300a3 <+115>:	8b 45 f8	mov    -0x8(%ebp),%eax
   0x000300a6 <+118>:	83 f8 07	cmp    $0x7,%eax
   0x000300a9 <+121>:	76 a7	jbe    0x30052 <main+34>
   0x000300ab <+123>:	b8 00 00 00 00	mov    $0x0,%eax
   0x000300b0 <+128>:	82	(bad)  
   0x000300b1 <+129>:	b8 00 00 00 00	mov    $0x0,%eax
   0x000300b6 <+134>:	8b 5d fc	mov    -0x4(%ebp),%ebx
   0x000300b9 <+137>:	c9	leave  
   0x000300ba <+138>:	c3	ret    
End of assembler dump.
Dump of assembler code for function max:
   0x00030005 <+0>:	55	push   %ebp
   0x00030006 <+1>:	89 e5	mov    %esp,%ebp
   0x00030008 <+3>:	83 ec 10	sub    $0x10,%esp
   0x0003000b <+6>:	e8 ab 00 00 00	call   0x300bb <__x86.get_pc_thunk.ax>
   0x00030010 <+11>:	05 f0 1f 00 00	add    $0x1ff0,%eax
   0x00030015 <+16>:	8b 45 08	mov    0x8(%ebp),%eax
   0x00030018 <+19>:	3b 45 0c	cmp    0xc(%ebp),%eax
   0x0003001b <+22>:	7e 08	jle    0x30025 <max+32>
   0x0003001d <+24>:	8b 45 08	mov    0x8(%ebp),%eax
   0x00030020 <+27>:	89 45 fc	mov    %eax,-0x4(%ebp)
   0x00030023 <+30>:	eb 06	jmp    0x3002b <max+38>
   0x00030025 <+32>:	8b 45 0c	mov    0xc(%ebp),%eax
   0x00030028 <+35>:	89 45 fc	mov    %eax,-0x4(%ebp)
   0x0003002b <+38>:	8b 45 fc	mov    -0x4(%ebp),%eax
   0x0003002e <+41>:	c9	leave  
   0x0003002f <+42>:	c3	ret    
End of assembler dump.
#ifndef PARSER_H_
#define PARSER_H_
#include <string>

/*
valores de 0 a 100 sao de transicao normal da tabela direta
valores de 100 a 200 sao de shift
valores de 200 a 300 sao de reduce
500 acc
*/





const int PARSER_TRANSITION_TABLE[77][44] = {
/*  
    inicio	varinicio	varfim	pt_v	id	vir	inteiro	real	literal	leia	escreva	lit	num	rcb	opm	se	ab_p	fc_p	opr	fimse	repita	fimrepita	varfim	então	fim	$	P	V	A	LV	D	TIPO	L	ES	ARG	CMD	LD	OPRD	COND	CAB	CP	EXP_R	R	CABR	CPR
       0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43 */
    {102, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,500, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1,104, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1,116, -1,117, -1, -1, -1,  5, -1, -1, -1, -1,  6, -1,  9, -1, -1, 11, 12, -1, -1, 14, 15, -1},
    { -1, -1,124, -1, -1, -1,121,122,123, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 18, 19, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,202, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1,116, -1,117, -1, -1, -1, 25, -1, -1, -1, -1,  6, -1,  9, -1, -1, 11, 12, -1, -1, 14, 15, -1},
    { -1, -1, -1, -1,126, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,130, -1, -1, -1, -1, -1, -1,128,129, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1,116, -1,117, -1, -1, -1, 31, -1, -1, -1, -1,  6, -1,  9, -1, -1, 11, 12, -1, -1, 14, 15, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,132, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1,116, -1,117, -1, -1, -1, 33, -1, -1, -1, -1,  6, -1,  9, -1, -1, 11, 12, -1, -1, 14, 15, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,138, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, 36, -1, -1, 37, 12, 34, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,139, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1,116, -1,117, -1, -1, -1, 40, -1, -1, -1, -1,  6, -1,  9, -1, -1, 11, 12, -1, -1, 14, 15, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1, -1, -1,145, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, 43, -1, -1, 44, 12, -1, -1, -1, -1, 41},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,146, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,239, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,203, -1, -1, -1, -1,203,203, -1, -1, -1, -1,203, -1, -1, -1, -1, -1,203, -1,203, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1,124, -1, -1, -1,121,122,123, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 19, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,149, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 48, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,209, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,210, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,211, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,150, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,212, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,151, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,152, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,215, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,216, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,217, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,218, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,155, -1, -1, -1, -1, -1, -1, -1,156, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 53, 54, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,224, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,225, -1, -1, -1, -1,225,225, -1, -1, -1, -1,225, -1, -1, -1, -1,225,225,225,225, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,138, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, 36, -1, -1, 37, 12, 57, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,138, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, 36, -1, -1, 37, 12, 58, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,138, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, 36, -1, -1, 37, 12, 59, -1, -1, -1, -1},
    { -1, -1, -1, -1,231, -1, -1, -1, -1,231,231, -1, -1, -1, -1,231, -1, -1, -1, -1,231,231,231,231, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,155, -1, -1, -1, -1, -1, -1, -1,156, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 61, -1, -1, -1, 60, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,232, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,233, -1, -1, -1, -1,233,233, -1, -1, -1, -1,233, -1, -1, -1, -1, -1,233, -1,233, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,145, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, 43, -1, -1, 44, 12, -1, -1, -1, -1, 62},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,145, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, 43, -1, -1, 44, 12, -1, -1, -1, -1, 63},
    { -1, -1, -1, -1,110, -1, -1, -1, -1,107,108, -1, -1, -1, -1,113, -1, -1, -1, -1,145, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, 43, -1, -1, 44, 12, -1, -1, -1, -1, 64},
    { -1, -1, -1, -1,238, -1, -1, -1, -1,238,238, -1, -1, -1, -1,238, -1, -1, -1, -1, -1,238, -1,238, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,155, -1, -1, -1, -1, -1, -1, -1,156, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 61, -1, -1, -1, 65, -1, -1, -1},
    { -1, -1, -1, -1,204, -1, -1, -1, -1,204,204, -1, -1, -1, -1,204, -1, -1, -1, -1, -1,204, -1,204, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,166, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,208, -1,167, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,205, -1, -1, -1, -1,205,205, -1, -1, -1, -1,205, -1, -1, -1, -1, -1,205, -1,205, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,213, -1, -1, -1, -1,213,213, -1, -1, -1, -1,213, -1, -1, -1, -1,213,213,213,213, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,214, -1, -1, -1, -1,214,214, -1, -1, -1, -1,214, -1, -1, -1, -1,214,214,214,214, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,168, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,221, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,169, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,222, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,222, -1, -1,222, -1,222, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,223, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,223, -1, -1,223, -1,223, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,228, -1, -1, -1, -1,228,228, -1, -1, -1, -1,228, -1, -1, -1, -1,228,228,228,228, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,229, -1, -1, -1, -1,229,229, -1, -1, -1, -1,229, -1, -1, -1, -1,229,229,229,229, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,230, -1, -1, -1, -1,230,230, -1, -1, -1, -1,230, -1, -1, -1, -1,230,230,230,230, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,170, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,171, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,235, -1, -1, -1, -1,235,235, -1, -1, -1, -1,235, -1, -1, -1, -1, -1,235, -1,235, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,236, -1, -1, -1, -1,236,236, -1, -1, -1, -1,236, -1, -1, -1, -1, -1,236, -1,236, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,237, -1, -1, -1, -1,237,237, -1, -1, -1, -1,237, -1, -1, -1, -1, -1,237, -1,237, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,172, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1,206, -1, -1, -1,206,206,206, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,149, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 73, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,219, -1, -1, -1, -1,219,219, -1, -1, -1, -1,219, -1, -1, -1, -1,219,219,219,219, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,155, -1, -1, -1, -1, -1, -1, -1,156, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 74, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,175, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,155, -1, -1, -1, -1, -1, -1, -1,156, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 76, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,234, -1, -1, -1, -1,234,234, -1, -1, -1, -1,234, -1, -1, -1, -1, -1, -1,234, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,207, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1,220, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1,226, -1, -1, -1, -1,226,226, -1, -1, -1, -1,226, -1, -1, -1, -1,226, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,227, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
}; 


#endif                                         
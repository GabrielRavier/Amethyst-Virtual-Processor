// Programmed with luv.. ~~kernels ♥♥♥

#include <stdio.h>
#include "08interpreter.h"

int registers[6];

int PRGMMEM[10];
int PRGMMEMSIZE = sizeof(PRGMMEM) / sizeof(int);

int PIA = 0;

int DF = 0;

int main()
{
	for (; PIA < PRGMMEMSIZE;)
	{
		int instruction_size = 0;

		if (instr >= 0 && instr <= 2)
		{
			instruction_size = 1;
		}
		else if (instr >= 3 && instr <= 18)
		{
			instruction_size = 2;
		}
		else if (instr >= 19 && instr <= 21)
		{
			instruction_size = 3;
		}
		else if (instr >= 22 && instr <= 38)
		{
			instruction_size = 4;
		}
		else
		{
			// ERROR
		}

		// Massive switch block aaa
		switch (instr)
		{
		case 0: // NOP
			goto EXECUTION_FINISHED;

		case  1: // RET
			PIA = arg1;
			continue;

		case  2: // NOT
			acc = ~acc;
			goto EXECUTION_FINISHED;

		case  3: // JMPl
			PIA = arg1;
			continue;
		case  4: // SLPi
			// Implentation independant
			goto EXECUTION_FINISHED;
		case  5: //SDFb 
			DF = arg1;
			goto EXECUTION_FINISHED;
		case  6: // ADDi 
			acc = acc + arg1;
			goto EXECUTION_FINISHED;
		case  7: //ADDr 
			acc = acc + REG[arg1];
			goto EXECUTION_FINISHED;
		case  8: // SUBi 
			acc = acc - arg1;
			goto EXECUTION_FINISHED;
		case  9: // SUBr 
			acc = acc - REG[arg1];
			goto EXECUTION_FINISHED;
		case 10: // ANDi 
			acc = acc & arg1;
			goto EXECUTION_FINISHED;
		case 11: // ANDr 
			acc = acc & REG[arg1];
			goto EXECUTION_FINISHED;
		case 12: // ORRi 
			acc = acc | arg1;
			goto EXECUTION_FINISHED;
		case 13: // ORRr 
			acc = acc | REG[arg1];
			goto EXECUTION_FINISHED;

		default:
			break;
		}

		EXECUTION_FINISHED:


	}

    return 0;
}


// Programmed with luv.. ~~kernels ♥♥♥

#define DEBUG 1
#define RELEASE 0




#include <stdio.h>
#include "08interpreter.h"

int registers[6];

int PRGMMEM[10];
int PRGMMEMSIZE = sizeof(PRGMMEM) / sizeof(int);

int ProgramIndexAddress = 0; // DEFINED as PIA

int DefinedFlag = 0; // DEFINED as DF

int main()
{
	for (; PIA < PRGMMEMSIZE;)
	{
		int instruction_size = 0; // DEFINED AS INST_SIZE

		if (instr >= 0 && instr <= 2)
		{
			INST_SIZE = 1;
		}
		else if (instr >= 3 && instr <= 18)
		{
			INST_SIZE = 2;
		}
		else if (instr >= 19 && instr <= 22)
		{
			INST_SIZE = 3;
		}
		else if (instr >= 23 && instr <= 34)
		{
			INST_SIZE = 4;
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

		case 14: // XORi 
			acc = acc ^ arg1;
			goto EXECUTION_FINISHED;

		case 15: // XORr 
			acc = acc ^ REG[arg1];
			goto EXECUTION_FINISHED;

		case 16: // LSFi
			acc = acc << arg1;
			goto EXECUTION_FINISHED;

		case 17: // RSFi
			acc = acc >> arg1;
			goto EXECUTION_FINISHED;

		case 18: // CALLl
			idx = PIA + 2;
			PIA = arg1;
			continue;

		case 19: // MOVir
			REG[arg2] = arg1;
			goto EXECUTION_FINISHED;

		case 20: // MOVrr
			REG[arg2] = REG[arg1];
			goto EXECUTION_FINISHED;

		case 21: { // SWPrr
			int temp = REG[arg1];
			REG[arg1] = REG[arg2];
			REG[arg2] = temp;
			goto EXECUTION_FINISHED;

		case 22: // BDFb
			if (arg1 == DF)
			{
				PIA = arg2;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 23: // BEQii
			if (arg1 == arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 24: // BEQir
			if (arg1 == REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 25: // BEQri
			if (REG[arg1] == arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 26: // BEQrr
			if (REG[arg1] == REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 27: // BGTii
			if (arg1 > arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 28: // BGTir
			if (arg1 > REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 29: // BGTri
			if (REG[arg1] > arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 30: // BGTrr
			if (REG[arg1] > REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 31: // BLTii
			if (arg1 < arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 32: // BLTir
			if (arg1 < REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 33: // BLTri
			if (REG[arg1] < arg2)
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;

		case 34: // BLTrr
			if (REG[arg1] < REG[arg2])
			{
				PIA = arg3;
				continue;
			}
			goto EXECUTION_FINISHED;
		default:
			// 
			break;
		}

	}
	EXECUTION_FINISHED:

		PIA += INST_SIZE;


		Update();
	}

    return 0;
}

// Update GUI, whichever. IDK what this routine should do.
void Update()
{
	// 
}
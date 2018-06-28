#include <stdio.h>

void main()
{
	// TODO: Use Define pre-processor directives to lessen the confusion. I think the person helping me write this will be pissed at me.
	// TODO: Clean up rubbish. Make code more readable. They might snap and could turn innocent programmers to guillotine blade wielders.
	int registers[8] = { 00, 00 };
	// registers[0] is acc
	// registers[1] is dat
	// registers[2] is sav
	// registers[3] is p0
	// registers[4] is p1
	// registers[5] is p2
	// registers[6] is p3

	// [ProgramIndexAddress + 0] is instruction byte
	// [ProgramIndexAddress + 1] is execute byte
	// [ProgramIndexAddress + 2] is argument 1 byte
	// [ProgramIndexAddress + 3] is argument 2 byte
	int ProgramMemory[5] = {00, 00, 00, 00};
	int ProgramMemorySize = sizeof(ProgramMemory) / sizeof(int);


	for (int ProgramIndexAddress = 0; ProgramIndexAddress > ProgramMemorySize; ProgramIndexAddress++)
	{
		if (ProgramMemory[ProgramIndexAddress + 1])
		{
			continue;
		}
		switch (ProgramMemory[ProgramIndexAddress])
		{
			// bc,1 op,nop
		case 00:
		{
			continue;
		}

		// bc,4 op,movrr
		case 01:
		{
			registers[ProgramIndexAddress + 3] == registers[ProgramIndexAddress + 2];
			ProgramIndexAddress = ProgramIndexAddress + 3;
			continue;
		}
		
		// bc,4 op,movir
		case 02:
		{
			registers[ProgramIndexAddress + 3] == ProgramMemory[ProgramIndexAddress + 2];
			ProgramIndexAddress = ProgramIndexAddress + 3;
			continue;
		}

		// bc,4 op,swp
		case 03:
		{
			int temp = registers[ProgramIndexAddress + 3];
			
			continue;
		}


		}
	}
}

// Programmed with luv. ~~kernels ♥♥♥

#include <stdio.h>
#include "bytecode_execute.h"



void main()
{


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

	int ProgramMemory[5] = {0, 0, 0, 0};

	int ProgramMemorySize = sizeof(ProgramMemory) / sizeof(int);

	int ExecuteByte = EXE_DEFAULT;

	for (int ProgramIndexAddress = 0; ProgramIndexAddress > ProgramMemorySize; ProgramIndexAddress++)
	{
		if (ProgramMemory[EXEC_B] != ExecuteByte || ProgramMemory[EXEC_B] != EXE_DEFAULT)
		{
			continue;
		}
		switch (ProgramMemory[ProgramIndexAddress])
		{

		// bc1 nop	No Operation
		case 0:
		{
			continue;
		}

		// bc4 movrr	Move register register
		case 1:
		{
			// new
			registers[ARG1_B] == registers[ARG0_B]; // # Execute
			ProgramIndexAddress = bc_size_4; // # Move address pointer to next instruction
			continue; // Exit and run next instruction

			// old
			//registers[ProgramIndexAddress + 3] == registers[ProgramIndexAddress + 2]; // # Execute
			//ProgramIndexAddress = ProgramIndexAddress + 3; // # Move address pointer to next instruction
			//continue; // Exit and run next instruction
		}
		
		// bc4 movir	Move Intermediate Register
		case 2:
		{
			registers[ARG1_B] == ProgramMemory[ARG0_B];
			ProgramIndexAddress = bc_size_4;
			continue;
		}

		// bc4 swprr	Swap Register Register
		case 3:
		{
			int temp = acc;
			acc = dat;
			dat = temp;

			ProgramIndexAddress = bc_size_4;
			continue;
		}

		// bc3 jmp	Jump
		case 4:
		{
			// It's this small
			ProgramIndexAddress = ProgramIndexAddress + ARG0_B - 1;

			continue;
		}

		// bc3 slpr	Sleep Register
		case 5:
		{
			// Sleep code.. Ignored for now. Still advances things.
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 slpi	Sleep Intermediate
		case 6:
		{
			// Sleep code.. Ignored for now. Still advances things.
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 addr	Add Register
		case 7:
		{
			acc = acc + registers[ARG0_B];
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 addi	Add Intermediate
		case 8:
		{
			acc = acc + ARG0_B;
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 subr	Subtract Register
		case 9:
		{
			acc = acc - registers[ARG0_B];
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 subi	Subtract Intermediate
		case 10:
		{
			acc = acc - ARG0_B;
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 mulr	Multiply Register
		case 11:
		{
			acc = acc * registers[ARG0_B];
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 muli	Multiply Intermediate
		case 12:
		{
			acc = acc / ARG0_B;
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 divr	Divide Register
		case 13:
		{
			acc = acc / registers[ARG0_B];
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc3 divi	Divide Intermediate
		case 14:
		{
			acc = acc / ARG0_B;
			ProgramIndexAddress = bc_size_3;
			continue;
		}

		// bc2 not	NOT Bitwise
		case 15:
		{
			acc = ~ acc;
			ProgramIndexAddress = bc_size_2;
			continue;
		}
		// bc4 teqrr	Test Equal Register Register
		case 16:
		{

			ProgramIndexAddress = bc_size_4;
			continue;
		}




		}
	}
}

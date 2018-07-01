// Programmed with luv. ~~kernels ♥♥♥

// ===[Task List]=========
// DONE: Use Define pre-processor directives to lessen the confusion. I think the person helping me write this will be pissed at me.
// DONE: Clean up rubbish. Make code more readable. They might snap and could turn innocent programmers to guillotine blade wielders.
// TODO: Add the new instructions.
// DONE: Add the new registers.
// TODO: Finish the rest of the test instructions.
// TODO: Unit test each and every instruction.
// TODO: Initial Full Systems Test(FST). 
// TODO: Clean code.
// TODO: Comment almost every line.
// TODO: Add documentations on each instruction.
// TODO: Design the stack
// TODO: Make decisions you undecisive worrywart overthinker. If you keep doing this incompetentness rubbish, you'll never finish anything significant.

#include <stdio.h>

// Registers Define Directives
// ===========================

// Accumulator Register
#define acc registers[0]

// Data Register
#define dat registers[1]

// Save Register
#define sav registers[2]

// Top Level Stack Address
#define sta registers[3]

// Top Level Stack Data
#define std registers[4]

// General Purpose Index Address Register
#define idx registers[5]

// RAM Data Register. Read Only
#define rmd registers[6]

// RAM Address Register. Read Only
#define rma registers[7]

// Bytecode Boolean
// ================

#define B_TRUE 1
#define B_FALSE 0

// Bytecode Execute Boolean
// ================

#define EXE_DEFAULT 1
#define EXE_TRUE 2
#define EXE_FALSE 3

// Bytecode sequence idk whatever structure
// ========================================

// Instruction Byte
#define INSTR_B ProgramIndexAddress + 0

// Execute Byte
#define EXEC_B ProgramIndexAddress + 1

// Argument 0 Byte
#define ARG0_B ProgramIndexAddress + 2

// Argument 1 byte
#define ARG1_B ProgramIndexAddress + 3


// Bytecode size. (increment from for loop included so subtract one)
// =================================================================

// Bytecode size
#define bc_size_2 ProgramIndexAddress + 1;
// Bytecode size
#define bc_size_3 ProgramIndexAddress + 2;
// Bytecode size
#define bc_size_4 ProgramIndexAddress + 3;





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

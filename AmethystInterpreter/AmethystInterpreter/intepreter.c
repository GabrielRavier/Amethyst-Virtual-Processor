// Programmed with luv. ~~kernels ♥♥♥

#include <stdio.h>
#include "interpreter.h"

// Registers
int registers[9] = { 00, 00 };

// Main Program
int ProgramMemory[5] = { 0, 0, 0, 0, 0 };

// Initiate Stack

int StackAddress[9] = { 0,0,0,0,0,0,0,0 };                            // Stackpart.Addresses
int StackData[9] = { 0,0,0,0,0,0,0,0 };                               // Stackpart.Data
int TopLevelIndex = 0;                                                // TopLevelIndex

// Initiate RAM

int RAM[512];
int RAMCurrentAddr = 0;

				 													  // int ProgramMemorySize = sizeof(PRGMEM) / sizeof(int);
int ProgramMemorySize = sizeof(PRGMEM) / sizeof(int);

// Flags
// =====

// ExecuteBit
int ExecuteByte = EXE_DEFAULT;

// Defined Flag
int DefinedFlag = 0;

void main()
{
	for (int PIA = 0; PIA <= ProgramMemorySize; PIA++)
	{
		// Update ProgramCounter Register
		prc = PIA;

		switch (PRGMEM[ProgramIndexAddress])
		{

		// USELESS INSTRUCTION ================================================

		// nop
		case 0:
		{
			continue;
		}

		// MOVE INSTRUCTIONS ==================================================

		// mov rr
		case 1:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				registers[ARG1_B] = registers[ARG0_B]; // Execute
			}
			PIA = bc_size_4; continue; // Finish and move to next instruction
		}

		// mov ir
		case 2:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				registers[ARG1_B] = PRGMEM[ARG0_B];
			}
			PIA = bc_size_4; continue;
		}

		// RAM INSTRUCTIONS ===================================================

		// rmc r
		case 3:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				RAMCurrentAddr = registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// rmc i
		case 4:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				RAMCurrentAddr = PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// rmv r
		case 5:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				RAM[RAMCurrentAddr] = registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// rmv i
		case 6:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				RAM[RAMCurrentAddr] = PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// SWAP INSTRUCTION ===================================================

		// swp rr
		case 7:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				int temp = acc;
				acc = dat;
				dat = temp;
			}
			PIA = bc_size_4; continue;
		}

		// JUMP INSTRUCTIONS ==================================================

		// jmp l
		case 8:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PIA = PRGMEM[ARG0_B] - 1;
			}
			continue;
		}

		// jmp r
		case 9:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PIA = registers[ARG0_B - 1];
			}
			continue;
		}

		// SLEEP INSTRUCTIONS =================================================

		// slp r
		case 10:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{

			}
			// No logic for now. Skips.
			PIA = bc_size_3; continue;
		}

		// slp i
		case 11:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{

			}
			// No logic for now. Skips.
			PIA = bc_size_3; continue;
		}

		// EXECUTE BYTE INSTRUCTION ===========================================

		// exb b
		case 12:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				ExecuteByte = PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// ARITHMETHICC INSTRUCTIONS ==========================================

		// add r
		case 13:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc + registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// add i
		case 14:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc + PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// sub r
		case 15:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc - registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// sub i
		case 16:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc - PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// mul r
		case 17:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc * registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// mul i
		case 18:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc * PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// div r
		case 19:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc / registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// div i
		case 20:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc / PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// neg
		case 21:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = -acc;
			}
			PIA = bc_size_3; continue;
		}

		// BITWISE INSTRUCTIONS ===============================================

		// not
		case 22:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = ~acc;
			}
			PIA = bc_size_3; continue;
		}

		// and r
		case 23:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc & registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// and i
		case 24:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc & PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// orr r
		case 25:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc | registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// orr i
		case 26:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc | PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// xor r
		case 27:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc ^ registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// xor i
		case 28:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc ^ PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// BITWISE.SHIFT INSTRUCTIONS =========================================

		// lsf r
		case 29:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc << registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// lsf i
		case 30:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc << PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// rsf r
		case 31:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc >> registers[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// rsf i
		case 32:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				acc = acc >> PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		// STACK.PUSH INSTRUCTIONS ============================================

		// psh li
		case 33:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackAddressData(ARG0_B, PRGMEM[ARG1_B]);
			}
			PIA = bc_size_4; continue;
		}

		// psh lr
		case 34:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackAddressData(registers[ARG0_B], PRGMEM[ARG1_B]);
			}
			PIA = bc_size_4; continue;
		}

		// psh rr
		case 35:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackAddressData(registers[ARG0_B], registers[ARG1_B]);
			}
			PIA = bc_size_4; continue;
		}

		// psh ri
		case 36:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackAddressData(registers[ARG0_B], PRGMEM[ARG1_B]);
			}
			PIA = bc_size_4; continue;
		}

		// psh r
		case 37:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackData(registers[ARG0_B]);
			}
			PIA = bc_size_3; continue;
		}

		// psh i
		case 38:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PushStackData(PRGMEM[ARG0_B]);
			}
			PIA = bc_size_3; continue;
		}

		// STACK.POP INSTRUCTIONS =============================================

		// pop
		case 39:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PopStack();
			}
			PIA = bc_size_2; continue;
		}

		// CALL/RET INSTRUCTIONS ==============================================

		// call l
		case 40:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PIA = bc_size_3; // Skip to next instruction
				idx = PIA; // Store the ret location
				PIA = PRGMEM[ARG0_B] - 1; // Jump
			}
		}

		// ret
		case 41:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				PIA = idx - 1;
			}
			continue;
		}

		// TEST EQUAL INSTRUCTIONS ============================================

		// teq rr
		case 42:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] == registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// teq ri
		case 43:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] == PRGMEM[ARG0_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// teq ir
		case 44:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] == registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// teq ii
		case 45:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] == PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// TEST GREATER THAN INSTRUCTIONS =====================================

		// tgt rr
		case 46:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] > registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tgt ri
		case 47:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] > PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tgt ir
		case 48:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] > registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tgt ii
		case 49:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] > PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}
		// TEST LESS THAN INSTRUCTIONS ========================================

		// tlt rr
		case 50:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] < registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tlt ri
		case 51:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] < PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tlt ir
		case 52:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] < registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tlt ii
		case 53:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] < PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// AUXILLERY TEST INSTRUCTIONS ========================================

		// tcp rr
		case 54:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] > registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
				if (registers[ARG0_B] == registers[ARG1_B])
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tcp ri
		case 55:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (registers[ARG0_B] > PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
				if (registers[ARG0_B] == PRGMEM[ARG1_B])
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tcp ir
		case 56:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] > registers[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
				if (PRGMEM[ARG0_B] == registers[ARG1_B])
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}

		// tcp ii
		case 57:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] > PRGMEM[ARG1_B])
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
				if (PRGMEM[ARG0_B] == PRGMEM[ARG1_B])
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_4; continue;
		}
		// TEST DEFINED FLAG ==================================================
		case 58:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				if (PRGMEM[ARG0_B] == DF)
					ExecuteByte = EXE_TRUE;
				else
					ExecuteByte = EXE_FALSE;
			}
			PIA = bc_size_3; continue;
		}
		// SET DEFINED FLAG ===================================================
		case 59:
		{
			if (PRGMEM[EXEC_B] == ExecuteByte || PRGMEM[EXEC_B] == EXE_DEFAULT)
			{
				DF = PRGMEM[ARG0_B];
			}
			PIA = bc_size_3; continue;
		}

		}
	}


	getchar();
}
// Push Address and Data to stack
void PushStackAddressData(int address, int data)
{
	StackAddress[TopLevelIndex + 1] = address;
	StackData[TopLevelIndex + 1] = data;
	TopLevelIndex++;

	lv_UpdateStackRegisters(); // Just updates the variables
}

// Push Data to stack
void PushStackData(int data)
{
	if (TopLevelIndex == 8)
	{
		return;
	}
	StackAddress[TopLevelIndex + 1] = prc;
	StackData[TopLevelIndex + 1] = data;
	TopLevelIndex++;

	lv_UpdateStackRegisters();
}

// Pop Stack once
void PopStack()
{
	if (TopLevelIndex == 0)
	{
		return;
	}
	StackAddress[TopLevelIndex] = 0;
	StackData[TopLevelIndex] = 0;
	TopLevelIndex--;

	lv_UpdateStackRegisters();
}

// LOWLEVEL: Update registers
void lv_UpdateStackRegisters()
{
	sta = StackAddress[TopLevelIndex];
	std = StackAddress[TopLevelIndex];
}
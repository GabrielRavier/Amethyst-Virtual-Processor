// Programmed with luv. ~~kernels ♥♥♥

#include "interpreter.h"
#include "Variables.c"
#include <stdio.h>

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
	StackAddress[TopLevelIndex + 1] = prc;
	StackData[TopLevelIndex + 1] = data;
	TopLevelIndex++;

	lv_UpdateStackRegisters();
}

// Pop Stack once
void PopStack()
{
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

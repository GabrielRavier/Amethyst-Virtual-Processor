﻿#pragma once
// Programmed with luv. ~~kernels ♥♥♥

// ===[Task List]=========
// DONE: Use Define pre-processor directives to lessen the confusion. I think the person helping me write this will be pissed at me.
// DONE: Clean up rubbish. Make code more readable. They might snap and could turn innocent programmers to guillotine blade wielders.
// DONE: Design the new instructions
// DONE: Add the new instructions.
// DONE: Add the new registers.
// DONE: Finish the rest of the test instructions.
// DONE: Clean code.
// DONE: Comment almost every line.
// DONE: Add documentations on each instruction.
// DONE: Design the stack
// TODO: Make decisions you undecisive worrywart overthinker. If you keep doing this incompetentness rubbish, you'll never finish anything significant.
// TODO: Unit test each and every instruction.
// TODO: Initial Full Systems Test(FST). (URGENT! HAVEN'T DONE A SINGLE TEST YET!!)
// TODO: Add the execute check

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

// Program Counter. Read Only
#define prc registers[8]

// Bytecode Boolean
// ================

#define B_TRUE 1
#define B_FALSE 0

// Bytecode Execute Boolean
// ================

#define EXE_DEFAULT 0
#define EXE_TRUE 1
#define EXE_FALSE 2

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

// Lazy Defines - Ease of torture
// ==============================

// PIA - ProgramIndexAddress
#define PIA ProgramIndexAddress

// Stack Functions
// ===============

// Stack Instruction: psh L/R R/I
void PushStackAddressData(int address, int data);

// Stack Instruction: psh R/I
void PushStackData(int data);

// Stack Instruction: pop
void PopStack();

// LOWLEVEL: Updates registers STA and STD
void lv_UpdateStackRegisters();


// Neatness Defines - Makes it pretty like anime traps
// ===================================================

// The define flag.. Uhm yeah.
#define DF DefinedFlag

// ProgramMemory.. Yup. I'm that spoiled with C defines
#define PRGMEM ProgramMemory 

// ~~ evrgrdn x krnl
// i ship it.

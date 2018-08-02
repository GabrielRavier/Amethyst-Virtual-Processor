#pragma once
// Programmed with luv.. ~~kernels ♥♥♥

// [ TASK LIST -- Amethyst 0.8 Interpreter ]
// =========================================
//
// TODO: Use Define Preprocesors to ease torture.
// TODO: Get spoiled with Defines
// DONE: Add 1 instr_size instructions
// DONE: Add 2 instr_size instructions
// DONE: Add 3 instr_size instructions
// TODO: Add 4 instr_size instructions
// TODO: Comment
// 
// Unit Test
// =========
// TODO: UNIT TESTS!!!
// TODO: Overall function
// TODO: instr_size 1 and 2
// TODO: instr_size 3 and 4
//
// Systems Test
// ============
// TODO: Full Systems Test
// TODO: Write sample code for Systems Test
// TODO: DevOps cycle and clean code.
//
// Maintenance
// ===========
// TODO: WILL DO - MORE AND MORE COMMENTS.
// TODO: Save kernel's brain memory state.
//
// Mentor Help and Rating Documentations
// =====================================
//
//
//
// General TODO List
// =================
// TODO: Write TODO list before taking a 8 hour nap
// TODO: Don't forget to write a self-deprecating message to your future self reading this code.
// TODO: FIND THE BASTARD THAT STOLE MY CLIPBOARD. クリップボード ちゃん AAH IDK
// TODO: Keep your promise that after writing the todo list, go to sleep. UWAAH BUT MY JAM CAME ON!1
// TODO: Stove warm some milk and sugar.

#define acc registers[0]                                                       // Accumulator Register
#define dat registers[1]                                                       // Data Register
#define sav registers[2]                                                       // Save Register
#define idx registers[3]                                                       // Index Register
#define prc registers[4]                                                       // Program Counter

#define instr PRGMMEM[ ProgramIndexAddress ]                                   // Gets the instruction
#define arg1  PRGMMEM[ ProgramIndexAddress + 1 ]                               // Gets Argument 1
#define arg2  PRGMMEM[ ProgramIndexAddress + 2 ]                               // Gets Argument 2
#define arg3  PRGMMEM[ ProgramIndexAddress + 3 ]                               // Gets Argument 3

#define bcsize_1 ProgramIndexAddress + 1                                       // Bytecode Sizes
#define bcsize_2 ProgramIndexAddress + 2                                       // Bytecode Sizes
#define bcsize_3 ProgramIndexAddress + 3                                       // Bytecode Sizes
#define bcsize_4 ProgramIndexAddress + 4                                       // Bytecode Sizes

#define PIA ProgramIndexAddress

#define DF DefinedFlag

#define REG registers
// ~~ evrgrdn x krnl
// i ship it.. no lol now it is...
// isla x krnl
// my new anime wife
// i'm a sick bastard.

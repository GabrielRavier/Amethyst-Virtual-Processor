#include <stdio.h>

// Registers Define Directives
#define acc registers[0]
#define dat registers[1]
#define sav registers[2]
#define p0 registers[3]
#define p1 registers[4]
#define p2 registers[5]
#define p3 registers[6]

// Bytecode sequence idk whatever structure
#define INSTR_B ProgramIndexAddress + 0
#define EXEC_B ProgramIndexAddress + 1
#define ARG0_B ProgramIndexAddress + 2
#define ARG1_B ProgramIndexAddress + 3

// Bytecode size. (increment from for loop included so subtract one)
#define bc_size_2 ProgramIndexAddress + 1;
#define bc_size_3 ProgramIndexAddress + 2;
#define bc_size_4 ProgramIndexAddress + 3;

void main()
{
    // DONE: Use Define pre-processor directives to lessen the confusion. I think the person helping me write this will be pissed at me.
    // DONE: Clean up rubbish. Make code more readable. They might snap and could turn innocent programmers to guillotine blade wielders.
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
            // new
            registers[ARG1_B] == registers[ARG0_B]; // # Execute
            ProgramIndexAddress = bc_size_4; // # Move address pointer to next instruction
            continue; // Exit and run next instruction

            // old
            //registers[ProgramIndexAddress + 3] == registers[ProgramIndexAddress + 2]; // # Execute
            //ProgramIndexAddress = ProgramIndexAddress + 3; // # Move address pointer to next instruction
            //continue; // Exit and run next instruction

            // I think this is cleaner
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

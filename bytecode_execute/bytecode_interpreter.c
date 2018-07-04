// Programmed with luv. ~~kernels ♥♥♥

#include <stdio.h>
#include "bytecode_execute.h"

void main()
{
    int registers[9] = { 00, 00 };

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
        // USELESS INSTRUCTION ================================================
        // nop
        case 0:
        {
            continue;
        }

        // MOVES and RAM INSTRUCTIONS =========================================
        // mov rr
        case 1:
        {
            registers[ARG1_B] == registers[ARG0_B]; // Execute
            PIA = bc_size_4; continue; // Finish and move to next instruction
        }

        // mov ir
        case 2:
        {
            registers[ARG1_B] == ARG0_B;
            PIA = bc_size_4; continue;
        }

        // rmc r
        case 3:
        {

        }

        // rmc i
        case 4:
        {

        }

        // rmv r
        case 5:
        {

        }
        
        // rmv i
        case 6:
        {

        }

        // swp rr
        case 7:
        {
            int temp = acc;
            acc = dat;
            dat = temp;
            PIA = bc_size_4; continue;
        }

        // JUMP INSTRUCTIONS ==================================================

        // jmp l
        case 8:
        {
            PIA = ARG0_B - 1;
            continue;
        }

        // jmp r
        case 9:
        {
            PIA = registers[ARG0_B - 1];
            continue;
        }

        // slp r
        case 10:
        {
            // No logic for now. Skips.
            PIA = bc_size_3; continue;
        }
        // SLEEP INSTRUCTIONS =================================================
        // slp i
        case 11:
        {
            // No logic for now. Skips.
            PIA = bc_size_3; continue;
        }

        // exb b
        case 12:
        {
            ExecuteByte = ARG0_B;
            PIA = bc_size_3; continue;
        }

        // ARITHMETHICC INSTRUCTIONS ==========================================

        // add r
        case 13:
        {
            acc = acc + registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // add i
        case 14:
        {
            acc = acc + ARG0_B;
            PIA = bc_size_3; continue;
        }

        // sub r
        case 15:
        {
            acc = acc - registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // sub i
        case 16:
        {
            acc = acc - ARG0_B;
            PIA = bc_size_3; continue;
        }

        // mul r
        case 17:
        {
            acc = acc * registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // mul i
        case 18:
        {
            acc = acc * ARG0_B;
            PIA = bc_size_3; continue;
        }

        // div r
        case 19:
        {
            acc = acc / registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // div i
        case 20:
        {
            acc = acc / ARG0_B;
            PIA = bc_size_3; continue;
        }






















        }

        // Update ProgramCounter Register
        prc = ProgramIndexAddress;
    }
}

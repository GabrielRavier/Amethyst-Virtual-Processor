// Programmed with luv. ~~kernels ♥♥♥

#include <stdio.h>
#include "interpreter.h"


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

        // MOVE INSTRUCTIONS ==================================================

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

        // RAM INSTRUCTIONS ===================================================

        // rmc r
        case 3:
        {
            // Skip for now.
            PIA = bc_size_3; continue;
        }

        // rmc i
        case 4:
        {
            // Skip for now.
            PIA = bc_size_3; continue;
        }

        // rmv r
        case 5:
        {
            // Skip for now.
            PIA = bc_size_3; continue;
        }
        
        // rmv i
        case 6:
        {
            // Skip for now.
            PIA = bc_size_3; continue;
        }

        // SWAP INSTRUCTION ===================================================

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

        // SLEEP INSTRUCTIONS =================================================

        // slp r
        case 10:
        {
            // No logic for now. Skips.
            PIA = bc_size_3; continue;
        }

        // slp i
        case 11:
        {
            // No logic for now. Skips.
            PIA = bc_size_3; continue;
        }

        // EXECUTE BYTE INSTRUCTION ===========================================

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

        // neg
        case 21:
        {
            acc = -acc;
            PIA = bc_size_3; continue;
        }

        // BITWISE INSTRUCTIONS ===============================================

        // not
        case 22:
        {
            acc = ~acc;
            PIA = bc_size_3; continue;
        }

        // and r
        case 23:
        {
            acc = acc & registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // and i
        case 24:
        {
            acc = acc & ARG0_B;
            PIA = bc_size_3; continue;
        }

        // orr r
        case 25:
        {
            acc = acc | registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // orr i
        case 26:
        {
            acc = acc | ARG0_B;
            PIA = bc_size_3; continue;
        }

        // xor r
        case 27:
        {
            acc = acc ^ registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // xor i
        case 28:
        {
            acc = acc ^ ARG0_B;
            PIA = bc_size_3; continue;
        }

        // BITWISE.SHIFT INSTRUCTIONS =========================================

        // lsf r
        case 29:
        {
            acc = acc << registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // lsf i
        case 30:
        {
            acc = acc << ARG0_B;
            PIA = bc_size_3; continue;
        }

        // rsf r
        case 31:
        {
            acc = acc >> registers[ARG0_B];
            PIA = bc_size_3; continue;
        }

        // rsf i
        case 32:
        {
            acc = acc >> ARG0_B;
            PIA = bc_size_3; continue;
        }

        // STACK.PUSH INSTRUCTIONS ============================================


        // STACK.POP INSTRUCTIONS =============================================


        // CALL/RET INSTRUCTIONS ==============================================









        }

        // Update ProgramCounter Register
        prc = ProgramIndexAddress;
    }
}

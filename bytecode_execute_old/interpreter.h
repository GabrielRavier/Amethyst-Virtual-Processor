// Programmed with luv. ~~kernels ♥♥♥

#include <stdio.h>
#include "interpreter.h"

// Registers
int registers[9] = { 00, 00 };

// Main Prgoram
int ProgramMemory[5] = { 0, 0, 0, 0 };

// Initiate Stack

  int StackAddress[9] = { 0,0,0,0,0,0,0,0 };                            // Stackpart.Addresses
  int StackData[9] = { 0,0,0,0,0,0,0,0 };                               // Stackpart.Data
  int TopLevelIndex = 0;                                                // TopLevelIndex


// int ProgramMemorySize = sizeof(ProgramMemory) / sizeof(int);
  int ProgramMemorySize = sizeof(ProgramMemory);

int ExecuteByte = EXE_DEFAULT;

void main()
{
    for (int ProgramIndexAddress = 0; ProgramIndexAddress <= ProgramMemorySize; ProgramIndexAddress++)
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
            registers[ARG1_B] = registers[ARG0_B]; // Execute
            PIA = bc_size_4; continue; // Finish and move to next instruction
        }

        // mov ir
        case 2:
        {
            registers[ARG1_B] = ARG0_B;
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

        // psh li
        case 33:
        {
            PushStackAddressData(ARG0_B, ARG1_B);
            PIA = bc_size_4; continue;
        }

        // psh lr
        case 34:
        {
            PushStackAddressData(registers[ARG0_B], ARG1_B);
            PIA = bc_size_4; continue;
        }

        // psh rr
        case 35:
        {
            PushStackAddressData(registers[ARG0_B], registers[ARG1_B]);
            PIA = bc_size_4; continue;
        }

        // psh ri
        case 36:
        {
            PushStackAddressData(registers[ARG0_B], ARG1_B);
            PIA = bc_size_4; continue;
        }

        // psh r
        case 37:
        {
            PushStackData(ARG0_B);
            PIA = bc_size_3; continue;
        }

        // psh i
        case 38:
        {
            PushStackData(registers[ARG0_B]);
            PIA = bc_size_3; continue;
        }

        // STACK.POP INSTRUCTIONS =============================================

        // pop
        case 39:
        {
            PopStack();
            PIA = bc_size_2; continue;
        }

        // CALL/RET INSTRUCTIONS ==============================================

        // call l
        case 40:
        {
            PIA = bc_size_3; // Skip to next instruction
            idx = PIA; // Store the ret location
            PIA = ARG0_B - 1; // Jump
        }

        // ret
        case 41:
        {
            PIA = idx - 1;
            continue;
        }

        // TEST EQUAL INSTRUCTIONS ============================================

        // teq rr
        case 42:
        {
            if (registers[ARG0_B] == registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else 
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // teq ri
        case 43:
        {
            if (registers[ARG0_B] == ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // teq ir
        case 44:
        {
            if (ARG0_B == registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // teq ii
        case 45:
        {
            if (ARG0_B == ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // TEST GREATER THAN INSTRUCTIONS =====================================

        // tgt rr
        case 46:
        {
            if (registers[ARG0_B] > registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tgt ri
        case 47:
        {
            if (registers[ARG0_B] > ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tgt ir
        case 48:
        {
            if (ARG0_B > registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tgt ii
        case 49:
        {
            if (ARG0_B > ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }
        // TEST LESS THAN INSTRUCTIONS ========================================

        // tlt rr
        case 50:
        {
            if (registers[ARG0_B] < registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tlt ri
        case 51:
        {
            if (registers[ARG0_B] < ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tlt ir
        case 52:
        {
            if (ARG0_B < registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tlt ii
        case 53:
        {
            if (ARG0_B < ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // AUXILLERY TEST INSTRUCTIONS ========================================

        // tcp rr
        case 54:
        {
            if (registers[ARG0_B] > registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            if (registers[ARG0_B] == registers[ARG1_B])
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tcp ri
        case 55:
        {
            if (registers[ARG0_B] > ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            if (registers[ARG0_B] == ARG1_B)
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tcp ir
        case 56:
        {
            if (ARG0_B > registers[ARG1_B])
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            if (ARG0_B == registers[ARG1_B])
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }

        // tcp ii
        case 57:
        {
            if (ARG0_B > ARG1_B)
                ExecuteByte = EXE_TRUE;
            else
                ExecuteByte = EXE_FALSE;
            if (ARG0_B == ARG1_B)
                ExecuteByte = EXE_FALSE;
            PIA = bc_size_4; continue;
        }
        // TEST DEFINED FLAG ==================================================
        case 58:
        {

        }
        // SET DEFINED FLAG ===================================================
        case 59:
        {

        }


        }

        // Update ProgramCounter Register
        prc = ProgramIndexAddress;
    }
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

/*
        // Instructions
        
        / Basic Instructions
        nop
        mov R/I R
        swp R R
        jmp L
        slp R/I
        
        / Arithmethic and Logic Instructions
        add R/I
        sub R/I
        mul R/I
        div R/I
        not
        
        / Test Instructions
        teq R/I R/I
        tgt R/I R/I
        tlt R/I R/I
        tcp R/I R/I
        tdf
        
        / Flag Instructions
        sdf
        
        Instructions and Arguments - Bytecode
        
        Argument Types
        rr - Register
        ii - Integer
        AA - Address
        bb - Boolean
        
bc_size Operand     num exe arg arg
1       nop         00  
4       mov R R     01  bb  rr  rr
4       mov I R     02  bb  ii  rr
4       swp R R     03  bb  rr  rr
3       jmp L       04  bb  AA
3       slp R       05  bb  rr
3       slp I       06  bb  ii
3       add R       07  bb  rr
3       add I       08  bb  ii
3       sub R       09  bb  rr
3       sub I       10  bb  ii
3       mul R       11  bb  rr
3       mul I       12  bb  ii
3       div R       13  bb  rr
3       div I       14  bb  ii
2       not         15  bb
        
4       teq R R     16  bb  rr  rr
4       teq R I     17  bb  rr  ii
4       teq I R     18  bb  ii  rr
4       teq I I     19  bb  ii  ii
        
4       tgt R R     20  bb  rr  rr
4       tgt R I     21  bb  rr  ii
4       tgt I R     22  bb  ii  rr
4       tgt I I     23  bb  ii  ii
        
4       tlt R R     24  bb  rr  rr
4       tlt R I     25  bb  rr  ii
4       tlt I R     26  bb  ii  rr
4       tlt I I     27  bb  ii  ii
        
4       tcp R R     28  bb  rr  rr
4       tcp R I     29  bb  rr  ii
4       tcp I R     30  bb  ii  rr
4       tcp I I     31  bb  ii  ii
        
3       tdf B       32  bb  bb
3       sdf B       33  bb  bb
        
        Bytecode Arguments - Integer
        Integers are parsed normally. There are no special processing
        
        Bytecode Arguments - Registers
        
        Some integer values are not allowed.
        Register Name   Num
        NUL             00
        ACC             01
        DAT             02
        SAV             03
        
        Bytecode Arguments - I/O Ports
        I/O Ports are also treated as normal registers.
        
        Bytecode I/O Registers  Num
        NUL             00
        p0              04
        p1              05
        p2              06
        p3              07
        p4              08
        p5              09
        
        Bytecode Arguments - Boolean
        Value           Num
        NUL             00
        TRUE            01
        FALSE           02



*/




#include <stdio.h>

int registers[8] = {00, 00};
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


int ProgramMemory[200] = {00,00,00,00};

for(ProgramIndexAddress = 0; ProgramIndexAddress > ProgramMemory.Length; ProgramIndexAddress++)
{
    // nop
    // 1 nop 00
    // No Operation
    if (ProgramMemory[ProgramIndexAddress] == 00)
    {
        continue;
    }

    // movrr
    // 4 mov R R 01 bb rr rr
    // Copy register 0 to register 1
    if(ProgramMemory[ProgramIndexAddress] == 01)
    {
        // execute byte not set
        if (ProgramMemory[ProgramIndexAddress + 1] != 01)
        {
            // skip over the rest of the instruction
            ProgramIndexAddress + 3;
            continue;
        }
        // Execute
        registers[ProgramMemory[ProgramIndexAddress + 2]] == registers[ProgramMemory[ProgramIndexAddress + 3]];
        ProgramIndexAddress + 3;
        continue;
    }
    // movir
    // 4 mov R R 02 bb ii rr
    // Copy intermediate number to register 0
    if(ProgramMemory[ProgramIndexAddress] == 01)
    {
        // execute byte not set
        if (ProgramMemory[ProgramIndexAddress + 1] != 01)
        {
            // skip over the rest of the instruction
            ProgramIndexAddress + 3;
            continue;
        }
        // Execute
        registers[ProgramMemory[ProgramIndexAddress + 2]] == ProgramMemory[ProgramIndexAddress + 3];
        ProgramIndexAddress + 3;
        continue;
    }
    // swprr
    // 4 swp R R 04 bb rr rr
    // Swaps register 0 and register 1
    if(ProgramMemory[ProgramIndexAddress] == 01)
    {
        // execute byte not set
        if (ProgramMemory[ProgramIndexAddress + 1] != 01)
        {
            // skip over the rest of the instruction
            ProgramIndexAddress + 3;
            continue;
        }
        // Execute
        registers[ProgramMemory[ProgramIndexAddress + 2]] == ProgramMemory[ProgramIndexAddress + 3];
        ProgramIndexAddress + 3;
        continue;
    }
}

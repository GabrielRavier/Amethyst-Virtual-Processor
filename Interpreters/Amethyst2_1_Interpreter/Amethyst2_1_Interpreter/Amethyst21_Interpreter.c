// Programmed with luv.. ~~kernels ♥♥♥

#include "Amethyst21_Interpreter.h"
#include <stdio.h>

/*

Amethyst v2.1 Interpreter
=========================


1. Defines
----------
PRGMMEM
PCCNT				Program Counter
EXEC_BIT			Execute Bit
DEFAULT_EXEC_BIT	


2. Bytecode
-----------

2.1 Bytecode Diagram
--------------------

00 00 00 00 00
^  ^  ^  ^  ^
|  |  |  |  Argument3
|  |  |  Argument2
|  |  Argument 1
|  Execute Byte
Instruction


2.2 Bytecode Indexes
--------------------
Instruction		PRGMMEM[PCCNT]
Execute Byte	PRGMMEM[PCCNT + 1]
Argument 1		PRGMMEM[PCCNT + 2]
Argument 2		PRGMMEM[PCCNT + 3]
Argument 3		PRGMMEM[PCCNT + 4]


3. Execution
------------

3.1 Execution Steps
-------------------

1. Get the instruction size. The amount of bytes to skip is saved. INDEX_SKIP = ??
2. Check if PCCNT == EXEC_BIT OR DEFAULT_EXEC_BIT
 2.1 If so, Do not execute anything, then run Skip subroutine
3. Execute.
4. Update registers and statuses
5. Run Skip subroutine

3.2 Instruction Size sub-routine
--------------------------------

If the instruction byte


3.3 Skip subroutine
-------------------
1. After getting instruction size
2. PCCNT index = PCCNT + INDEX_SKIP


3.3.1 Instruction Size Skip sizes
---------------------------------

INDEX_SKIP | Instruction Size Ranges
------------------------------------
2          | TODO: This
3          | TODO: Bytecodes
4          | DONE: Instructions
5          |  


// Amethyst v2.1 is more linear. Removes the - 1 because less instructions

INDEX_SKIP | Instruction Size
-----------------------------
2		   | 2
3		   | 3
4		   | 4
5		   | 5




*/

void main()
{
	if (1)
	{

	}
	else if (1)
	{

	}
	else if (1)
	{

	}


    return;
}


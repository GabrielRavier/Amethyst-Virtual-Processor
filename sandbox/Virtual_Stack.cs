// Programmed with luv. ~~kernels ♥♥♥

// I can't believe I wrote and designed this program in less than 5 minutes ayy eacks lmao

using System;

namespace Virtual_Stack
{
    class Program
    {
        // Init stack
        static int StackIndex = 0;
        static int[] Stack = new int[8];

        static void Main(string[] args)
        {
            Console.WriteLine("Kernels Simulated Virtual Stack");

            Console.WriteLine("Push 107");
            PushStack(107);
            OutputStackContents();

            Console.WriteLine("Push 114");
            PushStack(114);
            OutputStackContents();

            Console.WriteLine("Push 110");
            PushStack(110);
            OutputStackContents();

            Console.WriteLine("Push 108");
            PushStack(108);
            OutputStackContents();

            Console.WriteLine("Pop Stack");
            PopStack();
            OutputStackContents();

            Console.WriteLine("Pop Stack");
            PopStack();
            OutputStackContents();

            Console.WriteLine("Pop Stack");
            PopStack();
            OutputStackContents();

            Console.WriteLine("Push 50");
            PushStack(50);
            OutputStackContents();

            Console.ReadLine();
        }
      
      
        // STACK OPERATORS
        static void PushStack(int Data)
        {
            Stack[StackIndex + 1] = Data;
            StackIndex++;
        }

        static void PopStack()
        {
            Stack[StackIndex] = 0;
            StackIndex--;
        }

        static void OutputStackContents()
        {
            Console.WriteLine("Contents of Stack");
            for (int i = 0; i < Stack.Length; i++)
            {
                Console.WriteLine($"{i}|{Stack[i]}");
            }
            Console.WriteLine();
            Console.WriteLine("Top Stack Index: {0}", StackIndex);
            Console.WriteLine("Top Stack Value: {0}", Stack[StackIndex]);
            Console.WriteLine();
        }
    }
}

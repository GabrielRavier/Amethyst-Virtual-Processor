// Programmed with luv. ~~kernels ♥♥♥

// TO-DO LIST
// TODO: Read https://en.wikipedia.org/wiki/Parsing
// TODO: Read https://en.wikipedia.org/wiki/Interpreter_(computing)
// TODO: Read https://en.wikipedia.org/wiki/Translator_(computing)
// DONE: Input Cleansing
// TODO: Lexical Analysis
//  * TODO: Final Step: Program Evaluator
//  * TODO: ConvertToTokens
//  * TODO: Syntax Validity
// TODO: Bytecode Translator
//  * TODO: TOKEN TO BYTECODE
//  * TODO: INSTRUCTION OVERLOADING 
//  * TODO:  





using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Amethyst_ASM
{
#pragma warning disable IDE1006 // Naming Styles
    class std_portablebytecode
    {
        private static void Method()
        {
        }
        


        private class lowlevel
        {


        }

        /// <summary>
        /// Cleanse of input is the first step of parsing program input
        /// </summary>
        private class InputCleaning
        {
            /// <summary>
            /// Preps program for parsing. Removes all comments.
            /// </summary>
            /// <param name="Input">Prgram to clean</param>
            /// <returns>De-commented program</returns>
            internal static string[] RemoveComments(string[] Input)
            {
                List<string> OutputProgram = new List<string>();
                foreach (string LineOfProgram in Input)
                {
                    // OutputProgram.Add(LineOfProgram.Remove(LineOfProgram.IndexOf('#')));
                    string SansComment = LineOfProgram.Remove(LineOfProgram.IndexOf('#'));
                    if (SansComment.Length != 0)
                    {
                        OutputProgram.Add(SansComment);
                    }
                }
                return OutputProgram.ToArray();
            }

            /// <summary>
            /// Splits the program line to be prepared for parsing. This is the last step in the cleaning process.
            /// </summary>
            /// <param name="InputLine"></param>
            /// <returns></returns>
            internal static string[] SplitProgramLine(string InputLine)
            {
                return InputLine.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }
        }

        /// <summary>
        /// Analyse syntax to check for errors
        /// </summary>
        private class LexicalAnalysis
        {
            internal static void EvaluateProgram(string[] Program, out TokenType[] tokens)
            {

            }
            private static TokenType[] ConvertToTokens(string InputLine)
            {

            }
            private static bool SyntaxValidityCheck(TokenType[] tokens)
            {

            }
        }

        /// <summary>
        /// Converts program to bytecode
        /// </summary>
        private class Translator
        {

        }
    }

    enum TokenType { INSTRUCTION, REGISTER, INTEGER_LITERAL, BOOLEAN, EXECUTE_BOOL}
    enum InstructionsTokens { nop, mov, rmc, rmv, swp, jmp, slp, exb, add, sub, mul, div, neg, not, and, orr, xor, lsf, rsf, psh, pop, cal, ret, teq, tgt, tlt, tcp, tdf, sdf};
    enum RegistersTokens { acc, dat, sav, sta, std, idx}
    enum ReadOnlyRegistersTokens { rmd, rma, prc }
#pragma warning restore IDE1006 // Naming Styles lmao
}

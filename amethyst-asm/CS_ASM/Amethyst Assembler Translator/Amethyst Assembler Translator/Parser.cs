using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace Amethyst_Assembler_Translator
{
    partial class std_portablebytecode
    {
        private const int TOKEN_ARRAY_SIZE = 4;


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
                //TokenType[][] OutputTokens = new TokenType[Program.Length][];

                //for (int index = 0; index < Program.Length; index++)
                //{
                //    OutputTokens[index] = ConvertToTokens(Program[index]);
                //    if (SyntaxValidityCheck(Program[index], )
                //    {

                //    }
                //}
            }

            private static TokenType[] ConvertToTokens(string[] InputLine)
            {
                // Converts this: + mov 100 acc 
                // EXECUTE_BOOL, INSTRUCTION, INTEGER_LITERAL, REGISTER

                TokenType[] OutputTokens = new TokenType[4];

                int switchcheck = 0;
                // Check if first is a conditional execution
                switch (InputLine[switchcheck])
                {
                    case "+":
                        OutputTokens[switchcheck] = TokenType.EXECUTE_BOOL;
                        break;
                    case "-":
                        OutputTokens[switchcheck] = TokenType.EXECUTE_BOOL;
                        break;
                    default:
                        {
                            if (Enum.TryParse<InstructionsTokens>(InputLine[switchcheck], true, out var result000))
                            {
                                switchcheck = 1;
                                OutputTokens[switchcheck] = TokenType.INSTRUCTION;

                            }
                            // Check if it is a label
                            else if(InputLine[switchcheck][0] == ':')
                            {
                                switchcheck = 1;
                                OutputTokens[switchcheck] = TokenType.LABEL;
                            }
                            else
                            {
                                throw new AmethystException("Invalid Input Line: InputIndex[0] is not an instruction or conditional bool");
                            }
                        }
                        break;
                }

                #region ___
                //Checks if next index is an instruction(ASSERT)
                if (Enum.TryParse<InstructionsTokens>(InputLine[switchcheck], true, out var result001))
                {
                    switchcheck += 1;
                    OutputTokens[switchcheck] = TokenType.INSTRUCTION;
                }
                else
                {
                    throw new AmethystException("Invalid Input Line: InputIndex[1] is not an instruction");
                }
                #endregion

                #region ___
                // Checks if next index is argument0 as register, integer or label(default case)
                if (Enum.TryParse<RegistersTokens>(InputLine[switchcheck], true, out var result002))
                {
                    switchcheck += 1;
                    OutputTokens[switchcheck] = TokenType.INSTRUCTION;
                } else if (Int32.TryParse(InputLine[switchcheck],out var result003))
                {
                    switchcheck += 1;
                    OutputTokens[switchcheck] = TokenType.INTEGER_LITERAL;
                }
                else
                {
                    switchcheck += 1;
                    OutputTokens[switchcheck] = TokenType.LABEL;
                }
                #endregion





            }
            private static bool SyntaxValidityCheck(string Program, TokenType[] tokens)
            {
                // For that instruction, check if it has the correct tokens and/or arguments.
            }
        }

        /// <summary>
        /// Converts program to bytecode
        /// </summary>
        private class Translator
        {

        }
        #region Tokens
#pragma warning disable IDE1006 // Naming Styles
        enum TokenType { INSTRUCTION, REGISTER, INTEGER_LITERAL, BOOLEAN, EXECUTE_BOOL, LABEL }
        enum InstructionsTokens { nop, mov, rmc, rmv, swp, jmp, slp, exb, add, sub, mul, div, neg, not, and, orr, xor, lsf, rsf, psh, pop, cal, ret, teq, tgt, tlt, tcp, tdf, sdf };
        enum RegistersTokens { acc, dat, sav, sta, std, idx }
        // enum RegistersTokens { acc, dat, sav, sta, std, idx, rmd, rma, prc }
        enum ReadOnlyRegistersTokens { rmd, rma, prc }
#pragma warning restore IDE1006 // Naming Styles lmao
        #endregion

        // enum InstructionsTokens { nop, mov, rmc, rmv, swp, jmp, slp, exb, add, sub, mul, div, neg, not, and, orr, xor, lsf, rsf, psh, pop, cal, ret, teq, tgt, tlt, tcp, tdf, sdf };
        int[] Instruction_b_size = { 2,   3,   3,   3,   4,   3,   3,   3,   3,   3,   3,   3,   2,   2,   3,   3,   3,   3,   3,   4,   2,   3,   2,   4,   4,   4,   4,   3,   3   };
        // NOTE: PSH can be bc_size_4 or bc_size_3.
    }

    [Serializable]
    public class AmethystException : Exception
    {
        public AmethystException() { }
        public AmethystException(string message) : base(message) { }
        public AmethystException(string message, Exception inner) : base(message, inner) { }
        protected AmethystException(
          SerializationInfo info,
          StreamingContext context) : base(info, context) { }
    }
}

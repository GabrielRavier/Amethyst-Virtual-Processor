using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Amethyst_Assembler_Translator
{
    partial class std_portablebytecode
    {
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
            private static TokenType[] ConvertToTokens(string[] InputLine)
            {
                
                // Converts this: + mov 100 acc 
                // EXECUTE_BOOL, INSTRUCTION, INTEGER_LITERAL, REGISTER
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
        enum TokenType { INSTRUCTION, REGISTER, INTEGER_LITERAL, BOOLEAN, EXECUTE_BOOL }
        enum InstructionsTokens { nop, mov, rmc, rmv, swp, jmp, slp, exb, add, sub, mul, div, neg, not, and, orr, xor, lsf, rsf, psh, pop, cal, ret, teq, tgt, tlt, tcp, tdf, sdf };
        enum RegistersTokens { acc, dat, sav, sta, std, idx }
        enum ReadOnlyRegistersTokens { rmd, rma, prc }
#pragma warning restore IDE1006 // Naming Styles lmao
        #endregion

    }

    [Serializable]
    public class AmethystException : Exception
    {
        public AmethystException() { }
        public AmethystException(string message) : base(message) { }
        public AmethystException(string message, Exception inner) : base(message, inner) { }
        protected AmethystException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}

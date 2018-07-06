using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Amethyst_Assembler_Translator
{
#pragma warning disable IDE1006 // Naming Styles
    public class std_portablebytecode
    {

    }
    class lowlevel
    {

        /// <summary>
        /// Preps program for parsing. Removes all comments.
        /// </summary>
        /// <param name="Input">Prgram to clean</param>
        /// <returns>De-commented program</returns>
        private static string[] RemoveComments(string[] Input)
        {
            List<string> OutputProgram = new List<string>();
            foreach (string LineOfProgram in Input)
            {
                OutputProgram.Add(LineOfProgram.Remove(LineOfProgram.IndexOf('#')));
            }
            return OutputProgram.ToArray();
        }

        /// <summary>
        /// Splits the program line to be prepared for parsing. This is the last step in the cleaning process.
        /// </summary>
        /// <param name="InputLine"></param>
        /// <returns></returns>
        private static string[] SplitProgramLine(string InputLine)
        {
            return InputLine.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }

    enum Instructions { nop, mov, rmc, rmv, swp, jmp, slp, exb, add, sub, mul, div, neg, not, and, orr, xor, lsf, rsf, psh, pop, cal, ret, teq, tgt, tlt, tcp, tdf, sdf};
    enum Registers { acc, dat, sav, sta, std, idx}
    enum ReadOnlyRegisters { rmd, rma, prc }
#pragma warning restore IDE1006 // Naming Styles lmao
}

using System.ComponentModel.Design;
using System.Diagnostics.CodeAnalysis;

class Program
{
    static void Main()
    {
        int[] akcie = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 11, 10 };
        int sum = 0;
        foreach (var item in akcie)
            sum += item;
        double avg = sum/ akcie.Length;
        int above = 0;
        foreach (var item in akcie)
            if (item > avg) above++;
        Console.WriteLine((double)above/akcie.Length);
        bool growing = false;
        int j = 0;
        int nej = 0;
        for (int i = 1; i < akcie.Length; i++)
        {

            if (akcie[i] > akcie[i - 1])
            {
                if (growing)
                {
                    j += 1;
                }
                else
                {
                    growing = true;
                    j = 2;
                }
            }
            else { 
                
                growing = false;
                if (j > nej)
                {
                    nej = j;
                }
            }
        }
        Console.WriteLine(nej);
    }
}
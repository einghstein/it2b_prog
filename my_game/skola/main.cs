using System.ComponentModel.Design;
using System.Diagnostics.CodeAnalysis;

class Program
{
    static void akcie()
    {
        int[] akcie = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 11, 10 };
        int sum = 0;
        foreach (var item in akcie)
            sum += item;
        double avg = sum / akcie.Length;
        int above = 0;
        foreach (var item in akcie)
            if (item > avg) above++;
        Console.WriteLine((double)above / akcie.Length);
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
            else
            {

                growing = false;
                if (j > nej)
                {
                    nej = j;
                }
            }
        }
        Console.WriteLine(nej);
    }
    static void quizz()
    {
        string[] q = { "A", "B", "C", "D", "E" };
        string[] a = { "A", "B", "C", "D", "E" };
        for (int i = 0; i < q.Length; i++) {
            Console.WriteLine(q[i]);
            if (Console.ReadLine() == a[i])
            {
                Console.WriteLine("correct");
            }
            else
            {
                Console.WriteLine("incorrect");
            }
        }
    }
    static void cenzura(string veta, char znak)
    {
        foreach (char c in veta)
        {
            if (c == znak) { Console.Write("*"); }
            else { Console.Write(c); }
        }
        Console.WriteLine();
    }
    static void Main()
    {
        //quizz();
        //cenzura("gugugaga", 'g');
    }
}

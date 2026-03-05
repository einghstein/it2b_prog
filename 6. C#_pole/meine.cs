using System.ComponentModel.DataAnnotations;
using System.Linq;

class Program
{
    
    static void poleig()
    {
        int[] pole = new int[10];
        for (int i = 0; i < 10; i++)
        {
            Console.Write($"Cislo {i + 1}: ");
            pole[i] = int.Parse(Console.ReadLine());
        }
        Array.Sort(pole);
        Console.WriteLine($"min: {pole[0]}\nmax: {pole[9]}\ndiff: {pole[9] - pole[0]}");
        Console.WriteLine($"3 min: {pole[0]}, {pole[1]}, {pole[2]}");

        Console.WriteLine($"median: {(pole[4] + pole[5]) / 2.0 }");
    }

    static bool stejnePrvky(int[] pole){
        for (int i = 0; i < pole.Length; i++){
            for (int j = i + 1; j < pole.Length; j++) {
                if (pole[j] == pole[i]){
                    return true;
                }
            }
        }
        return false;
    }

    static bool delitel(int[] pole) {
        int max = pole.Max();
        for 
    }

    static void Main()
    {
        int[] test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12 };
        Console.Write("stej: ");
        Console.WriteLine(stejnePrvky(test));
        Console.WriteLine($"delitel: {delitel(test)}");
    }
}

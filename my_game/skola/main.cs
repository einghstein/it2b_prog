
using System;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Security.Authentication.ExtendedProtection;

/*
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

    static void trojka()
    {
        List<int> pole = new List<int> { 0 };
        int i = 0;
        while (true)
        {
            Console.Write("> ");
            char inp = char.Parse(Console.ReadLine());
            if (inp == 's') { pole.Append(pole[i] - 1); }
            else if (inp == 'w') { pole.Append(pole[i] + 1); }
            else if (inp == 'W') { pole.Append(pole[i] + 3); }
            else if (inp == 'S') { pole.Append(pole[i] - 3); }
            else { break; }
        }

        int offset = pole[0];
        foreach (int it in pole) { if (it < offset) { offset = it; } }
        offset = Math.Abs(offset);
        Console.WriteLine(offset);
        foreach (int it in pole)
        {
            for (int j = 0; j < (it + offset); j++) {
                Console.Write("X");
                Console.WriteLine($"{it}");
            }

            Console.WriteLine(it);

        }
        //Console.WriteLine(pole[pole.Length -1 ]);

    }
*/
class Car
{
    public string Nazev;
    public int Cena;
    public int Vykon;

    public double Pomer;
    public Car(string nazev, int cena, int vykon)
    {
        Nazev = nazev;
        Cena = cena;
        Vykon = vykon;
        Pomer = (double)cena / vykon;

    }
}

class App
{
    public App() { }
    public List<Car> list;
    public void Add(string nazev, int cena, int vykon)
    {
        list.Add(new Car(nazev, cena, vykon));
    }
    public string nej()
    {
        Car best = list[0];
        foreach (Car i in list)
        {
            if (i.Pomer < best.Pomer)
            {
                best = i;
            }
        }
        return best.Nazev;
    }
}
/*
class Program
{

    static string nejdelsi(string veta)
    {
        string[] slova = veta.Split(" ");
        int nej = 0;
        string cur = "";
        foreach (string s in slova)
        {
            if ((s.Contains('a') || s.Contains('A')) && s.Length > nej)
            {
                cur = s;
                nej = s.Length;
            }
        }
        return cur;
    }

    static List<int> BezDuplicit(int[] pole)
    {
        List<int> list = pole.ToList();
        list.Sort();
        while (true) {
            bool notchange = true;
            for (int i = 0; i < list.Count - 1; i++) {
                {
                    if (list[i] == list[i + 1])
                    {
                        notchange = false;
                        list.Remove(list[i]);
                        break;
                    }
                }
                
            }
            if (notchange) { return list; }
        }
    }


        static void Main()
        {
        /*Console.WriteLine(nejdelsi("a aa aaa bbb"));
        Console.WriteLine(nejdelsi("gaga gadg"));
        Console.WriteLine(nejdelsi("aaaaaabbb"));
        Console.WriteLine(nejdelsi("bbb"));
        Console.WriteLine(nejdelsi("b bbb"));

        int[] pole = { 3, 1, 2 };
        foreach (int i in BezDuplicit(pole))
        {
            Console.WriteLine(i);
        }
        App app = new App();
    }
}




class Film
{
    public string Nazev;
    public int Hodnoceni;

    public Film(string nazev, int hodnoceni)
    {
        string Nazev = nazev;
        int Hodnoceni = hodnoceni;
    }
}

    class App
    {
        private int avg = 0;
        public List<Film> list = new List<Film>();
        void Add()
        {
            string nazev = Console.ReadLine();
            int hodnoceni = int.Parse(Console.ReadLine());
            avg += hodnoceni;
            list.Add(new Film(nazev, hodnoceni));
        }
        void writeAll() { foreach (Film film in list) { Console.WriteLine(film.Nazev); } }
        void find(string vyraz)
        {
            foreach (Film film in list) { if (film.Nazev.Contains(vyraz)) { Console.WriteLine(film.Nazev); } }
            void getAvgHodnoceni() { Console.WriteLine(avg / list.Count()); }
        }
        void remove(string vyraz)
        {
            foreach (Film film in list) { if (film.Nazev.Contains(vyraz)) { list.Remove(film); } }
        }
    }
*/



class Planet
{
    public int mass;
    public string id;
    public int[] pos;   // Position in 2D (x, y)
    public int[] speed; // Speed in 2D (vx, vy)

    // Constructor to initialize mass, id, and position; speed defaults to (0, 0)
    public Planet(int mass, string id, int[] pos)
    {
        this.mass = mass;
        this.id = id;
        this.pos = pos;
        this.speed = new int[] { 0, 0 }; // Default speed (vx, vy)
    }

    // Method to update the position of the planet based on its speed
    public void UpdatePosition()
    {
        // Update position based on speed
        pos[0] += speed[0]; // Update x position
        pos[1] += speed[1]; // Update y position
    }

    // Method to apply gravitational force and update speed
    public void ApplyGravity(Planet other, int G)
    {
        // Calculate distance between planets
        int dx = other.pos[0] - this.pos[0];
        int dy = other.pos[1] - this.pos[1];
        double distance = Math.Sqrt(dx * dx + dy * dy);

        // Gravitational force formula F = G * (m1 * m2) / r^2
        double force = G * (this.mass * other.mass) / (distance * distance);

        // Calculate direction of force (unit vector)
        double forceX = force * dx / distance;
        double forceY = force * dy / distance;

        // Update speed based on gravitational force (assuming small time step)
        speed[0] += (int)(forceX / this.mass); // Change in x-speed
        speed[1] += (int)(forceY / this.mass); // Change in y-speed
    }
}

class Program
{
    static void Main()
    {
        // Gravitational constant (arbitrary for this simulation)
        const int gravitationalConstant = 600000;

        // Create some planets
        List<Planet> planets = new List<Planet>
        {
            new Planet(100, "Planet A", new int[] { 0, 0 }),
            new Planet(150, "Planet B", new int[] { 100, 0 })
        };

        // Simulate the system by updating positions and applying gravity
        for (int i = 0; i < 10; i++) // 10 iterations
        {
            // Apply gravity between each pair of planets
            for (int j = 0; j < planets.Count; j++)
            {
                for (int k = j + 1; k < planets.Count; k++)
                {
                    planets[j].ApplyGravity(planets[k], gravitationalConstant);
                    planets[k].ApplyGravity(planets[j], gravitationalConstant);
                }
            }

            // Update positions of all planets
            foreach (var planet in planets)
            {
                planet.UpdatePosition();
                Console.WriteLine($"Planet {planet.id} Position: ({planet.pos[0]}, {planet.pos[1]})");
            }
            Console.WriteLine("-----------");
        }
    }
}

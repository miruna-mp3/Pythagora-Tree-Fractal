    #include <iostream>
    #include "graphics2.h"
    using namespace std;

    struct point
    {
        double x, y;
    } a, b;

    void PythagoreanTree(point a, point b, int amount);
    void End();

    int nr, amount, length;
    int poly[10];

    int main()
    {
        amount = 10; ///nr. repetari
        length = 160; ///lungime init.

        a.x = 6*length/2 - length/2;
        a.y = 4*length;
        b.x = 6*length/2 + length/2;
        b.y = 4*length;

        int driver, mod;
        initgraph(&driver, &mod, "Pythagorean Tree", 1024, 1024);

        PythagoreanTree(a,b,amount);

        End();

        return 0;
    }

    void PythagoreanTree(point a, point b, int amount)
    {
        point c,d,e;

        ///a & b sunt punctele de la baza patratului curent
        ///construim d & c care sunt punctele de la partea de sus a patratului curent
        ///e va fi punctul de "punte" dintre cele 2 patrate care se construiesc mai departe
        ///adica e va fi punctul unde cele 2 patrate se ating
        ///deci bazele la urmatoarele 2 patrate vor fi defapt d & e, respectiv e & c

        c.x = b.x - (a.y - b.y);
        c.y = b.y - (b.x - a.x);

        d.x = a.x - (a.y - b.y);
        d.y = a.y - (b.x - a.x);

        e.x = d.x + ( b.x - a.x - (a.y - b.y) ) / 2;
        e.y = d.y - ( b.x - a.x + (a.y - b.y) ) / 2;

        if (amount > 0)
        {
            setcolor((amount + 2)%15 + 1);

            poly[0] = a.x; //1st vertex
            poly[1] = a.y;

            poly[2] = b.x; //2nd vertex
            poly[3] = b.y;

            poly[4] = c.x; //3rd vertex
            poly[5] = c.y;

            poly[6] = d.x; //4th vertex
            poly[7] = d.y;

    //poly-ul nu se inchide singur, deci inchidem noi la punctul initial
            poly[8] = a.x;
            poly[9] = a.y;

            fillpoly(5, poly);
            //setcolor(YELLOW);
            //drawpoly(5, poly);

            PythagoreanTree(d,e,amount-1);
            PythagoreanTree(e,c,amount-1);
        }
    }

    void End()
    {
        getch();
        cleardevice();
        closegraph();
    }

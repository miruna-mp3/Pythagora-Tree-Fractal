#include <iostream>
#include "graphics2.h"

using namespace std;

int nr=1;

void fractal(int xc, int yc, int L);
int main()
{int L=200;
	//initializare mod grafic
	int driver, mod;
	initgraph(&driver, &mod, "", 1280, 1024); //ultimii 2 parametri = dimensiunea in pixeli a ferestrei grafice
	//calculam coordonatele centrului ferestrei
	double midx = getmaxx()/2;
	double midy = getmaxy()/2;
	fractal(midx, midy, L);
    while (!kbhit());
    closegraph();
	return 0;
}

void fractal(int xc, int yc, int L)
///daca c==0 rosu daca c==1 albastru
{
nr++;
if (L>1)
    {
     fractal(xc-L/2, yc-L/2, L/2);
     fractal(xc-L/2, yc+L/2, L/2);
     fractal(xc+L/2, yc+L/2, L/2);
     fractal(xc+L/2, yc-L/2, L/2);
     if(nr%2 == 0) setcolor(RED);
     else setcolor(BLUE);
     bar(xc-L/2, yc-L/2, xc+L/2, yc+L/2);
     setcolor(YELLOW);
     rectangle(xc-L/2, yc-L/2, xc+L/2, yc+L/2);
    }
nr--;
}

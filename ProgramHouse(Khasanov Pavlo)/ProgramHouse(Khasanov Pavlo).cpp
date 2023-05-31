#include "includes.h"

int main()
{
    Human* h = new Human[5];
    House h1(50, 5, h);

    House h2(h1);
    h2.delHuman(4);
    h2.displayHouse();
    cout << endl << endl;
    h1.displayHouse();
}

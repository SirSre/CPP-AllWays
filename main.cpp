#include <iostream>
using namespace std;
#include <vector>

class Feld{
    int xGrenzwert;
    int yGrenzwert;
    int ergebnis;
public:
    Feld(int _xGrenzwert, int _yGrenzwert): xGrenzwert(_xGrenzwert), yGrenzwert(_yGrenzwert), ergebnis(0) {}
    int laufen(int xWert, int yWert);
};

int Feld::laufen(int xWert, int yWert) {
    if(xWert == xGrenzwert && yWert == yGrenzwert){
        ergebnis++;
    } else if(xWert <= xGrenzwert && yWert <= yGrenzwert) {
        laufen(xWert+1,yWert);
        laufen(xWert,yWert+1);
    }
    return ergebnis;
}

int main() {
    int xKoordinate;
    int yKoordinate;
    cout << "xGrenze des Feldes eingeben: " << endl;
    cin >> xKoordinate;
    cout << "yGrenze des Feldes eingeben: " << endl;
    cin >> yKoordinate;

    Feld f(xKoordinate,yKoordinate);
    int x = f.laufen(0,0);
    cout << x << endl;
    return 0;
}
/**
1	2	3	4	5
1	2	3	4	5	6
2	3	6	10	15	21
3	4	10	20	35	56
4	5	15	35	70	126
5	6	21	56	126	252
*/
/**
 * Basisfaelle sind alle Faelle mit M oder N kreuz 1 (Mx1) und (Nx1) in diesen gibt es M+1 bzw N+1 Moeglichkeiten
 * Alle anderen Faelle (MxN) kann man wie folgend berechnen (MxN-1)+(M-1xN)
 * Sollten die Ergebnisse davon nicht vorliegen kann man das Ergebnis wieder rekursiv berchnen
 * */
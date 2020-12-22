#include <iostream>
using namespace std;

class Feld{
    int xMax;
    int yMax;
    int result;
public:
    Feld(int _xMax, int _yMax): xMax(_xMax), yMax(_yMax), result(0) {}
    int allWays(int xWert, int yWert);
};

int Feld::allWays(int xWert, int yWert) {
    if(xWert == xMax && yWert == yMax){
        result++;
    } else if(xWert <= xMax && yWert <= yMax) {
        allWays(xWert+1,yWert);
        allWays(xWert,yWert+1);
    }
    return result;
}

int main() {
    int xCoordinate;
    int yCoordinate;
    cout << "Enter your max x Value: " << endl;
    cin >> xCoordinate;
    cout << "Enter your max y Value: " << endl;
    cin >> yCoordinate;

    Feld f(xCoordinate,yCoordinate);
    int x = f.allWays(0,0);
    cout << x << endl;
    return 0;
}
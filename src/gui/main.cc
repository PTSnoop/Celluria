#include "main.hh"

int main() {
    
    IrrlichtDriver * irrdriver = new IrrlichtDriver;

    int i = 0;
    while (irrdriver->run()) {
        cout << i << endl;
        i++;
    }
    return 0;
}

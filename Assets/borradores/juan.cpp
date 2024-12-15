#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

float alive = 1;

void beAwesome() {
    cout << "be awesome!" << endl;
}

int main() {

    while(alive) {
        beAwesome();
        sleep(1);
    }

    return 0;
}
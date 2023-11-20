#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

#define LENGTH 20
#define FILE_NAME "SequenciaTeste_"

int main () {
    srand((unsigned) time(NULL));
    
    ofstream ArqSequencia (FILE_NAME + to_string(LENGTH) + ".txt");
    
    for (int i = 0; i < LENGTH; i++) {
        int random = rand() % 20;
        ArqSequencia << random << endl;
    }
    
    ArqSequencia.close();

    return 1;
}
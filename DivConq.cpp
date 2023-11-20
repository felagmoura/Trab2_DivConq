#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

vector<int> CriarSequecia (string FileName);
void LIS (vector<int> Subsequencia);
int SearchIndex (vector<int> Sequencia, int maxLen, int elemento);


int main (int argc, char* argv[]) {
    vector<int> Sequencia = CriarSequecia(argv[1]);
    LIS(Sequencia);

    return 1;
}


vector<int> CriarSequecia (string FileName) {
    vector<int> Sequencia;
    ifstream inputFile (FileName);

    int value;

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    while (inputFile >> value) {
        Sequencia.push_back(value);
    }

    return Sequencia;
}

void LIS (vector<int> Sequencia) {
    int SeqLen = Sequencia.size();

    vector<int> temp (SeqLen, INT_MAX);
    int position[SeqLen];

    int last_index = 0;
    
    temp[0] = Sequencia[0];
    position[0] = 0;

    for (int i = 1; i < SeqLen; i++) {
        if (temp[last_index] < Sequencia[i]) {
            temp[last_index + 1] = Sequencia[i];
            position[last_index + 1] = i;
            last_index++;
        }
        else {
            int first_index = SearchIndex(temp, SeqLen, Sequencia[i]);
            temp[first_index] = Sequencia[i];
            position[first_index] = i;
        }
    }

    cout << "Length of longest increasing subsequence " << last_index + 1 << endl;

    for (int i = 0; i < last_index + 1; i++)
        cout << Sequencia[position[i]] << " ";
    cout << endl;
}

int SearchIndex (vector<int> Sequencia, int maxLen, int elemento) {
    int mid;
    int low = 0;
    int high = maxLen;

    while (low < high) {
        mid = low + (high - low) / 2;

        if (elemento <= Sequencia[mid]) {
            high = mid;
        }

        else {
            low = mid + 1;
        }
    }

    return low;
}
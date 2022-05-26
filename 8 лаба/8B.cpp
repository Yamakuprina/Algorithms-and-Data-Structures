#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;
    int matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> matrix[i][j];
        }
    }
    bool ch = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((matrix[i][j] != matrix[j][i]) || (i == j && matrix[i][j] != 0)) {
                ch = false;
            }
        }
    }
    if (ch) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    return 0;
}

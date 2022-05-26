#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M;
    fin >> N >> M;

    int matrix[N][N];
    memset(matrix, 0, sizeof(int)*N*N);

    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        matrix[x-1][y-1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}

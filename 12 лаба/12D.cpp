#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    long long n, m;
    fin >> n >> m;

    vector<vector<long long>> table(n + 3, vector<long long>(m + 3, 0));
    table[2][2] = 1;
    int si = 2, sj = 2;
    while ((si < n + 1) || (sj < m + 1)) {
        if (sj == m + 1) {
            si++;
        } else {
            sj++;
        }
        int i = si;
        int j = sj;
        while ((i <= n + 1) && j >= 2) {
            table[i][j] = table[i + 1][j - 2] + table[i - 1][j - 2] + table[i - 2][j - 1] + table[i - 2][j + 1];
            i++;
            j--;
        }
    }/*
    for (int i=0;i<n+3;i++){
        for (int j=0;j<m+3;j++){
            fout << table[i][j] << " ";

        }
        fout << endl;
    }*/
    fout << table[n + 1][m + 1];

    fin.close();
    fout.close();
}

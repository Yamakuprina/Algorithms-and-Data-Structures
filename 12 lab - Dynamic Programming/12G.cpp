#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");

    int s, n;
    fin >> s >> n;
    vector<vector<long long>> arr(n + 1, vector<long long>(s + 1, 0));
    vector<long long> weight(n + 1);
    weight[0] = 0;

    for (int i = 1; i <= n; ++i) {
        fin >> weight[i];
    }

    for (int i = 0; i <= s; ++i) {
        arr[0][i] = 0;
    }

    for (int i = 0; i <= n; ++i) {
        arr[i][0] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j >= weight[i])
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - weight[i]] + weight[i]);
            else
                arr[i][j] = arr[i - 1][j];
        }
    }

    /*
    for (int i=0;i<n+1;i++){
        for (int j=0;j<s+1;j++){
            fout << arr[i][j] << " ";

        }
        fout << endl;
    }*/


    fout << arr[n][s] << endl;

    fin.close();
    fout.close();
}

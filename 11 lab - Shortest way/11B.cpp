#include <iostream>
#include <vector>
#include <fstream>
#define INF 100000000
using namespace std;


int main() {
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");

    int N, M;
    fin >> N >> M;
    vector<pair <pair <int, int>, int>> edges;
    for (int j = 1; j <= M; j++) {
        int u, v, weight;
        fin >> u >> v >> weight;
        edges.emplace_back(make_pair(u, v), weight);
    }
    int matrix[N+1][N+1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            matrix[i][j] = INF;
        }
    }
    for (auto e : edges) {
        matrix[e.first.first][e.first.second] = e.second;
    }

    for (int i = 1; i <= N; i++) {
        matrix[i][i] = 0;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}

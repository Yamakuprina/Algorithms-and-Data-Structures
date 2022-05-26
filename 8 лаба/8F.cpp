#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;
vector <int> arr[10001];

vector <char> bfs (int N, int M, int start, int destination) {
    vector<int> d(N), p(N);
    vector <bool> used(N);
    queue<int> Q;
    p[start] = -1;
    used[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto V : arr[u]) {
            int t = V;
            if (!used[t]) {
                used[t] = true;
                Q.push(V);
                d[V] = d[u] + 1;
                p[t] = u;
            }
        }
    }
    vector <int> path(0);
    if (used[destination]) {
        for (int v = destination; v != -1; v = p[v]) {
            path.push_back(v);
        }
    }
    reverse(path.begin(), path.end());
    vector <char> path2;
    int size = path.size();
    for (int i = 0; i < size - 1; i++) {
        int temp = path[i + 1] - path[i];
        if (temp == 1 && M != 1)
            path2.push_back('R');
        else if (temp == -1)
            path2.push_back('L');
        else if (temp > 0)
            path2.push_back('D');
        else if (temp < 0)
            path2.push_back('U');
    }
    return path2;
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M;
    int S = 0;
    fin >> N >> M;
    char matrix[N+2][M+2];
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < M + 2; j++) {
            matrix[i][j] = '0';
        }
    }
    int start, destination;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            fin >> matrix[i][j];
            if (matrix[i][j] == 'S') {
                start = (i - 1) * M + j;
            }
            if (matrix[i][j] == 'T') {
                destination = (i - 1) * M + j;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == '.' || matrix[i][j] == 'S' || matrix[i][j] == 'T' ) {
                S++;
                if (matrix[i][j-1] == '.' || matrix[i][j-1] == 'S' || matrix[i][j-1] == 'T' ) {
                    arr[(i - 1) * M + j].push_back((i - 1) * M + (j - 1));
                }
                if (matrix[i][j+1] == '.' || matrix[i][j+1] == 'S' || matrix[i][j+1] == 'T') {
                    arr[(i - 1) * M + j].push_back((i - 1) * M + (j + 1));
                }
                if ((matrix[i-1][j] == '.' || matrix[i-1][j] == 'S' || matrix[i-1][j] == 'T') && i != 1) {
                    arr[(i - 1) * M + j].push_back((i - 2) * M + j);
                }
                if (matrix[i+1][j] == '.' || matrix[i+1][j] == 'S' || matrix[i+1][j] == 'T') {
                    arr[(i - 1) * M + j].push_back(i * M + j);
                }
            }
        }
    }
    vector <char> temp;
    temp = bfs(N*M + 1, M, start, destination);
    if (temp.empty()) {
        fout << -1;
    } else {
        fout << temp.size() << endl;
        for (int i = 0; i < temp.size(); i++) {
            fout << temp[i];
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

vector <int> arr[100001];

vector <int> bfs (int N) {
    vector <int> d(N+1);
    queue <int> Q;
    for (int i = 0; i <= N; i++) {
        d[i] = N;
    }
    d[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto i : arr[u]) {
            if (d[i] == N) {
                d[i] = d[u] + 1;
                Q.push(i);
            }
        }
    }
    return d;

}
int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");

    int M, N;
    fin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    vector <int> temp;
    temp = bfs(N);
    for (int i = 1; i <= N; i++) {
        fout << temp[i] << " ";
    }
    return 0;
}

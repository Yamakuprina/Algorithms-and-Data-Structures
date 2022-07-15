#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int components[100001];
bool used[100001];
vector <int> arr[100001];

void dfs(int v, int size) {
    used[v] = 1;
    components[v] = size;
    for (int i = 0; i < arr[v].size(); i++) {
        int next_vert = arr[v][i];
        if (!used[next_vert]) {
            dfs(next_vert, size);
        }
    }
}

int main() {
    ifstream fin("components.in");
    ofstream fout("components.out");

    int M, N;
    fin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        if (x != y) {
            arr[x].push_back(y);
            arr[y].push_back(x);
        } else {
            arr[x].push_back(y);
        }
    }

    for (int i = 1; i <= N; i++) {
        used[i] = 0;
    }

    int size = 1;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            dfs(i, size);
            size++;
        }
    }
    fout << size - 1 << endl;
    for (int i = 1; i <= N; i++) {
        fout << components[i] << " ";
    }

    return 0;
}

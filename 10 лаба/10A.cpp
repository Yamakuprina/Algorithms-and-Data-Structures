#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <int> top;
vector <int> list[100001];
bool used[100001];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < list[v].size(); i++) {
        int next = list[v][i];
        if (!used[next]) {
            dfs(next);
        }
    }
    top.push_back(v);
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        fout << list[i].size() << " ";
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> sorted;
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
    sorted.push_back(v);
}

int main() {

    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(sorted.begin(), sorted.end());
    bool check;

    for (int i = 0; i < sorted.size() - 1; i++) {
        check = false;
        for (int j = 0; j < list[sorted[i]].size(); j++) {
            if (list[sorted[i]][j] == sorted[i  + 1]) {
                check = true;
            }
        }
        if (!check) {
            break;
        }
    }

    if (check) {
        fout << "YES";
    } else {
        fout << "NO";
    }

    return 0;
}

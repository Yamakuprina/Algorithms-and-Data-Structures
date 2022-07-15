#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> list[100001];
char color[100001];
bool check = true;

void dfs(int v, char clr) {
    color[v] = clr;
    for (int i = 0; i < list[v].size(); i++) {
        int next = list[v][i];
        if (color[next] == 'w') {
            if (clr == 'r') {
                dfs(next, 'b');
            }
            if (clr == 'b') {
                dfs(next, 'r');
            }
        } else if (color[next] == clr) {
            check = false;
        }
    }
}

int main() {

    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        if (x != y) {
            list[x].push_back(y);
            list[y].push_back(x);
        } else {
            list[x].push_back(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs(i, 'r');
        }
    }
    if (check) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    return 0;
}

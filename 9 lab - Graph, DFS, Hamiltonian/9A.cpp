#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> sorted;
vector <int> list[100001];
char color[100001];
bool check_cycle = false;

void dfs(int v) {
    color[v] = 'g';
    for (int i = 0; i < list[v].size(); i++) {
        int next = list[v][i];
        if (color[next] == 'w') {
            dfs(next);
        }
        if (color[next] == 'g') {
            check_cycle = true;
        }
    }
    color[v] = 'b';
    sorted.push_back(v);
}

int main() {
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs(i);
        }
    }
    reverse(sorted.begin(), sorted.end());

    if (check_cycle) {
        fout << -1;
    } else {
        for (int i : sorted) {
            fout << i << " ";
            }
    }
    return 0;
}

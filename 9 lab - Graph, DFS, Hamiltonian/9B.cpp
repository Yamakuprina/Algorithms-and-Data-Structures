#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> sorted;
vector <int> list[100001];
int parent[100001];
char color[100001];
int start = -1, finish;


bool dfs(int v) {
    color[v] = 'g';
    for (unsigned i = 0; i < list[v].size(); i++) {
        int next = list[v][i];
        if (color[next] == 'w') {
            parent[next] = v;
            if (dfs(next)) {
                return true;
            };
        } else if (color[next] == 'g') {
            start = next;
            finish = v;
            return true;
        }

    }
    color[v] = 'b';
    return false;
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
        parent[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        if (dfs(i)) {
            break;
        }
    }
    if (start == -1) {
        fout << "NO";
    } else {
        fout << "YES" << endl;

        vector <int> cycle;
        cycle.push_back(start);

        for (int v = finish; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        reverse(cycle.begin(), cycle.end());
        for (auto i : cycle) {
            fout << i << " ";
        }
    }
    return 0;
}

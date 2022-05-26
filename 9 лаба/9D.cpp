#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> sorted;
vector <int> list_1[100001];
vector <int> list_2[100001];
int comp[100001];
char color[100001];

void dfs1(int v) {
    color[v] = 'g';
    for (auto i = 0; i < list_1[v].size(); i++) {
        int next = list_1[v][i];
        if (color[next] == 'w') {
            dfs1(next);
        }
    }
    sorted.push_back(v);
}

void dfs2(int v, int comp_num) {
    color[v] = 'g';
    comp[v] = comp_num;
    for (auto i = 0; i < list_2[v].size(); i++) {
        int next = list_2[v][i];
        if (color[next] == 'w') {
            dfs2(next, comp_num);
        }
    }
}

int main() {

    ifstream fin("cond.in");
    ofstream fout("cond.out");

    int m, n;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list_1[x].push_back(y);
        list_2[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs1(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    int comp_num = 1;
    for (int i = 1; i <= n; i++) {
        int v = sorted[n-i];
        if (color[v] == 'w') {
            dfs2(v, comp_num);
            comp_num++;
        }
    }
    fout << comp_num - 1 << endl;
    for (int i = 1; i <= n; i++) {
        fout << comp[i] << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct tree {
    vector<int> edges;
    int value;
};

void dfs(int cur, vector<tree> &graph, vector<vector<int>> &distances) {
    distances[cur][0] = 0;
    distances[cur][1] = graph[cur].value;

    for (int i = 0; i < graph[cur].edges.size(); i++)
        dfs(graph[cur].edges[i], graph, distances);

    for (int i = 0; i < graph[cur].edges.size(); i++) {
        distances[cur][1] += distances[graph[cur].edges[i]][0];
        distances[cur][0] += max(distances[graph[cur].edges[i]][0], distances[graph[cur].edges[i]][1]);
    }

}


signed main() {
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");

    int n;
    fin >> n;

    vector<tree> graph(n);
    vector<vector<int>> distances(n, vector<int>(2));
    int root = 0;

    int a, b;
    for (int i = 0; i < n; i++) {
        fin >> a >> b;
        if (a != 0) {
            graph[a - 1].edges.push_back(i);
            graph[i].value = b;
        } else {
            root = i;
            graph[i].value = b;
        }
    }

    dfs(root, graph, distances);

    fout << max(distances[root][0], distances[root][1]);

    fin.close();
    fout.close();
}

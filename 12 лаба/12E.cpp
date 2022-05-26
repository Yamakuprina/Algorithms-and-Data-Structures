#include <iostream>
#include <vector>

using namespace std;

struct tree {
    vector<int> edges;
};

void dfs(int cur, vector<tree> &graph, vector<vector<int>> &distances) {
    distances[cur][0] = 0;
    distances[cur][1] = 1;

    for (int i = 0; i < graph[cur].edges.size(); i++) {
        dfs(graph[cur].edges[i], graph, distances);
    }

    for (int i = 0; i < graph[cur].edges.size(); i++) {
        distances[cur][1] += distances[graph[cur].edges[i]][0];
        distances[cur][0] += max(distances[graph[cur].edges[i]][0], distances[graph[cur].edges[i]][1]);
    }

}

int main() {
    int num = 0;
    int root = 0;

    int n;
    cin >> n;

    vector<int> result;
    vector<tree> graph(n);
    vector<vector<int>> distance(n, vector<int>(2));

    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (value != 0) {
            graph[value - 1].edges.push_back(i);
        } else {
            root = i;
        }
    }

    dfs(root, graph, distance);
    cout << max(distance[root][0], distance[root][1]);
}

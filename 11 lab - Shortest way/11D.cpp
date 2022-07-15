#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(long long V, vector<vector<pair<long long, long long>>> &list, long long * &used) {
    used[V] = true;
    for (int i = 0; i < list[V].size(); i++) {
        int to = list[V][i].first;
        if (!used[to])
            dfs(to, list, used);
    }
}

int main() {
    ifstream fin("path.in");
    ofstream fout("path.out");

    long long N, M, S;
    fin >> N >> M >> S;
    vector<vector<pair<long long, long long>>> list(N+1);
    long long INF = 2*1e18;

    for (int i = 0; i < M; i++) {
        int U, V;
        long long weight;
        fin >> U >> V >> weight;
        list[U].push_back(make_pair(V, weight));
    }
    auto *dist = new long long[N + 1];
    auto *used = new long long[N + 1];

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[S] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < list[j].size(); k++) {
                long long to = list[j][k].first;
                long long weight = list[j][k].second;
                if ((dist[j] < INF) && (dist[to] > dist[j] + weight)) {
                    dist[to] = max(-INF, dist[j] + weight);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            long long to = list[i][j].first;
            long long weight = list[i][j].second;
            if ((dist[i] < INF) && (dist[to] > dist[i] + weight) && !used[to]) {
                dfs(to, list, used);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF)
            fout << '*' << endl;
        else if (used[i])
            fout << '-' << endl;
        else
            fout << dist[i] << endl;
    }
    delete [] used;
    delete [] dist;
    return 0;
}

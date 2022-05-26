#include <fstream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;


int main() {
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");

    int N, M;
    fin >> N >> M;

    vector<vector<pair<int, int>>> list(N+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for (int i = 0; i < M; i++) {
        int U, V, weight;
        fin >> U >> V >> weight;
        list[U].push_back(make_pair(V, weight));
        list[V].push_back(make_pair(U, weight));
    }

    vector<bool> used(N + 1, false);
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int U = pq.top().second;
        int dist_ = pq.top().first;
        pq.pop();
        if (dist_ > dist[U])
            continue;
        for (int j = 0; j < list[U].size(); j++) {
            int V_ = list[U][j].first;
            int weight = list[U][j].second;
            if (!used[V_] && dist[V_] > dist[U] + weight) {
                dist[V_] = dist[U] + weight;
                pq.push(make_pair(dist[V_], V_));
            }
        }
        used[U] = true;
    }

    for (int i = 1; i <= N; i++) {
        fout << dist[i] << " ";
    }
    return 0;
}

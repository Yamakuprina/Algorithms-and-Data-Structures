#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define INF 100001
using namespace std;


int main() {
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");

    int N;
    fin >> N;
    int matrix[N+1][N+1];
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++) {
            fin >> matrix[i][j];
        }
    }

    vector<pair <int, pair <int, int>>> edges;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i][j] < INF)
                edges.emplace_back(matrix[i][j], make_pair(i, j));
        }
    }
    int dist[N + 1];
    int parents[N + 1];
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        parents[i] = -1;
    }
    int V;
    for (int i = 0; i < N; i++) {
        V = -1;
        for (auto e : edges) {
            if (dist[e.second.second] > dist[e.second.first] + e.first) {
                dist[e.second.second] = max(-INF, dist[e.second.first] + e.first);
                parents[e.second.second] = e.second.first;
                V = e.second.second;
            }
        }
    }
    if (V == -1) {
        fout << "NO";
    }
    else {

        vector <int> path;
        for (int i = 0; i < N; i++){
                V = parents[V];
        }
        for (int i = V; i != 0; i = parents[i]){
            path.push_back(i);
            if (i == V && path.size() > 1){
                break;
            }
        }
        fout << "YES" << endl;
        fout << path.size() << endl;

        reverse(path.begin(), path.end());
        for (auto i : path){
            fout << i << " ";
        }
    }
    return 0;
}

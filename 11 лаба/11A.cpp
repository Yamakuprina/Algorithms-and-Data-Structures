#include <fstream>
#include <vector>
#define LLONG_MAX  9223372036854775807LL
using namespace std;

int main() {

    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int N, start, finish;
    fin >> N >> start >> finish;
    start--;
    finish--;

    vector <vector <int>> matrix;

    for (int i = 0; i < N; i++){
        matrix.emplace_back();
        for (int j = 0; j < N; j++){
            int tmp;
            fin >> tmp;
            matrix[i].push_back(tmp);
        }
    }

    vector<bool> used(N, false);
    vector<long long> dist(N, LLONG_MAX);
    dist[start] = 0;
    int v = 0;
    long long min_dist;
    for (int i = 0; i < N; i++) {
        min_dist = LLONG_MAX;
        for (int j = 0; j < N; j++) {
            if (!used[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                v = j;
            }
        }
        used[v] = true;
        for (int j = 0; j < N; j++) {
            if (!used[j] && matrix[v][j] != -1 && dist[v] != LLONG_MAX && dist[j] > dist[v] + matrix[v][j])
                dist[j] = dist[v] + matrix[v][j];
        }

    }

    if (dist[finish] == LLONG_MAX) {
        fout << -1;
    } else {
        fout << dist[finish];
    }

    return 0;
}

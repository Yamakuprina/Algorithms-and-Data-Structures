#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

using namespace std;
vector <int> list[100001];
bool used[100001];
bool win[100001];

int main() {

    ifstream fin("game.in");
    ofstream fout("game.out");

    int m, n, pos;
    fin >> n >> m >> pos;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        used[i] = false;
        win[i] = false;
    }

    stack <int> s;
    s.push(pos);

    int cur;
    while (!s.empty()) {
        cur = s.top();
        if (used[cur]) {
            for (auto v : list[cur]) {
                if (!win[v]) {
                    win[cur] = true;
                }
            }
            s.pop();
        }

        used[cur] = true;
        for (auto v : list[cur]) {
            if (!used[v]) {
                s.push(v);
            }
        }
    }

    if (win[pos]) {
        fout << "First player wins" << endl;
    } else {
        fout << "Second player wins" << endl;
    }
    return 0;
}

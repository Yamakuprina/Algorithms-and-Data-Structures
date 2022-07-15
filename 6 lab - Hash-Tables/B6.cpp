#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<string, string>> Table[100001];

int exist(vector<pair<string, string>> A, const string& l) {
    for (int i = 0; i < A.size(); i++)
        if (A[i].first == l)
            return i;
    return 0;
}
int get_hash(string key) {
    int hash_v = 0;
    for(char i : key) {
        hash_v = 27 * hash_v + (int)i;
    }
    return abs(hash_v % 100001);
}


int main() {
    ifstream fin("map.in");
    ofstream fout("map.out");
    string instruction;

    while (fin >> instruction) {

        if (instruction == "put") {

            string x, y;
            fin >> x >> y;
            int h = get_hash(x);
            int b = exist(Table[h], x);

            if (!Table[h].empty() && Table[h][b].first == x)
                Table[h][b].second = y;

            if (Table[h].empty() || Table[h][b].first != x)
                Table[h].emplace_back(x, y);

        } else if (instruction == "delete") {
            string x;
            fin >> x;
            int h = get_hash(x);
            int b = exist(Table[h], x);

            if (!Table[h].empty() && Table[h][b].first == x) {
                swap(Table[h][b], Table[h][Table[h].size() - 1]);
                Table[h].pop_back();
            }
        } else if (instruction == "get") {
            string x;
            fin >> x;
            int h = get_hash(x);
            int b = exist(Table[h], x);

            if (!Table[h].empty() && Table[h][b].first == x) {
                fout << Table[h][b].second << '\n';
            } else {
                fout << "none\n";
            }
        }
    }
    return 0;
}

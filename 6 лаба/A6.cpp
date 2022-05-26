#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> Table[1000001];

unsigned exists(vector<long> a, long x) {
    for (unsigned i = 0; i < a.size(); i++)
        if (a[i] == x)
            return i;
    return 0;
}

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");

    string instructions;

    while (fin >> instructions) {

        if (instructions == "insert") {
            long x;
            fin >> x;
            long h = abs(x % 1000001);
            unsigned b = exists(Table[h], x);

            if (Table[h].empty() || Table[h][b] != x)
                Table[h].push_back(x);


        } else if (instructions == "delete") {
            long x;
            fin >> x;
            long h = abs(x % 1000001);
            unsigned b = exists(Table[h], x);

            if (!Table[h].empty() && Table[h][b] == x) {
                swap(Table[h][b], Table[h][Table[h].size() - 1]);
                Table[h].pop_back();
            }

        } else if (instructions == "exists") {
            long x;
            fin >> x;
            long h = abs(x % 1000001);
            unsigned b = exists(Table[h], x);

            if (!Table[h].empty() && Table[h][b] == x) {
                fout << "true\n";
            } else {
                fout << "false\n";
            }

        }
    }

    return 0;
}

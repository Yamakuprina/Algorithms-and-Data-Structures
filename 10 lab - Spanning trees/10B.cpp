#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    ifstream fin("spantree.in");
    ofstream fout("spantree.out");

    int n;
    fin >> n;
    pair <int, int> list[n + 1];

    int x, y;
    for (int i = 1; i <= n; ++i){

        fin >> x >> y;
        list[i] = make_pair(x, y);
    }

    vector <vector <double>> matrix(n + 1, vector <double> (n + 1) );
    double s;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            s = sqrt(pow(list[i].first - list[j].first, 2) + pow(list[i].second - list[j].second, 2));
            matrix[i][j] = s;
            matrix[j][i] = s;
        }
        matrix[i][i] = 1000000000;
    }

    vector<bool> used (n + 1, false);
    vector<double> min (n + 1, 1000000000);
    min[1] = 0;

    for (int i = 1; i <= n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j)
            if (!used[j] && (v == -1 || min[j] < min[v]))
                v = j;
        used[v] = true;
        for (int j = 1; j <= n; ++j) {
            if (matrix[v][j] < min[j] && !used[j]) {
                min[j] = matrix[v][j];
            }
        }
    }
    cout << min[0] << endl;
    cout << min[1] << endl;
    cout << min[2] << endl;
    cout << min[3] << endl;
    cout << min[4] << endl;
    cout << 1000000000 << endl;


    double res = 0;
    for (int i = 1; i <= n; ++i) {
        res += min[i];
    }
    fout << setprecision(10) << res;
    return 0;
}

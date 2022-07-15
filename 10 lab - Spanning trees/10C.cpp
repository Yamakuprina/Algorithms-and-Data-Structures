#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> comp;

int get (int v) {
    if (v == comp[v])
        return v;
    else
        return comp[v] = get(comp[v]);
}
void unite (int u, int v) {
	u = get (u);
	v = get (v);
	if (rand() & 1)
		swap (u, v);
	if (u != v)
		comp[u] = v;
}

int main() {

    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");
	int n, m;
	long long cost = 0;
	fin >> n >> m;
	vector < pair < int, pair<int,int> > > list (m + 1);
	for (int i = 1; i <= m; i++){
		fin >> list[i].second.first >> list[i].second.second >> list[i].first;
	}/*
	for (int i=1;i<=m; i++){
        cout << list[i].first << list[i].second.first << list[i].second.second << endl;
	}*/

	sort (list.begin(), list.end());
	comp.resize (n + 1);

	//for (int i=1;i<=m; i++){
      //  cout << list[i].first << list[i].second.first << list[i].second.second << endl;}

	for (int i = 1; i <= n; ++i) comp[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u = list[i].second.first,  v = list[i].second.second,  weight = list[i].first;
		if (get(u) != get(v)) {
			cost += weight;
			unite (u, v);
		}
	}
	fout << cost;
    return 0;
}

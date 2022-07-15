#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>

const int size_ = 26;

using namespace std;

struct vertex {
    int next[size_];
    vector<int> term;
    int sf;
    int sp;
};

int main() {
    ifstream fin("search4.in");
    ofstream fout("search4.out");
    vector<vertex> nodes;
    nodes.emplace_back();
    int n;
    fin >> n;
    int cntr = 0;
    for (int i = 0; i < n; ++i) {
        string str;
        fin >> str;
        int cur = 0;
        for (int i = 0; i < str.size(); ++i) {
            const int next = str[i] - 'a';
            if (nodes[cur].next[next] == 0) {
                nodes.emplace_back();
                nodes[cur].next[next] = (int)nodes.size() - 1;
            }
            cur = nodes[cur].next[next];
        }
        nodes[cur].term.push_back(cntr++);
    }
    string text;
    fin >> text;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int ch = 0; ch < size_; ch++) {
            if (nodes[cur].next[ch] == 0) {
                nodes[cur].next[ch] = nodes[nodes[cur].sf].next[ch];
            }
            else {
                int next = nodes[cur].next[ch];
                if (cur != 0) {
                    nodes[next].sf = nodes[nodes[cur].sf].next[ch];
                    if (!nodes[nodes[next].sf].term.empty()) {
                        nodes[next].sp = nodes[next].sf;
                    }
                    else {
                        nodes[next].sp = nodes[nodes[next].sf].sp;
                    }
                }
                q.push(next);
            }
        }
    }
    vector<bool> is(nodes.size());
    vector<bool> answer(cntr);
    int cur = 0;
    for (int i = 0; i < text.size(); ++i) {
        cur = nodes[cur].next[int(text[i] - 'a')];
        int tmp = cur;
        while (!is[tmp]) {
            if (!nodes[tmp].term.empty()) {
                for (auto&& it : nodes[tmp].term)
                    answer[it] = true;
            }
            is[tmp] = true;
            tmp = nodes[tmp].sp;
        }
    }
    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i]) {
            fout << "YES\n";
        }
        else {
            fout << "NO\n";
        }
    }
}

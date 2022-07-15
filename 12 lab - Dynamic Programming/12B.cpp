#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 100000000000;

long long binSearchFirst(vector<long long> &arr, int key) {
    long long left = -1;
    long long right = arr.size();
    while (left < right - 1) {
        long long m = (left + right) / 2;
        if (arr[m] < key)
            left = m;
        else
            right = m;
    }

    return right;
}

vector<long long> findLIS(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> d(n + 1, INF);
    vector<long long> pos(n + 1);
    vector<long long> prev(n);
    long long length = 0;

    pos[0] = -1;
    d[0] = -INF;

    for (int i = 0; i < n; ++i) {
        long long j = binSearchFirst(d, arr[i]);
        if (d[j - 1] < arr[i] && arr[i] < d[j]) {
            d[j] = arr[i];
            pos[j] = i;
            if (i == 0) {
                prev[i] = -1;
            } else {
                prev[i] = pos[j - 1];
            }

            length = max(length, j);
        }
    }

    vector<long long> answer;
    long long p = pos[length];
    while (p != -1) {
        answer.push_back(arr[p]);
        p = prev[p];
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> arr(n);
    vector<long long> p(n + 1, -1);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> answer = findLIS(arr);

    cout << answer.size() << endl;
    for (long long &i : answer) {
        cout << i << ' ';
    }

    return 0;
}

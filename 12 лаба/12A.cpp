#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> distance(n);
    vector<int> prev(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        distance[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j)
            if ((arr[j] < arr[i]) && (1 + distance[j] > distance[i])) {
                distance[i] = 1 + distance[j];
                prev[i] = j;
            }
    }

    int length = distance[0];
    int pos = 0;

    for (int i = 0; i < n; ++i)
        if (distance[i] > length) {
            length = distance[i];
            pos = i;
        }
    cout << length << endl;

    vector<int> answer;
    while (pos != -1) {
        answer.push_back(pos);
        pos = prev[pos];
    }

    reverse(answer.begin(), answer.end());

    for (auto i : answer) {
        cout << arr[i] << ' ';;
    }

}

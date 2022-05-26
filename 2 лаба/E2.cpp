#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int kth(vector<int> &mas, int l, int r, int k) {

    int j = r, i = l;
    int s = (l+r)/2;
    int x = mas[s];
    if (l==r) {
        return mas[k];
    }
    while (i<=j) {
        while (mas[i]<x){
            i++;
        }
        while (mas[j]>x){
            j--;
        }
        if (i<=j) {
            swap(mas[i],mas[j]);
            i++;
            j--;
        }
    }
    if ((k<=j) && (l<=k)){
        return kth(mas,l,j,k);
    }
    if ((i<=k) && (k<=r)) {
        return kth(mas,i,r,k);

    }
}

int main(){

    ifstream fin("kth.in");
    ofstream fout("kth.out");

    int N, K, A, B, C, a1, a2;
    fin >> N >> K;
    fin >> A >> B >> C >> a1 >> a2;

    vector<int> nums(N);
    nums = {a1, a2};
    for (int i = 2; i < N; ++i) {
        nums[i] = (A * nums[i - 2] + B * nums[i - 1] + C);
    }

    kth(nums,0,N-1,K-1);
    int ans = nums[K-1];


    fout << ans ;
    fin.close();
    fout.close();

    return 0;
}

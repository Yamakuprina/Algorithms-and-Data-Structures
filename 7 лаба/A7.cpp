#include <iostream>
#include <fstream>
using namespace std;

struct Tree {
	int key;
	int left;
	int right;
	int parent;
};

int Height (struct Tree* A, int bottom) {
	int l, r;
	if ((A[bottom].left == 0) && (A[bottom].right == 0)) {
		return 1;
	}

	if (A[bottom].left == 0) {
		l = 0;
	} else {
		l = Height(A, A[bottom].left);
	}

	if (A[bottom].right == 0) {
		r = 0;
	} else {
		r = Height(A, A[bottom].right);
	}

	if (l > r) {
		return l + 1;
	} else {
		return r + 1;
	}
}

struct Tree A[200001];

int main(){

    ifstream fin("balance.in");
    ofstream fout("balance.out");
    int n;
    int h;
    int l;
    int r;


    fin >> n;
	if (n == 0){
		fout << 0;
		return 0;
	}

    for (int i = 1; i <= n; i++){
    	fin >> A[i].key >> A[i].left >> A[i].right;
    	A[A[i].left].parent = i;
    	A[A[i].right].parent = i;
	}

    for (int i=1;i<=n; i++){
        l = 0;
        r = 0;
        if (A[i].left != 0){
            l = Height(A, A[i].left);
        }
        if (A[i].right != 0){
            r = Height(A, A[i].right);
        }
        h = r - l;
        fout << h << "\n";
    }


    fin.close();
    fout.close();

	return 0;
}

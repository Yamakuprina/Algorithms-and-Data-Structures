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

    ifstream fin("height.in");
    ofstream fout("height.out");
    int n;
    int bottom;

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

	for (int i = 1; i<= n; i++){
		if (A[i].parent == 0)
			bottom = i;
	}

	fout << Height(A, bottom);
    fin.close();
    fout.close();

	return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

struct Tree {
	int key;
	int left;
	int right;
	int parent;
};

int Check (struct Tree* A, int bottom, int *max, int *min) {
	if (A[bottom].left == 0 && A[bottom].right == 0) {
		*max = A[bottom].key;
		*min = A[bottom].key;
		return 1;
	}

	int l, r, x = -1000000001, y = 1000000001;

	if (A[bottom].left == 0) {
		l = 1;
	} else {
		l = Check(A, A[bottom].left, &x, &y);
		if (A[bottom].key > x && l == 1) {
			if (y < *min) {
				*min = y;
			}
			if (x > *max) {
				*max = x;
			}
		} else {
			return 0;
		}
	}
	x = -1000000001;
	y = 1000000001;
	if (A[bottom].right == 0) {
		r = 1;
	} else {
		r = Check(A, A[bottom].right, &x, &y);
		if (A[bottom].key < y && r == 1) {
			if (x > *max) {
				*max = x;
			}
			if (y < *min) {
				*min = y;
			}
		} else {
			return 0;
		}
	}
	if (A[bottom].key > *max){
		*max = A[bottom].key;
	}
	if (A[bottom].key < *min) {
		*min = A[bottom].key;
	}
	return l * r;
}

struct Tree A[200001];

int main(){

    ifstream fin("check.in");
    ofstream fout("check.out");
    int n;
    int bottom, x = -1000000001, y = 1000000001;

    fin >> n;
	if (n == 0){
		fout << "YES";
		fin.close();
        fout.close();

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

	if (Check(A, bottom, &x, &y)) {
		fout << "YES";
	} else {
		fout << "NO";
	}
    fin.close();
    fout.close();

	return 0;
}

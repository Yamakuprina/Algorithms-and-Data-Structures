#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Tree {
    int key;
    int balance;
    int height;
    Tree* left;
    Tree* right;
};

int Balance(Tree *A) {
    int l_h;
    int r_h;
    if (A == NULL) {
        return 0;
    } else {
        l_h = Balance(A->left);
        r_h = Balance(A->right);
        A->balance = r_h - l_h;
        if (l_h > r_h) {
            A->height = l_h + 1;
        } else {
            A->height = r_h + 1;
        }
        return A->height;
    }

};
int main() {

    ifstream fin("balance.in");
    ofstream fout("balance.out");

    int n;
    int k, l, r;
    fin >> n;
    vector <Tree> A(n);

    for (int i = 0; i < n; i++) {
        fin >> k >> l >> r;
        A[i].key = k;
        if (!l) {
            A[i].left = NULL;
        } else {
            A[i].left = &A[l - 1];
        }
        if (!r) {
            A[i].right = NULL;
        } else {
            A[i].right = &A[r - 1];
        }
        A[i].height = 0;
        A[i].balance = 0;
    }

    Balance(&A[0]);

    for (int i = 0; i < n; i++){
        fout << A[i].balance << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

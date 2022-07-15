#include <iostream>
#include <fstream>

using namespace std;

struct Tree {
    int Key;
    Tree *l;
    Tree *r;
};

Tree* insert(int Key, Tree *&x) {
    if (x == NULL) {
        x = new Tree;
        x -> Key = Key;
        x -> l = NULL;
        x -> r = NULL;
    } else {
        if (x -> Key > Key) {
            insert(Key, x -> l);
        } else if (x -> Key < Key){
            insert(Key, x -> r);
        }
    }
}

bool exist(int dat, Tree *x) {
    if (x == NULL) {
        return false;
    }
    if (dat == x -> Key) {
        return true;
    }
    if (dat < x -> Key) {
        return exist(dat, x -> l);
    } else {
        return exist(dat, x -> r);
    }
}

Tree* minn(Tree *&x) {
    if (x -> l == NULL) {
        return x;
    }
    return minn(x -> l);
}

Tree* next(int dat, Tree *&x) {
    Tree *cur = x;
    Tree *sucs = NULL;
    while (cur != NULL) {
        if (cur -> Key > dat) {
            sucs = cur;
            cur = cur -> l;
        } else {
            cur = cur -> r;
        }
    }
    return sucs;
}

Tree *prev(int dat, Tree *&x) {
    Tree *cur = x;
    Tree *previous = NULL;
    while (cur != NULL) {
        if (cur -> Key < dat) {
            previous = cur;
            cur = cur -> r;
        } else {
            cur = cur -> l;
        }
    }
    return previous;
}

Tree *delete_def(Tree *&x, int dat) {
    if (x == NULL)  {
        return x;
    }
    if (dat < x -> Key) {
        x -> l = delete_def(x -> l, dat);
    } else if (dat > x -> Key) {
        x -> r = delete_def(x -> r, dat);
    } else if (x -> l != NULL && x -> r != NULL) {
        x -> Key = minn(x -> r)->Key;
        x -> r = delete_def(x -> r, x -> Key);
    } else {
        if (x -> l != NULL) {
            x = x -> l;
        } else if (x -> r != NULL) {
            x = x -> r;
        } else
            x = NULL;
    }
    return x;
}

int main() {

    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    Tree* Tree_main = 0;
    string instructions;
    int x;
    while (fin >> instructions) {
        if (instructions == "insert") {
            fin >> x;
            insert(x, Tree_main);
        } else if (instructions == "exists") {
            fin >> x;
            fout << (exist(x, Tree_main) ? "true" : "false") << endl;
        } else if (instructions == "delete") {
            fin >> x;
            Tree_main = delete_def(Tree_main, x);
        } else if (instructions == "next") {
            fin >> x;
            Tree *tmp = next(x, Tree_main);
            if (tmp == NULL) {
                fout << "none" << endl;
            } else {
                fout << tmp -> Key << endl;
            }
        } else if (instructions == "prev") {
            fin >> x;
            Tree *tmp = prev(x, Tree_main);
            if (tmp == NULL) {
                fout << "none" << endl;
            } else {
                fout << tmp -> Key << endl;
            }
        }
    }

    return 0;
}

#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

int main() {

    ifstream fin("search2.in");
    ofstream fout("search2.out");

    string text, pattern;
    int count = 0;
    bool check;


    fin >> pattern >> text;

    vector<int> places;

    int M = pattern.length();
    int N = text.length();

    int Hash_pattern = 0;
    int x = 3;
    long long x_m = pow(x,M);
    int p = 1007;
    vector<int> Hash(N-M+1, 0);

    for (int i=0; i<M;i++){
        Hash_pattern = (Hash_pattern*x + (pattern[i]-'a')) % p;
    }

    for(int i=0;i<M;i++){
        Hash[0] = (Hash[0]*x + (text[i]-'a')) % p;
    }

    for(int i=0; i<(N-M+1);i++){
        Hash[i+1] = (Hash[i]*x - (x_m*(text[i]-'a')) + (text[i+M]-'a')) % p;

        /*for (int i=0; i< Hash.size(); i++){
        fout << Hash[i] << " ";
    }
    fout << endl;*/
    }

    //fout << Hash_pattern << endl;

    for (int i=0; i<N-M+1;i++){
        if (Hash[i]!=Hash_pattern){
            continue;
        }
        check = true;

        for(int j=0; j<M;j++){
            if(text[i+j]!=pattern[j]){
                check = false;
                break;
            }
        }
        if (check){
            places.push_back(i+1);
            count++;
        }
    }

    fout << count << endl;
    for (int i=0; i< places.size(); i++){
        fout << places[i] << " ";
    }

    return 0;
}

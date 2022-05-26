#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string text;

    fin >> text;

    vector<int> prefix(text.length(),0);
    int j = 0;
    int i = 1;

    for(int i = 1; i < text.length(); i++){
        j = prefix[i-1];
        while((j>0)&&(text[j]!= text[i])){
            j = prefix[j-1];
        }
        if(text[j]==text[i]){
            j++;
        }
        prefix[i]=j;
    }

    for (int i=0; i< prefix.size(); i++){
        fout << prefix[i] << " ";
    }

    return 0;
}

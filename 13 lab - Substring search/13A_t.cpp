#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string text, pattern;
    int start;
    int count = 0;
    bool check;

    fin >> pattern >> text;

    vector<int> places;

    int N = text.length();
    int M = pattern.length();

    vector<char> text_sector(N-M);

    for (int i = 0; i < N-M; i++){

    text_sector

    }

    /*
    //fout << pattern << endl;

    for(int i=0; i < (text.length() - pattern.length()+1);i++){
        fout << "i " <<  i << endl;

        if (text[i]==pattern[0]){
            start = i;
            fout << "Here we go" << endl;
            fout << "start " << start << endl;
            fout << "i " <<  i << endl;

            for (int j=1; j < pattern.length(); j++){
                i+=1;
                fout << "Text  " <<  text[i] << endl;
                fout << "Pattern  " <<  pattern[i] << endl;
                if (text[i]==pattern[j]) check = true;
                else {
                    check = false;
                    break;
                }
                fout << "checking " << check << endl;
            }
            if (check==true){
                fout << "Added stuff " << endl;
                fout << endl;
                places.push_back(start+1);
                count+=1;
            }
            i = start;
        }
    }
    fout << count << endl;
    for (int i=0; i< places.size(); i++){
        fout << places[i] << " ";
    }
    */
    return 0;
}

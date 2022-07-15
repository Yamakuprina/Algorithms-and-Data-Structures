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

    for(int i=0; i < (text.length() - pattern.length()+1);i++){

        if (text[i]==pattern[0]){
            start = i;
            check = true;

            for (int j=1; j < pattern.length(); j++){

                i+=1;

                if (text[i]!=pattern[j]){

                    check = false;
                    break;
                }

            }
            if (check==true){

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

    return 0;
}

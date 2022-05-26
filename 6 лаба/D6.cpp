#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Get_El(const string& key, int HashSize){
    int Hash = 0;
    int tmp = 1;
    for (char i : key){
        Hash += tmp * (int)i;
        Hash %= HashSize;
        tmp = (tmp * 27) % HashSize;
    }
    return Hash;
}

struct Set{
    string key;
    vector <vector <string> > element;
    Set(){
        element.resize(311);
    }
};

struct Multi_Map{
    vector < vector<Set> > set;
    Multi_Map(){
        set.resize(100003);
    }
};

Multi_Map Map;

void put(const string& key, const string& el){
    int key_Hash = Get_El(key, 100003);
    for (auto & i : Map.set[key_Hash]){
        if (i.key == key){
            int elHash = Get_El(el, 311);
            for (const auto & j : i.element[elHash]){
                if (j == el)
                    return;
            }
            i.element[elHash].push_back(el);
            return;
        }
    }
    Set* new_Set = new Set;
    new_Set->key = key;
    new_Set->element[Get_El(el, 311)].push_back(el);
    Map.set[key_Hash].push_back(*new_Set);
    delete new_Set;
}

void del(const string& key, const string& el){
    int key_Hash = Get_El(key, 100003);
    for (auto & i : Map.set[key_Hash]){
        if (i.key == key){
            int elHash = Get_El(el, 311);
            for (int j = 0; j < i.element[elHash].size(); j++){
                if (i.element[elHash][j] == el) {
                    i.element[elHash].erase(i.element[elHash].begin() + j);
                    return;
                }
            }
        }
    }
}

void deleteAll(const string& key){
    int key_Hash = Get_El(key, 100003);
    for (auto & i : Map.set[key_Hash]){
        if (i.key == key){
            for(auto & j : i.element){
                while(!j.empty())
                    j.pop_back();
            }
            return;
        }
    }
}

vector<string> Get (const string& key){
    vector<string> Result;
    int key_Hash = Get_El(key, 100003);
    for (auto & i : Map.set[key_Hash]){
        if (i.key == key){
            for(auto & j : i.element){
                for(const auto & k : j) {
                    Result.push_back(k);
                }
            }
            return Result;
        }
    }
    return Result;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("multimap.in");
    fout.open("multimap.out");

    while(!fin.eof()) {
        string instruction;
        fin >> instruction;

        if (instruction == "put") {
            string first, second;
            fin >> first >> second;
            put(first, second);
        }
        if (instruction == "delete") {
            string first, second;
            fin >> first >> second;
            del(first, second);
        }
        if (instruction == "deleteall") {
            string first;
            fin >> first;
            deleteAll(first);
        }
        if (instruction == "get") {
            string first;
            fin >> first;
            vector<string> get_ = Get(first);
            fout << get_.size() << ' ';
            for (const string& i : get_)
                fout << i << ' ';
            fout << "\n";
        }

    }
    fin.close();
    fout.close();
    return 0;
}

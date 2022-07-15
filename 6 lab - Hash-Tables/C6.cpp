#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct List_El {
    string key;
    string value;
    struct List_El* next;
    struct List_El* prev;
    struct List_El* next_Queue;
};

class List {
    List_El* list;
public:
    List() {
        list = new List_El();
        list->value = list->key = "";
        list->next_Queue = nullptr;
    }
    void insert(const string& key, const string& value, List_El *head) {
        List_El *new_El = exist(key);
        if (exist(key) == nullptr) {
            new_El = new List_El;
            new_El->key = key;
            new_El->value = value;
            new_El->next_Queue = list->next_Queue;
            list->next_Queue = new_El;
            List_El *Tail = head->prev;
            Tail->next = new_El;
            head->prev = new_El;
            new_El->next = head;
            new_El->prev = Tail;
        } else
            new_El->value = value;
    }
    void del(const string& key) {
        List_El *cur_el = list;
        while (cur_el->next_Queue != nullptr) {
            if (cur_el->next_Queue->key == key) {
                List_El *will_delete = cur_el->next_Queue;
                cur_el->next_Queue = cur_el->next_Queue->next_Queue;
                List_El *prev_element = will_delete->prev, *NextNode = will_delete->next;
                will_delete->prev->next = NextNode;
                will_delete->next->prev = prev_element;
                delete will_delete;
                return;
            } else
                cur_el = cur_el->next_Queue;
        }
    }
    List_El* exist(const string& key) {
        List_El *cur_El = list;
        while (cur_El->next_Queue != nullptr) {
            if (cur_El->next_Queue->key == key)
                return cur_El->next_Queue;
            cur_El = cur_El->next_Queue;
        }
        return nullptr;
    }
};

class LinkedMap
{
    vector <List> lm;
    List_El *head;
    static int GetEl(const string& key) {
        int hash_value = 0;
        for(char i : key) {
            hash_value = 27 * hash_value + i;
        }
        return abs(hash_value % 1000001);
    }
public:
    LinkedMap() {
        lm.resize(1000001);
        head = new List_El;
        head->prev = head->next = head;
    }
    void insert(const string& key, const string& value) {
        lm[GetEl(key)].insert(key, value, head);
    }
    void del(const string& key) {
        lm[GetEl(key)].del(key);
    }
    string get(const string& key) {
        List_El *result = lm[GetEl(key)].exist(key);
        if (result == nullptr)
            return "none";
        else
            return result->value;
    }
    string next(const string& x)
    {
        List_El *result = lm[GetEl(x)].exist(x);
        if (result == nullptr || result->next == head)
            return "none";
        else
            return result->next->value;
    }
    string prev(const string& key)
    {
        List_El *result = lm[GetEl(key)].exist(key);
        if (result == nullptr || result->prev == head) {
            return "none";
        }
        else {
            return result->prev->value;
        }
    }
};

int main() {
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string key;
    string value;
    string instruction;
    LinkedMap Map;
    while(fin >> instruction) {
        if (instruction == "put") {
            fin >> key >> value;
            Map.insert(key, value);
        } else if (instruction == "delete") {
            fin >> key;
            Map.del(key);
        } else if (instruction == "get") {
            fin >> key;
            fout << Map.get(key) << "\n";
        } else if (instruction == "next") {
            fin >> key;
            fout << Map.next(key) << "\n";
        } else if (instruction == "prev") {
            fin >> key;
            fout << Map.prev(key) << "\n";
        }
    }
}

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct Label
{
	int t;
	string s;
};
struct Queue
{
	unsigned short int number;
	struct Queue* next;
};

void Push (struct Queue** top, unsigned short int element)
{
	struct Queue* head = new struct Queue;
    head->number = element;
    head->next = *top;
    *top = head;
}

unsigned short int Pop (struct Queue** top)
{
	unsigned short int tmp;
	struct Queue* list = *top;
	if ((list)->next == NULL)
	{
		tmp = (list)->number;
		delete list;
		*top = NULL;
	} else {
		while ((list)->next->next != NULL)
		{
			list = (list)->next;
		}

		tmp = (list)->next->number;
		delete (list)->next;
		(list)->next = NULL;
	}
    return tmp;
}

int main()
{
    ifstream fin("quack.in");
    ofstream fout("quack.out");

    vector <string> res;
    string s, stm;
    Queue* A = NULL;
    unsigned short int regs[26], z;
    unsigned short int x, y;
    char stmp;
    int t = -1;
    vector <Label> lab;
	Label p;
    for (int i = 0; i < 26; i++) {
    	regs[i] = 0;
	}
    while (fin >> s) {
    	t++;
    	res.push_back(s);
    	if (s[0] == ':') {
			p.t = t;
			p.s = s.erase(0, 1);
			lab.push_back(p);
		}
	}
    for (int i = 0; i <= t; i++) {
    	s = res[i];
		switch (s[0])
		{
		case '+' :
			Push(&A, (Pop(&A)+Pop(&A)) % 65536);
			break;

		case '-' :
			x = Pop(&A);
			y = Pop(&A);
			x = x - y;
			if (x < 0) {
				x = 65536 - x;
			}
			Push(&A, (x % 65536));
			break;

		case '*' :
			Push(&A, (Pop(&A)*Pop(&A)) % 65536);
			break;

		case '/' :
			x = Pop(&A);
			y = Pop(&A);
			if (y == 0) {
				Push(&A, 0);
			} else {
				Push(&A, x / y);
			}
			break;

		case '%' :
			x = Pop(&A);
			y = Pop(&A);
			if (y == 0) {
				Push(&A, 0);
			} else {
				Push(&A, x % y);
			}
			break;

		case '>' :
			regs[s[1] - 'a'] = Pop(&A);
			break;

		case '<' :
			Push(&A, regs[s[1] - 'a']);
			break;

		case 'P' :
			if (s.size() == 1) {
				fout << Pop(&A) << "\n";
			} else {
				fout << regs[s[1] - 'a'] << "\n";
			}
			break;

		case 'C' :
			if (s.size() == 1) {
				stmp = Pop (&A) % 256;
				fout << stmp;
			} else {
				stmp = regs[s[1] - 'a'] % 256;
				fout << stmp;
			}
			break;

		case 'J' :
			stm = s.erase(0, 1);
			for (int j = 0; j < lab.size(); j++) {
				if (lab[j].s == stm) {
					i = lab[j].t;
				}
			}
			break;

		case 'Z' :
			if (regs[s[1] - 'a'] == 0) {
				s.erase(0, 2);
				for (int j = 0; j < lab.size(); j++) {
					if (lab[j].s == s) {
						i = lab[j].t;
					}
				}
			}
			break;

		case 'E' :
			if (regs[s[1] - 'a'] == regs[s[2] - 'a']) {
				s.erase(0, 3);
				for (int j = 0; j < lab.size(); j++) {
					if (lab[j].s == s) {
						i = lab[j].t;
					}
				}
			}
			break;

		case 'G' :
			if (regs[s[1] - 'a'] > regs[s[2] - 'a']) {
				s.erase(0, 3);
				for (int j = 0; j < lab.size(); j++) {
					if (lab[j].s == s) {
						i = lab[j].t;
					}
				}
			}
			break;

		case 'Q' :
			i = t + 1;
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':

			stringstream sstream(s);
			sstream >> z;
			Push(&A, z);
			break;
		}
	}

    return 0;
}

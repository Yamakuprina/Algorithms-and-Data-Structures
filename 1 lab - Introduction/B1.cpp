#include <iostream>
#include <fstream>

using namespace std;

int main(){

long long a;
long long b;
ifstream fin("aplusbb.in");
ofstream fout("aplusbb.out");
fin >> a >> b;
fout << a+b*b;
fin.close();
fout.close();

return 0;
}

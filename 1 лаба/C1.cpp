#include <iostream>
#include <fstream>

using namespace std;

int max(int first_num, int second_num){

if (first_num >= second_num) return first_num;
else return second_num;
}

int main(){

ifstream fin("turtle.in");
ofstream fout("turtle.out");

int height, width;
fin >> height >> width;




return 0;
}

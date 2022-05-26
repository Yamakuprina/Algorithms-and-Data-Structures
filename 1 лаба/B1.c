#include <stdio.h>
#include <math.h>



int main(){

long long a;
long long b;
FILE *fin,*fout;
fin = fopen("aplusbb.in", "r");
fout = fopen("aplusbb.out", "w");
fscanf(fin, "%lld%lld", &a, &b);
fprintf(fout, "%lld", a+b*b);
fclose(fin);
fclose(fout);

return 0;
}

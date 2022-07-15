#include <stdio.h>
#include <math.h>



int main(){

long long a = 0;
long long b = 0;
FILE *fin,*fout;
fin = fopen("aplusb.in", "r");
fout = fopen("aplusb.out", "w");
fscanf(fin, "%d%d", &a, &b);
fprintf(fout, "%d", a+b);
fclose(fin);
fclose(fout);

return 0;
}

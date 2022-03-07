#include <stdio.h>

int sumFib1(int n, int s)
{
int sum=0;
if (n<1) {
return 0;
}
else if(n==1){
return 1;
}
if (s!=0) {
while (n>0) {
sum=sum+sumFib1(n,0);
n=n-1;
}
return sum;
}
return sumFib1(n-1,0)+sumFib1(n-2,0);
}

int main(void) {
	printf("%d\n", sumFib1(6, 1));
}

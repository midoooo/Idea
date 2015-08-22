#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() {
	 long double a, b;
	 long int c;
	scanf("%Lf %Lf %li", &a, &b, &c);
	 long double series[9000];
	 long int i;
	 series[0]=0;
	series[1] = a;
	series[2] = b;

	for (i = 3; i <= c; i++)
	{
	     long double temp=(series[i-1]*series[i-1]);
		series[i] = temp + series[i-2];
		///printf("%llu\n",series[i]);
	}
	char aa[200];
	sprintf(aa, "%0.0Lf", series[c]);
	printf("%s", aa);
	return 0;
}

#include <stdio.h>

/* print Celsius-Fahrenheit Table
   for celsius = 0, 20, ..., 300; floating point version */

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;    /* lower limit of temperature table */
	upper = 300;  /* upper limit */
	step = 20;    /* step size */

	celsius = lower;

	printf("============\n   C  |  F  \n============\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32 ;
		printf("%5.1f |  %-4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	printf("============\n");
}

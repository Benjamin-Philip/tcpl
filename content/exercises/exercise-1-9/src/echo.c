#include <stdio.h>

main(){
	int c; /* The current character*/
	int space; /* Whether space has been used */

	while((c = getchar()) != EOF)
		if (c != ' ' ){
			putchar(c);
			space = 0;
		}

		else if (!space) {
			putchar(' ');
			space = 1;
		}
}

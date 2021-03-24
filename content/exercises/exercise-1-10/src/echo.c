#include <stdio.h>

main(){
	int c; /* The current character */

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t"); /*Note the 2 backlashes. I need
					* to escape the backlashes, or
					* I will literally print a tab.*/
		}

		else if (c == '\b') {
			printf("\\b");
		}

		else if (c == '\\') {
			printf("\\\\");
		}

		else {
			putchar(c);
		}
	}
}

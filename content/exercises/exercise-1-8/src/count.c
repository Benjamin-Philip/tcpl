#include <stdio.h>

/* Count spaces, tabs, and newlines */
main()
{
	int c;
	int newline, tab, space;

	newline = 0;
	tab = 0;
	space = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n')
			newline++;
		else if(c == '\t')
			tab++;
		else if (c == ' ')
			space++;

	printf("Newlines: %d\n", newline);
	printf("Tabs: %d\n", tab);
	printf("Space: %d\n", space);


}

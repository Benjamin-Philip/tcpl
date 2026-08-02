#include <stdio.h>

main()
{
    int prevc, curc;

    prevc = 'a';
    while ((curc = getchar()) != EOF) {
        if (!((curc == ' ') && (prevc == ' ')))
            putchar(curc);

        prevc = curc;
    }
}

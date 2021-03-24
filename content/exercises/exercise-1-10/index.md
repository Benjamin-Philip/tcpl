---
title: Exercise 1-10
date: 2021-03-23
---

This is the {{<tex>}}10^{th}{{</tex>}} exercise from Tcpl. Here, we re-write `echo` to print the escape sequences of some hard to type characters.

# The Question

**Exercise 1-10:** WRite a program to copy its input to its output, replacing each tab with `\t`, each backspace with `\b` and each backslash with `\\`. This makes tabs and backslashes visible in an unambiguous way.

# The Answer

For this question, all I think we need to do is check if any of the special
characters has been inputed. If a special character is inputed, we print the
corresponding escape sequence.

## Printing all inputed characters

So a quick program that will print all characters:

```c
#include <stdio.h>

main(){
	int c; /* The current character */

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
```

and testing:

```bash
$ ./echo
Foobar
Foobar
```

## Writing the program for tabs
Now let's implement it for tabs:

```c
#include <stdio.h>

main(){
	int c; /* The current character */

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t"); /*Note the 2 backlashes. I need
                            * to escape the backlashes, or
					        * I will literally print a tab.*/
		}
		else {
                putchar(c);
        }
	}
}
```

and testing:

```bash
$ ./echo
The quick       brown fox..
The quick\tbrown fox..
```

## Writing it for all the special characters

Now that we know how it all works, let's write it for all the special
characters:

```c
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
```

and testing:

```bash
$ ./echo
This is tab:
This is tab:\t
This is a backslash: \
This is a backslash: \\
```

However, I am unable to input a backspace character in my terminal. So, I am
unable to test the functionality.

# Conclusion

Though this problem was not as interesting as the last, It was certainly not
easy. Here is my [C file](src/echo.c) and my [makefile](src/makefile).

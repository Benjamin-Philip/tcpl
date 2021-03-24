---
title: Exercise 1-8
date: "2021-03-19"
---

This is the {{<tex>}}8^{th}{{</tex>}} exercise in Tcpl. Here, we count the
number of tabs, newlines and spaces in input.

# The Question

**Exercise 1-8:** Write a program to count blanks, tabs, and newlines.

# The Answer

Like what was shown in the Line counting example, all we need to do is have a
`while` loop iterating over all the characters in input until, `EOF`. Next, we
need to add one to `tab` if we find a tab, one to `newline` if we find a
newline, and one to `space` if we find a space.

## Hard to type characters

But how do we match these characters? They are hard-to-type characters after
all ? For that we use the *escape sequences* shown in the very first example.
We use `\n` for newline, `\t` for tab. For space, there is no escape sequence.
This is because we can type space using the space bar.

## The End result

Knowing all this, we get the following program:

```c
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
```

## Testing

Now, I didn't test it extensively. I just trusted the compiler to check for
Syntax errors and etc.

One test I did was the following:

```bash
$ cat makefile | ./count
Newlines: 15
Tabs: 2
Space: 16
```

This was using my [makefile](src/makefile).

# Conclusion

We use a `while` loop to iterate over all characters. We use escape sequences to
match hard to type characters.

Here is my [makefile](src/makefile) and my [C file](src/count.c)

---
title: Exercise 1-9
date: 2021-03-23
---

This is the {{<tex>}}9^{th}{{</tex>}} exercise in Tcpl. Here, we write a program
to echo input. However, in a given input, we replace `n` number of blanks (where
`n` is <= 1) with a single blank.

# The Question

**Exercise 1-9:** Write a program to copy it input to its output, replacing each
string of one or more blanks by a single blank.

# Assumptions

So this question is slightly vague in the sense, it doesn't explain how to end
input, how *exactly* space are replaced, whether:

"A  Quick     Brown  Fox" becomes: 

1. "A QuickBrownFox"
2. "A Quick Brown Fox"

I am going to assume the latter. I also am going to assume "\n" as end of
string, and `EOF` (Ctrl-D) as end of program. Kind of like `cat -`.

# The Answer

Now that we know *what* our program does, we need to decide *what* is does.
In order to solve this problem, we need to work 1 issue:

> Printing only one space between words

Let's have a single program that will print input till `EOF`:

```c

#include <stdio.h>

main(){
    int c;

    while((c = getchar()) != EOF)
        putchar(c);
}

```

Let's compile and try it out:

```bash
$ ./echo
The       quick brown fox jumps over the lazy dog
The       quick brown fox jumps over the lazy dog
```

As you can see, exactly what we input is printed back.

Now, let's write it in such a way that it won't print blanks at all:

```c
#include <stdio.h>

main(){
    int c;

    while((c = getchar()) != EOF)
	    if (c != ' ' ){
		  putchar(c);
	    }
}
```

And testing:

```bash
$ ./echo
The Quick Brown Fox..
TheQuickBrownFox..
```

Now consider having a boolean value `space`, which we'll use to denote if space
has been used yet. By default it is false (`int` 0), but, if we come across a
space, we'll set it to true. When we come across a character that is not a
space, we'll set it to false.

Now, when we come across with a space we'll print a space only **if it is
false**.

This gives us the following program:

```c
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
```

testing:

```bash
$ ./echo
The       Quick         Brown Fox Jumps Over The    Dog.
The Quick Brown Fox Jumps Over The Dog.
```

That's it! We have solved the problem!

# Conclusion

I personally found this question rather interesting.. You can find 
my [Cfile](src/echo.c) and my [makefile](src/makefile) at the links.

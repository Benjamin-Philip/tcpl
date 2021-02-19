---
title: Tcpl Exercise 1-2
date: "2021-02-18"
---

This is the {{<tex>}}2^{nd}{{</tex>}} exercise from Tcpl.
Here we try to find more escape sequences.

# The Question

**Exercise 1-2:** Experiment to find out what happens when `printf`'s argument
string contains *\c*, where *c** is some character not above listed.

# The Answer

We are supposed to experiment, right ?

Let's write a simple program with multiple functions which each print a
different escape sequence

```c
#include <stdio.h>

main()
{
	print_v();
	print_f();
	print_d();
}

print_v()
{
	printf("Printing \\v:");
	printf("\v");
	printf("end\n");
}

print_f()
{
	printf("Printing \\f:");
	printf("\f");
	printf("end\n");
}

print_d()
{
	printf("Printing \\d:");
	printf("\d");
	printf("end\n");
}
```

and running it after compiling:

```bash
$ ./escape
Printing \v:
            end
Printing \f:
            end
Printing \d:dend
```

Well, the only thing that we found out is that `\v` and `\f` are escape
sequences and that `\d` is not.

We don't know *what* the two escape sequences print. Even if we **do** find more
sequences, we don't know *what* they print. This just seems boring. So
here is a [Wikipedia Link](https://en.wikipedia.org/wiki/Escape_sequences_in_C
"Answer") to the Answer.

Here is my [C file](src/escape.c) and my [makefile](src/makefile)

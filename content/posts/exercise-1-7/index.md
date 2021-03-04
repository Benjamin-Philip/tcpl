---
title: Tcpl Exercise 1-7
date: "2021-03-04"
---

This is the {{<tex>}}7^{th}{{</tex>}} Exercise in Tcpl. Here, we find the value
of `EOF`.

# The Question

**Exercise 1-7:** Write a program to print the value of `EOF`.

# The Answer

Look at the code the authors gave us for copying input to output:

```c
#include <stdio.h>
/* copy input to output; 1st version */

main(){
        int c;

        while((c = getchar()) != EOF)
                putchar(c);
}

```

You will notice that `c` is an integer. It is being compared to `EOF` which is
a constant. This leads me to believe that `EOF` is of integer type.

So typical of C. Using integers for important values

So, we can simple print the constant:

```c
#include <stdio.h>

main(){
	printf("This is EOF: %d\n", EOF);
}
```

and on running, we find:

```bash
$ ./puteof
This is EOF: -1
```

# Conclusion

The value of `EOF` is -1.

Here is my [C file](src/puteof.c) and my [makefile](src/makefile).

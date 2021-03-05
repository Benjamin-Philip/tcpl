---
title:  Exercise 1-5
date: 2021-02-24 
---

This is the {{<tex>}}5^{th}{{</tex>}} exercise in the Tcpl. Here, we print the
temperature conversion table in reverse order.

# The Question

**Exercise 1-5:**  Modify the temperature conversion program to print the table
in reverse order, that is, from 300 degrees to 0.

# The Answer

The following is the program to print the table using a `for` loop.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */

main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

Look at the `for` statement

```c
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
```

`fahr` starts at zero:

```c
fahr = 0;
```

Until it is greater than or equal to 300.

```c
fahr <= 300;
```

and then we increment by 20:

```c
fahr = fahr + 20
```

We want the for loop to run in reverse - that is, start at 300, and end at 0.
But in order to reach 0 *from* 300, we need to *decrement*. The number used to
increment was 20. So we'll use that to decrement (or use its additive inverse
and increment.)

So a summary:

1. We start at 300
2. We end at 0
3. We decrement by 20.

All this makes for the following `for` loop.

```c
for (fahr = 300; fahr >= 0; fahr = fahr - 20)
```

and Rewriting the program, and running:

```bash
$ ./temp
300  148.9
280  137.8
260  126.7
240  115.6
220  104.4
200   93.3
180   82.2
160   71.1
140   60.0
120   48.9
100   37.8
 80   26.7
 60   15.6
 40    4.4
 20   -6.7
  0  -17.8
  ```

It works !

Here is my [C file](src/temp.c) and here is my [makefile](src/makefile). 

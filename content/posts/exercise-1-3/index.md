---
title: Tcpl Exercise-1-3
date: "2021-2-19"
---

This is the {{<tex>}}3^{rd}{{</tex>}} exercise from Tcpl. Here we write a
program to print out the Fahrenheit to Celsius Table. We even beautify it and
give it header!

# The Question

**Exercise 1-3:** Modify the temperature conversion program to print a heading
above the table.

# The Answer

This should be fairly easy. All we need to do is Print a Header.

This is the temperature conversion program:

```c
#include <stdio.h>

/* print Fahrenheit-Celsius Table
   for farh = 0, 20, ..., 300; floating point version */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;    /* lower limit of temperature table */
	upper = 300;  /* upper limit */
	step = 20;    /* step size */

	fahr = lower;
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

}
```

We need to have an header. Let's say it looked like this:

```
=======
 F | C
=======
```

Of course, we would like "F" and "C" right-justed. 

However, it's not been mentioned that we must use the right justing
functionality that C has. So let us do the most simplest thing possible - Type
in the string manually:

```c
printf("==========\n  F  |  C  \n==========\n");
```

Let's see how that looks. (I have put it just above the while loop.):

```bash
$ ./temp
==========
  F  |  C
==========
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

Hmmm. 2 things:

1. The Fahrenheit header is bigger than the celsius header.
2. We should put a "|" (pipe) to separate the celsius readings from Fahrenheit.

By adding a pipe, We increase the overall length of the output, and hence, we
can solve the first problem.

So:

```c
while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f  |%6.1f\n", fahr, celsius);
		fahr = fahr + step;
}	
```

And consequently:

```c
printf("============\n  F  |   C  \n============\n");
```

Let's see how it looks running it:

```bash
$ ./temp
============
  F  |   C
============
  0  | -17.8
 20  |  -6.7
 40  |   4.4
 60  |  15.6
 80  |  26.7
100  |  37.8
120  |  48.9
140  |  60.0
160  |  71.1
180  |  82.2
200  |  93.3
220  | 104.4
240  | 115.6
260  | 126.7
280  | 137.8
300  | 148.9
```

Now that looks good! doesn't it ?

Let's add a footer after the while loop:

```c
printf("============\n");
```

And running:

```bash
$ ./temp
============
  F  |   C
============
  0  | -17.8
 20  |  -6.7
 40  |   4.4
 60  |  15.6
 80  |  26.7
100  |  37.8
120  |  48.9
140  |  60.0
160  |  71.1
180  |  82.2
200  |  93.3
220  | 104.4
240  | 115.6
260  | 126.7
280  | 137.8
300  | 148.9
============
```

Even better!

# Conclusion

Conversion tables need a header and a footer and the best solutions are the
simplest ones. 

Here's my [C file](src/temp.c) and my [makefile](src/makefile).

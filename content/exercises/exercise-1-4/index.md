---
title:  Exercise 1-4
date: "2021-02-20"
---

This is the {{<tex>}}4^{th}{{</tex>}} exercise in Tcpl. Here, we write a Celsius
to Fahrenheit table.

# The Question

**Exercise 1-4:** Write a program to print the corresponding Celsius to
Fahrenheit table.

# The Answer

## Finding Fahrenheit to Celsius

This is not too difficult. The following is the formula for Celsius from
Fahrenheit:

{{<tex display="true">}}\text{C} = \frac{5}{9} \times (\text{F} - 32){{</tex>}}

With some simplification, we get {{<tex>}}\text{F} \rightarrow
\text{c}{{</tex>}}:

{{<tex display="true">}}
\begin{aligned}
  \text{C} &= \frac{5}{9} \times {\text{F} - 32}\\
  \text{C} \times \frac{9}{5} &= \text{F} - 32\\
  \text{C} \times \frac{9}{5} + 32 &= \text{F}\\
  \text{F} &= \text{C} \times \frac{9}{5} + 32\\ 
\end{aligned}
{{</tex>}}

## Writing the Code

Let's just copy the previous code:

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

	printf("============\n  F  |   C  \n============\n");
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f  |%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	printf("============\n");
}
```

Now, we increment `celsius` instead of `fahr`. We compute `fahr`, print `celsius`
before `fahr` and compare `celsius` with `upper`

Now keeping in mind, all those things, I wrote the following code:

```c
#include <stdio.h>

/* print Celsius-Fahrenheit Table
   for celsius = 0, 20, ..., 300; floating point version */

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;    /* lower limit of temperature table */
	upper = 300;  /* upper limit */
	step = 20;    /* step size */

	celsius = lower;

	printf("============\n   C  |  F  \n============\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32 ;
		printf("%5.1f |  %-4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	printf("============\n");
}
```

and running it gives:

```bash
$ ./temp
============
   C  |  F
============
  0.0 |  32
 20.0 |  68
 40.0 |  104
 60.0 |  140
 80.0 |  176
100.0 |  212
120.0 |  248
140.0 |  284
160.0 |  320
180.0 |  356
200.0 |  392
220.0 |  428
240.0 |  464
260.0 |  500
280.0 |  536
300.0 |  572
============
```

## The Explanation

I did 3 things: 

1. I computed `fahr` instead of `celsius`
2. I printed `celsius` before `fahr`
3. I did all the necessary things to compute `fahr` in a loop.

### I computed `fahr` instead of `celsius`

The first bit is simple, I simply followed the formula we had derived. 

### I printed `celsius` before `fahr`

This bit wasn't so simple, because I needed it to look good.
The following is the `printf` statement:

```c
printf("%5.1f |  %-4.0f\n", celsius, fahr);
```

Notice `"%-4.0f"`. Here, I am left justing `fahr`. Another thing to notice is
that I mention `celsius` before `fahr`.

### I did all the necessary things to compute `fahr` in a loop

If you look at the previous program, we first `fahr` as `lower`, we then
computed `celsius` and incremented `fahr` by step. Here, I just did the same
thing, but `celsius` in the place of `fahr` and vice versa.

# Conclusion

Americans are morons. If it not for them, we would have been using Celsius for
weather everywhere right now. (Funny thing is that they use Celsius for body
temperature instead of Fahrenheit. Totally got things the other way round! Maybe
we should all use Kelvin ?)

But seriously speaking, there is no conclusion. Here's my [C file](src/temp.c)
and my [makefile](src/makefile).

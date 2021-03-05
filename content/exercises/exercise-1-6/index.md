---
title:  Exercise 1-6
date: "2021-03-01"
---

This is the {{<tex>}}6^{th}{{</tex>}} exercise from Tcpl. Here we try to find
the value of  `true` and `false` in C (ANSI C doesn't have a bool datatype).

# The Question

**Exercise 1-6:** Verify that the expression `getchar() != EOF` is 0 or 1.

# The Answer

The `!=` (not equal) operator returns `false` if a condition is true, and `true`
if a condition is false. At least in languages like `python` or `ruby`. In `C` (ANSI)
however, there isn't a `bool` datatype by default.

## How we find the answer

So, the Question in other words, is we need to find the values of `true` and `false`.

Now, this simplest way to find the value of something, is to print. That means,
we print `true` and `false`. However, we don't know *where* we get `true` and
`false` from. Thus, we must print the evaluation of an expression that returns
`true` or `false`.

The following should work :

```c
printf(1==0);
```

That will return `false`.

And the following:

```c
printf(1==1);
```

will return `true`.

## Compiling

And on compiling:

```bash
$ make
cc bool.c -o bool
'bool.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    4 | main(){
      | ^~~~
bool.c: In function ‘main’:
bool.c:8:9: warning: passing argument 1 of ‘printf’ makes pointer from integer without a cast [-Wint-conversion]
    8 |  printf(1==1);
      |         ^~~~
      |         |
      |         int
In file included from bool.c:1:
/usr/include/stdio.h:332:43: note: expected ‘const char * restrict’ but argument is of type ‘int’
  332 | extern int printf (const char *__restrict __format, ...);
      |                    ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
bool.c:8:2: warning: format not a string literal and no format arguments [-Wformat-security]
    8 |  printf(1==1);
      |  ^~~~~~
bool.c:12:2: warning: null argument where non-null required (argument 1) [-Wnonnull]
   12 |  printf(1==0);
      |  ^~~~~~
bool.c:12:2: warning: null format string [-Wformat-overflow=]
   12 |  printf(1==0);
      |  ^~~~~~~~~~~~
```


## Rewriting our program

Ok, with this error, we now that `booleans` are expressed as integers. Let's
change our statements accordingly.

```c
printf("The value of true: %d\n", 1 == 1);
```


## Running

After compiling, and on running, we get:

```bash
$ ./bool
Value of true: 1
Value of false: 0
```

Quite unexpected! In `ruby`, 0 can be considered `true` and 1 `false`

# Conclusion

As the value of `true` is 1 and `false` 0, `getchar() != EOF` is always 1 or 0.

Here is my [C file](src/bool.c) and my [makefile](src/makefile)

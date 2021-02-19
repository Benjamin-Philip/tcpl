---
title: Tcpl Exercise-1-1
date: "2021-02-18"
---

This is the very {{<tex>}}1^{st}{{</tex>}} Exercise in "The C Programming
Language" (which I decided to shorten to tcpl). Here we write the most famous
programming in history - `hello-world`

# The Exercise

**Exercise 1-1:**. Run the "hello, world" program on your system. Experiment
with leaving out parts of the program, to see what error messages you get.

# The Answer

This isn't to difficult. We just run the program.

```c
#include <stdio.h>

main()
{
    printf("Hello World! \n");
}
```

Let's try to compile it:

```bash
$ gcc hello-world.c -o hello-world
hello-world.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    3 | main()
      | ^~~~
```

Great! The program itself is not very good. This is probably because gcc is a
very good compiler and frowns on missing out some parts.

Let's try to run it:

```bash
$ ./hello-world
Hello World!
```

Now Let's see what happens when we remove the first line:

```c
main()
{
    printf("Hello World! \n");
}
```

And compiling:

```bash
make -k 
cc     hello-world.c   -o hello-world
hello-world.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    1 | main()
      | ^~~~
hello-world.c: In function ‘main’:
hello-world.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    3 |     printf("Hello World! \n");
      |     ^~~~~~
hello-world.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’
hello-world.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | main()
```

Okay, so `stdio.h` seems to be the standard library

What if we remove the the parantheses at `main`:

```c
#include <stdio.h>

main
{
    printf("Hello World! \n");
}
```

and compiling:
```
make -k 
cc     hello-world.c   -o hello-world
hello-world.c:4:1: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token
    4 | {
      | ^
make: *** [<builtin>: hello-world] Error 1
make: Target 'all' not remade because of errors.
```

Ok, `C` doesn't like that as well.

I suppose `gcc` will pass a similar error if the take away the semicolon, or the
brackets.

# Conclusion

Brian Kernighan and Dennis Ritchie know `C`'s syntax.

Here's my [C file](src/hello-world.c) and my [makefile](src/makefile).

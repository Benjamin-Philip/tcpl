---
title: "Exercise 1-11"
date: 2021-03-29T15:58:07+05:30
---

This is the {{<tex>}}11^{th}{{</tex>}} exercise from Tcpl. Here we test the example word program.

# The Question

**Exercise 1-11:** How would you test the word count program? What kinds of
input are most likely to uncover bugs if there are any?

# The Answer

I would take a known file, count it using the program `wc`. Then, I will count
it using our program. Let's do that!

## Choosing a file

I decided I will use the source code to our example program. Though, it's not
the best example, it's more likely to contain "words" that our program will
accept but `wc` will reject.

**Note:** I typed out the entire source file from hand. So, if you want to test
this on your machine, you should probably download [it](src/wc.c).

## Running wc

Now we need to run wc. `wc` by default, prints newline, word, and byte counts.
Since our program counts characters as well, we need to pass some flags to
override the default:

- `l` to count new lines
- `w` to count words
- `m` to count chars

**Note:** I use [GNU coreutils](https://www.gnu.org/software/coreutils/). You
might want to check if you use the FreeBSD implementation if you are on a Mac.

so running:

```bash
$ wc wc -lwm
 25  90 427 wc.c
 ```

The first value is the word count, the second the newline count, and the last
the character count.

## Running our homebrew

Now let's run our implementation:

```bash
$ cat wc.c | ./wc
25 90 427
```

Well! I wasn't expecting this! It appears that gnu's `wc` is as naive as our
homebrew! I can't think of any other efficient manner of testing than comparing
our wc to the gnu wc. 

## Some possible bugs

The only place I think the program can go wrong is with what english considers
as a word. Eg: up-to-date, long-term etc. Other than that, I can't think of
anything - our program is doing exactly what we want.

# Conclusion

I would test this program using `wc`. I also think that this program is bug
free, with the exception of compound words, which are basically 2 different
squashed together, but hyphenated.

Here is my [makefile](src/makefile), and my [source file](src/wc.c).

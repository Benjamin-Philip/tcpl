---
title: "{{ replace .Name "exercise-" "Exercise " | title }}"
date: {{ .Date }}
---

# The Question

**{{ replace .Name "exercise-" "Exercise " | markdownify }}:**

# The Answer

# Conclusion

Here is my [makefile](src/makefile)

# Bonus 20 - Dynamic Arrays and Memory

Fix `dynarray.cpp`, then run it under `valgrind --leak-check=full ./a.out` (or build with `-fsanitize=address -g`) until the report is clean. Questions: what does "shallow copy" mean and why is it dangerous here? Who owns the memory `data` points to?

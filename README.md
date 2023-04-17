**Implemented additonal methods for sorting students.**

**V0.1:**
Vector and array implementation program to get students and their grades from a console. Outputs results to a file.

**V0.2:**
Improved security from V0.1. Added a function to read students and their grades from a file and outputs results to a file.

**V0.3:**
Improved V0.2 by adding user error handling.

**V0.4:**
Improved V0.3 performance. Added a functionality that divides students into two groups. Added program performance times.

**V0.5:**
Improved V0.4 performance. Implemented program with lists and deques. All versions were benchmarked and compared.

**V1.0:**
Full release. Added extra method for sorting students. Easier building for users.

**Student dividing performance::**
| Number of students | Vector method 0 duration (seconds) | Vector method 1 duration (seconds) | List method 0 duration (seconds) | List method 1 duration (seconds) | Deque method 0 duration (seconds) | Deque method 1 duration (seconds) |
|:------------------:|:----------------------------------:|:----------------------------------:|:--------------------------------:|:--------------------------------:|:---------------------------------:|:---------------------------------:|
|        1 000       |                0.01                |                0.02                |               0.01               |               0.01               |                0.01               |                0.02               |
|       10 000       |                0.07                |                1.27                |               0.11               |               0.24               |                0.09               |                0.88               |
|       100 000      |                0.67                |               118.76               |               1.06               |               17.57              |                0.85               |               90.78               |

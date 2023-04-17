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

**Usage:**
1. Choose your container type and run the program.
2. You will be asked if you want to read data from a file (If you have a file to read from press - Y, else press - N). If you proceed with this option you will need to choose which method you will use to sort students (0 OR 1). After that you type your file's name and the results will be outputted into results.txt file.
3. Next you will be asked if you want to generate a file. (If you want to generate press - Y, else press - N). If you proceed with this option you will be asked how much students and grades you want to generate. After your input a file will be generated.
4. Next you will be asked if you want to run a benchmark. (If you want to generate press - Y, else press - N). If you proceed with this option you will be asked which method you will want to use for students diving (0 OR 1). After that you need to choose your file with students and your program will be benchmarked. 
5. After that you will have a manual student and grade reading from console.

**Building:**
To build a project, install CMake and build the project with CMakeLists.txt file.

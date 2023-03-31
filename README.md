# OOP
Added 3 types of containers: vector, list, deque. You can see performance of each container below (Using 10 grades):

| Number of students | Vector container performance (seconds) | List container performance (seconds) | Deque container performance (seconds) |
|:------------------:|:--------------------------------------:|:------------------------------------:|:-------------------------------------:|
|        1 000       |                    0.01                |                   0.01               |                   0.01                |
|       10 000       |                    0.09                |                   0.12               |                   0.11                |
|       100 000      |                    0.84                |                   1.13               |                   1.04                |
|      1 000 000     |                    8.79                |                   11.68              |                   10.93               |
|     10 000 000     |                    87.11               |                   126.12             |                  179.36               |

Performance was tested using these system specifications: AMD Ryzen 3800XT, 16 GB, 1TB SSD.

# OOP
- Changed container to Class.

Below you can see performance differences between two program versions V1.0 and V1.1:

Reading comparison:
| Number of students | V1.0 Performace (seconds)  | V1.1 Performance (seconds) |
|:------------------:|:--------------------------:|:--------------------------:|
|       100 000      |            0.23            |            0.26            |
|      1 000 000     |            2.13            |            2.59            |

Sorting comparison:
| Number of students | V1.0 Performace (seconds)  | V1.1 Performance (seconds) |
|:------------------:|:--------------------------:|:--------------------------:|
|       100 000      |            0.03            |            0.02            |
|      1 000 000     |            0.37            |            0.25            |

Dividing comparison:
| Number of students | V1.0 Performace (seconds)  | V1.1 Performance (seconds) |
|:------------------:|:--------------------------:|:--------------------------:|
|       100 000      |            0.63            |            0.69            |
|      1 000 000     |            6.57            |            7.48            |

Total time comparison:
| Number of students | V1.0 Performace (seconds)  | V1.1 Performance (seconds) |
|:------------------:|:--------------------------:|:--------------------------:|
|       100 000      |            0.87            |            0.97            |
|      1 000 000     |            9.11            |            10.33           |


Below you can see performance differences between optimization flags using V1.1:

1 000 Students:
| Number of students | V1.1 -O1 Performance (seconds)  | V1.1 -O2 Performance (seconds) | V1.1 -O3 performance (seconds) |
|:------------------:|:-------------------------------:|:------------------------------:|:------------------------------:|
|       Reading      |               0.00              |                0.00            |               0.00             |
|       Sorting      |               0.00              |                0.00            |               0.00             |
|       Diving       |               0.02              |                0.01            |               0.01             |
|     Total Time     |               0.02              |                0.01            |               0.01             |

10 000 Students:
| Number of students | V1.1 -O1 Performance (seconds)  | V1.1 -O2 Performance (seconds) | V1.1 -O3 performance (seconds) |
|:------------------:|:-------------------------------:|:------------------------------:|:------------------------------:|
|       Reading      |               0.03              |                0.03            |               0.03             |
|       Sorting      |               0.00              |                0.00            |               0.00             |
|       Diving       |               0.07              |                0.07            |               0.07             |
|     Total Time     |               0.10              |                0.10            |               0.10             |

100 000 Students:
| Number of students | V1.1 -O1 Performance (seconds)  | V1.1 -O2 Performance (seconds) | V1.1 -O3 performance (seconds) |
|:------------------:|:-------------------------------:|:------------------------------:|:------------------------------:|
|       Reading      |               0.26              |                0.26            |               0.26             |
|       Sorting      |               0.03              |                0.02            |               0.02             |
|       Diving       |               0.73              |                0.67            |               0.65             |
|     Total Time     |               1.02              |                0.96            |               0.93             |


1 000 000 Students:
| Number of students | V1.1 -O1 Performance (seconds)  | V1.1 -O2 Performance (seconds) | V1.1 -O3 performance (seconds) |
|:------------------:|:-------------------------------:|:------------------------------:|:------------------------------:|
|       Reading      |               2.70              |               2.64             |               2.63             |
|       Sorting      |               0.33              |               0.29             |               0.25             |
|       Diving       |               7.50              |               7.30             |               7.29             |
|     Total Time     |              10.53              |              10.23             |              10.17             |

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <string>
#include <chrono>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::copy;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;
using std::sort;
using std::deque;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;
using std::find_if;

struct Student
{
    string name, surname;
    deque<int> grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &);
void findAverage(Student &);
void findMedian(Student &);
void getStudent(Student &);
void printStudents(deque<Student>);
void printStudentsToFile(deque<Student>);
void readFile(deque<Student> &, Student &, deque<Student>, deque<Student>);
void generateFile(deque<Student> &, Student &, deque<Student>);
void sortingTest(deque<Student> &, Student &, deque<Student>, deque<Student>);
int getRandomGrade();
void sortStudentsMethodOne(deque<Student>, deque<Student> &);
void sortStudentsMethodTwo(deque<Student>, deque<Student> &, deque<Student> &);
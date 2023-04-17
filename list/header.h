#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
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
using std::list;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;
using std::find_if;

struct Student
{
    string name, surname;
    list<int> grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &);
void findAverage(Student &);
void findMedian(Student &);
void getStudent(Student &);
void printStudents(list<Student>);
void printStudentsToFile(list<Student>);
void readFile(list<Student> &, Student &, list<Student>, list<Student>);
bool sortAscending(Student &, Student &);
void generateFile(list<Student> &, Student &, list<Student>);
void sortingTest(list<Student> &, Student &, list<Student>, list<Student>);
int getRandomGrade();
void sortStudentsMethodOne(list<Student>, list<Student> &);
void sortStudentsMethodTwo(list<Student>, list<Student> &, list<Student> &);
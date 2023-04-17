#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
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
using std::vector;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;
using std::find_if;

struct Student
{
    string name, surname;
    vector<int> grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &);
void findAverage(Student &);
void findMedian(Student &);
void getStudent(Student &);
void printStudents(vector<Student>);
void printStudentsToFile(vector<Student>);
void readFile(vector<Student> &, Student &, vector<Student>, vector<Student>);
void generateFile(vector<Student> &, Student &, vector<Student>);
void sortingTest(vector<Student> &, Student &, vector<Student>, vector<Student>);
int getRandomGrade();
void sortStudentsMethodOne(vector<Student>, vector<Student> &);
void sortStudentsMethodTwo(vector<Student>, vector<Student> &, vector<Student> &);
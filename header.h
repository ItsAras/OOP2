#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

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

struct Student
{
    string name, surname;
    vector<int> grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &tmp);
void findAverage(Student &tmp);
void findMedian(Student &tmp);
void getStudent(Student &tmp);
void printStudents(vector<Student> tmp);
void printStudentsToFile(vector<Student> tmp);
void readFile(vector<Student> &tmp, Student &temp);

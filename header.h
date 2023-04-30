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

class Student
{
    private:
        string name;
        string surname;
        vector<int> grades;
        int exam;
        double average;
        double median;

    public:
        Student() : exam(0) {}
        Student(std::istream& is);
        inline string Name() const { return name; }
        inline string Surname() const { return surname; }
        inline vector<int> Grades() const { return grades; }
        inline int Exam() const { return exam; }
        inline double Average() const { return average; }
        inline double Median() const { return median; }
        void SetName(string name) { name = name; }
        void SetSurname(string surname) { surname = surname; }
        void SetGrade(vector<int> grades) { grades = grades; }
        void SetExam(int exam) { exam = exam; }
        void SetAverage(double average) { average = average; }
        void SetMedian(double median) { average = average; }
        void ClearGrades() { grades.clear(); }
        std::istream& ReadStudent(std::istream&);
        ~Student() {};
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
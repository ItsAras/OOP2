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
        string name, surname;
        int exam;
        double average;
        double median;

    public:
        vector<int> grades;
        Student() : exam(0), average(0), median(0) {}
        Student(std::istream& is);

        inline string getName() const { return name; };
        inline string getSurname() const { return surname; };
        const vector<int>& getGrades() const { return grades; };
        inline int getExam() const { return exam; };
        inline double getAverage() const { return average; };
        inline double getMedian() const { return median; };

        void setName(string name) { this->name = name; };
        void setSurname(string surname) { this->surname = name; };
        void setGrades(vector<int> grades) { this->grades = grades; }
        void setExam(int exam) { this->exam = exam; }
        void setAverage(double average) { this->average = average; }
        void setMedian(double median) { this->median = median; }
        void clearGrades() { grades.clear(); }
        void sortGrades() { sort(grades.begin(), grades.end()); };

        Student(const Student& other)
            : name(other.name), surname(other.surname), exam(other.exam), average(other.average), median(other.median), grades(other.grades)
        {
        }

        Student(Student&& other)
            : name(move(other.name)), surname(move(other.surname)), exam(other.exam), average(other.average), median(other.median), grades(move(other.grades))
        {
        }

        Student& operator=(const Student& other)
        {
            if (this != &other)
            {
                name = other.name;
                surname = other.surname;
                exam = other.exam;
                average = other.average;
                median = other.median;
                grades = other.grades;
            }
            return *this;
        }

        Student& operator=(Student&& other)
        {
            if (this != &other)
            {
                name = move(other.name);
                surname = move(other.surname);
                exam = other.exam;
                average = other.average;
                median = other.median;
                grades = move(other.grades);
            }
            return *this;
        }
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
void runTest();

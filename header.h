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



class Human
{
    protected:
        string name;
        string surname;

    public:
        Human() = default;
        Human(const string& name, const string& surname)
            : name(name), surname(surname) {}

        virtual ~Human() = default;

        inline string getName() const { return name; }
        inline string getSurname() const { return surname; }

        void setName(const string& name) { this->name = name; }
        void setSurname(const string& surname) { this->surname = surname; }
};

class Student : public Human {
private:
    int exam;
    double average;
    double median;
    

public:
    vector<int> grades;

    Student() : exam(0), average(0), median(0) {}
    Student(const string& name, const string& surname)
        : Human(name, surname), exam(0), average(0), median(0) {}
    Student(const string& name, const string& surname, const vector<int>& grades, int exam, double average, double median)
        : Human(name, surname), exam(exam), average(average), median(median), grades(grades) {}

    const vector<int>& getGrades() const { return grades; }
    inline int getExam() const { return exam; }
    inline double getAverage() const { return average; }
    inline double getMedian() const { return median; }

    void setGrades(const vector<int>& grades) { this->grades = grades; }
    void setExam(int exam) { this->exam = exam; }
    void setAverage(double average) { this->average = average; }
    void setMedian(double median) { this->median = median; }
    void clearGrades() { grades.clear(); }
    void sortGrades() { sort(grades.begin(), grades.end()); }

    virtual ~Student() = default;
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;
    Student(Student&& other) noexcept = default;
    Student& operator=(Student&& other) noexcept = default;
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
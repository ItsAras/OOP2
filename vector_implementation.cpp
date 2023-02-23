#include "header.h"

struct Student
{
    string name, surname;
    vector<int> grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &tmp)
{
    int x;
    char userInput;

    do
    {
        cout << "Student's [" << tmp.grades.size() << "] grade: ";
        
        while (!(cin >> x))
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. You need to type a number... ";
        }

        tmp.grades.push_back(x);

        cout << "Press N when finished. Press any key to continue... ";
        cin >> userInput;

    } while (userInput != 'n');
}

void findAverage(Student &tmp)
{
    int sum = 0;

    for (int i = 0; i < tmp.grades.size(); i++)
    {
        sum += tmp.grades[i];
    }

    tmp.average = (double)sum / tmp.grades.size();
}

void findMedian(Student &tmp)
{
    sort(tmp.grades.begin(), tmp.grades.end());

    int middle = (tmp.grades.size()) / 2;
    tmp.median = (tmp.grades.size() - 1) % 2 == 0 ? (tmp.grades[middle - 1] + (double)tmp.grades[middle]) / 2: tmp.grades[middle];
}

void getStudent(Student &tmp)
{
    int x;

    cout << "Student's name and surname: ";
    cin >> tmp.name >> tmp.surname;

    getGrades(tmp);
    findAverage(tmp);
    findMedian(tmp);
    tmp.grades.clear();

    cout << "Student's exam grade: ";

    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. You need to type a number... ";
    }
    
    tmp.exam = x;
}

void printStudents(vector<Student> tmp)
{
    cout << setw(20) << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        cout << setw(20) << i.name << setw(30) << i.surname << setw(30) << fixed << setprecision(2) << 0.4 * i.average + 0.6 * i.exam << setw(15) << setprecision(2) << 0.4 * i.median + 0.6 * i.exam << endl;
    }
}

int main()
{
    char userInput;
    vector<Student> student;
    Student tmp;

    do
    {
        getStudent(tmp);
        student.push_back(tmp);

        cout << "Press N when finished. Press any key to continue... ";
        cin >> userInput;

    } while (userInput != 'n');

    printStudents(student);
}

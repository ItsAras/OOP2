#include "header.h"

struct Student
{
    string name, surname;
    int numberOfGrades;
    int* grades;
    int exam;
    double average;
    double median;
};

void getGrades(Student &tmp)
{
    int x;
    char userInput;
    tmp.numberOfGrades = 1;

    do
    {
        int* temp = new int[tmp.numberOfGrades];

        if (tmp.numberOfGrades > 1) {
            copy(tmp.grades, tmp.grades + tmp.numberOfGrades - 1, temp);
            delete [] tmp.grades;
        }

        tmp.grades = new int[tmp.numberOfGrades];
        cout << "Student's [" << tmp.numberOfGrades << "] grade: ";
        while (!(cin >> x))
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. You need to type a number... ";
        }

        temp[tmp.numberOfGrades - 1] = x;
        copy(temp, temp + tmp.numberOfGrades, tmp.grades);
        delete [] temp;

        tmp.numberOfGrades++;

        cout << "Press N when finished. Press any key to continue adding grades... ";
        cin >> userInput;

    } while (userInput != 'n');
}

void findAverage(Student &tmp)
{
    int sum = 0;

    for (int i = 0; i < tmp.numberOfGrades - 1; i++)
    {
        sum += tmp.grades[i];
    }

    tmp.average = (double)sum / (tmp.numberOfGrades - 1);
}

void findMedian(Student &tmp)
{
    sort(tmp.grades, tmp.grades + tmp.numberOfGrades - 1);

    int middle = (tmp.numberOfGrades - 1) / 2;
    tmp.median = (tmp.numberOfGrades - 1) % 2 == 0 ? (tmp.grades[middle - 1] + (double)tmp.grades[middle]) / 2: tmp.grades[middle];
}

void getStudent(Student &tmp)
{
    int x;

    cout << "Student's name and surname: ";
    cin >> tmp.name >> tmp.surname;

    getGrades(tmp);
    findAverage(tmp);
    findMedian(tmp);
    cout << "Student's exam grade: ";

    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. You need to type a number... ";
    }
    
    tmp.exam = x;
}

void printStudents(Student* tmp, int n)
{
    cout << setw(20) << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(20) << tmp[i].name << setw(30) << tmp[i].surname << setw(30) << fixed << setprecision(2) << 0.4 * tmp[i].average + 0.6 * tmp[i].exam << setw(15) << setprecision(2) << 0.4 * tmp[i].median + 0.6 * tmp[i].exam << endl;
    }
}

int main()
{
    char userInput;
    Student* student;
    Student* tmp;
    int numberOfStudents = 1;

    do
    {
        tmp = new Student[numberOfStudents];

        if (numberOfStudents > 1) {
            copy(student, student + numberOfStudents - 1, tmp);
            delete [] student;
        }

        student = new Student[numberOfStudents];

        getStudent(tmp[numberOfStudents - 1]);
        copy(tmp, tmp + numberOfStudents, student);
        delete [] tmp;

        numberOfStudents++;

        cout << "Press N when finished. Press any key to continue... ";
        cin >> userInput;

    } while (userInput != 'n');

    printStudents(student, numberOfStudents - 1);
}

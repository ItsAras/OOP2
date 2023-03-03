#include "header.h"

int main()
{
    char userInput;
    vector<Student> student;
    Student tmp;

    cout << "Do you want to read data from a file? Y - (YES), N - (NO): ";
    cin >> userInput;

    if (userInput == 'y' || userInput == 'Y') readFile(student, tmp);

    else
    {
        do
        {
            getStudent(tmp);
            student.push_back(tmp);

            cout << "Press N when finished. Press any key to continue... ";
            cin >> userInput;

        } while (userInput != 'n');

        printStudents(student);
    }
}

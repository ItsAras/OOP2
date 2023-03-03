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
        cout << "Student's [" << tmp.grades.size() + 1 << "] grade: ";
        
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
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << left << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        cout << setw(30) << left << i.name << setw(30) << i.surname << setw(30) << fixed << setprecision(2) << 0.4 * i.average + 0.6 * i.exam << setw(15) << setprecision(2) << 0.4 * i.median + 0.6 * i.exam << endl;
    }
}

void printStudentsToFile(vector<Student> tmp)
{   
    ofstream fr("results.txt");
    fr << "------------------------------------------------------------------------------------------------------" << endl;
    fr << setw(30) << left << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    fr << "------------------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        fr << setw(30) << left << i.name << setw(30) << i.surname << setw(30) << fixed << setprecision(2) << 0.4 * i.average + 0.6 * i.exam << setw(15) << setprecision(2) << 0.4 * i.median + 0.6 * i.exam << endl;
    }
}

void readFile(vector<Student> &tmp, Student &temp)
{
    ifstream fd;
    fd.exceptions(std::ios::failbit);
    string fileName;
    string line;
    bool fileExists = false;
    int numberOfGrades = -3;
    int x;

    while (fileExists == false) 
    {
        try
        {
            cout << "File's name (Example: students.txt): ";
            cin >> fileName;
            fd.open(fileName);
            fd.rdbuf();
            fileExists = true;
        } catch(std::ios_base::failure &fail) {
            cout << "Wrong file name provided. Make sure the file exists: ";
        }
    }

    while (fd.peek() != '\n')
    {
        fd >> fileName;
        numberOfGrades++;
    }

    getline(fd, line);

    cout << "Reading file. Please wait... " << endl;

    while(!fd.eof())
    {
        fd >> temp.name >> temp.surname;

        for (int i = 0; i < numberOfGrades; i++)
        {
            fd >> x;
            temp.grades.push_back(x);
        }

        findAverage(temp);
        findMedian(temp);

        fd >> temp.exam;

        tmp.push_back(temp);
        temp.grades.clear();
    }

    sort(tmp.begin(), tmp.end(), [](Student& A, Student& B)
    { 
        return A.name < B.name; 
    });

    fd.close();

    cout << "Program finished. You can find your results in results.txt file." << endl;

    printStudentsToFile(tmp);
}

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

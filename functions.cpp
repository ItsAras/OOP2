#include "header.h"

void getGrades(Student &tmp)
{
    int x;
    char userInput;

    do
    {
        cout << "Student's [" << tmp.Grades().size() + 1 << "] grade: ";
        
        while (!(cin >> x))
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. You need to type a number... ";
        }

        tmp.Grades().push_back(x);

        cout << "Press N when finished. Press any key to continue... ";
        cin >> userInput;

    } while (userInput != 'n');
}

void findAverage(Student &tmp)
{
    int sum = 0;

    for (int i = 0; i < tmp.Grades().size(); i++)
    {
        sum += tmp.Grades()[i];
    }

    tmp.SetAverage((double)sum / tmp.Grades().size());
}

void findMedian(Student &tmp)
{
    sort(tmp.Grades().begin(), tmp.Grades().end());

    int middle = (tmp.Grades().size()) / 2;
    tmp.SetMedian((tmp.Grades().size() - 1) % 2 == 0 ? (tmp.Grades()[middle - 1] + (double)tmp.Grades()[middle]) / 2: tmp.Grades()[middle]);
}

void getStudent(Student &tmp)
{
    string name, surname;
    int x;

    cout << "Student's name and surname: ";
    cin >> name >> surname;

    getGrades(tmp);
    findAverage(tmp);
    findMedian(tmp);
    tmp.Grades().clear();

    cout << "Student's exam grade: ";

    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. You need to type a number... ";
    }
    
    tmp.SetName(name);
    tmp.SetSurname(surname);
    tmp.SetExam(x);
}

void printStudents(vector<Student> tmp)
{
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << left << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        cout << setw(30) << left << i.Name() << setw(30) << i.Surname() << setw(30) << fixed << setprecision(2) << 0.4 * i.Average() + 0.6 * i.Exam() << setw(15) << setprecision(2) << 0.4 * i.Median() + 0.6 * i.Exam() << endl;
    }
}

void printStudentsToFile(vector<Student> tmp, string fileName)
{   
    ofstream fr(fileName + ".txt");
    fr << "------------------------------------------------------------------------------------------------------" << endl;
    fr << setw(30) << left << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    fr << "------------------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        fr << setw(30) << left << i.Name() << setw(30) << i.Surname() << setw(30) << fixed << setprecision(2) << 0.4 * i.Average() + 0.6 * i.Exam() << setw(15) << setprecision(2) << 0.4 * i.Median() + 0.6 * i.Exam() << endl;
    }
}

void readFile(vector<Student> &tmp, Student &temp, vector<Student> noob, vector<Student> nerd)
{
    string name, surname;
    ifstream fd;
    fd.exceptions(std::ios::failbit);
    string fileName;
    string line;
    bool fileExists = false;
    int numberOfGrades = -3;
    int x;
    bool methodOne;

    cout << "Which student sorting strategy you want to use? 0 (First method) OR 1 (Second method): ";
    cin >> methodOne;

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
        fd >> name >> surname;

        for (int i = 0; i < numberOfGrades; i++)
        {
            fd >> x;
            temp.Grades().push_back(x);
        }

        findAverage(temp);
        findMedian(temp);

        fd >> x;
        temp.SetName(name);
        temp.SetSurname(surname);
        temp.SetExam(x);
        tmp.push_back(temp);
        temp.Grades().clear();
    }

    sort(tmp.begin(), tmp.end(), [](Student& A, Student& B)
    { 
        return A.Name() < B.Name(); 
    });

    fd.close();

    methodOne ? sortStudentsMethodOne(tmp, noob) : sortStudentsMethodTwo(tmp, noob, nerd);

    cout << "Program finished. You can find your results in results.txt file." << endl;
}

void generateFile(vector<Student> &tmp, Student &temp, vector<Student> noob)
{
    auto generatingStart = std::chrono::system_clock::now();
    int numberOfStudents;
    int numberOfGrades;

    cout << "How many students do you want to generate? ";
    cin >> numberOfStudents;

    cout << "How many grades do you want to generate? ";
    cin >> numberOfGrades;

    cout << "Generating file..." << endl;
    auto timeStart = std::chrono::system_clock::now();

    ofstream fr(to_string(numberOfStudents) + ".txt");

    fr << setw(20) << left << "Vardas" << setw(20) << right << "Pavarde";
    for (int i = 0; i < numberOfGrades; i++) fr << setw(20) << "ND" + to_string(i + 1);
    fr << setw(20) << right << "Egz.";

    for (int i = 0; i < numberOfStudents; i++)
    {
        fr << endl << setw(20) << left << "Vardas" + to_string(i + 1) << setw(20) << right << "Pavarde" + to_string(i + 1);

        for (int j = 0 ; j < numberOfGrades; j++)
        {
            fr << setw(20) << to_string(getRandomGrade());
        }

        fr << setw(20) << right << to_string(getRandomGrade());
    }

    fr.close();

    auto timeEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = timeEnd - timeStart;

    cout << "File generated. File generating took " << fixed << setprecision(2) << elapsedTime.count() << " seconds." << endl;
}

void sortingTest(vector<Student> &tmp, Student &temp, vector<Student> noob, vector<Student> nerd)
{
    string name, surname;
    ifstream fd;
    fd.exceptions(std::ios::failbit);
    string fileName;
    string line;
    bool fileExists = false;
    int numberOfGrades = -3;
    int x;
    bool methodOne;

    cout << "Which student sorting strategy you want to use? 0 (First method) OR 1 (Second method): ";
    cin >> methodOne;

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
    auto testStart = std::chrono::system_clock::now();
    auto timeStart = std::chrono::system_clock::now();

    while(!fd.eof())
    {
        fd >> name >> surname;

        for (int i = 0; i < numberOfGrades; i++)
        {
            fd >> x;
            temp.Grades().push_back(x);
        }

        findAverage(temp);
        findMedian(temp);

        fd >> x;
        
        temp.SetName(name);
        temp.SetSurname(surname);
        temp.SetExam(x);
        tmp.push_back(temp);
        temp.Grades().clear();
    }

    fd.close();

    auto timeEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = timeEnd - timeStart;
    cout << "Reading completed in " << fixed << setprecision(2) << elapsedTime.count() << " seconds. Sorting students..." << endl;

    timeStart = std::chrono::system_clock::now();

    sort(tmp.begin(), tmp.end(), [](Student& A, Student& B)
    { 
        return A.Name() < B.Name(); 
    });

    timeEnd = std::chrono::system_clock::now();
    elapsedTime = timeEnd - timeStart;
    cout << "Sorting completed in " << fixed << setprecision(2) << elapsedTime.count() << " seconds. Dividing students..." << endl;
    timeStart = std::chrono::system_clock::now();

    methodOne ? sortStudentsMethodOne(tmp, noob) : sortStudentsMethodTwo(tmp, noob, nerd);

    timeEnd = std::chrono::system_clock::now();
    auto testEnd = std::chrono::system_clock::now();
    elapsedTime = timeEnd - timeStart;
    std::chrono::duration<double> testTime = testEnd - testStart;
    cout << "Dividing completed in " << fixed << setprecision(2) << elapsedTime.count() << " seconds. Program finished in " << fixed << setprecision(2) << testTime.count() << " seconds." << endl;
}

int getRandomGrade() {
    return 1 + rand() % 10;
}

void sortStudentsMethodOne(vector<Student> tmp, vector<Student> &noob)
{
    auto findNoob = [](auto &i) { return 0.4 * i.Average() + 0.6 * i.Exam() < 5; };

    for (auto &i : tmp)
    {
        if (0.4 * i.Average() + 0.6 * i.Exam() < 5) 
        {
            noob.push_back(i);
            auto itr = find_if(tmp.begin(), tmp.end(), findNoob);
            tmp.erase(itr);
        }
    }

    printStudentsToFile(tmp, "nerds");
    printStudentsToFile(noob, "noobs");
}

void sortStudentsMethodTwo(vector<Student> tmp, vector<Student> &noob, vector<Student> &nerd)
{
    for (auto &i : tmp)
    {
        if (0.4 * i.Average() + 0.6 * i.Exam() < 5) noob.push_back(i);
        else if(0.4 * i.Average() + 0.6 * i.Exam() >= 5) nerd.push_back(i);

    }

    printStudentsToFile(nerd, "nerds");
    printStudentsToFile(noob, "noobs");
}
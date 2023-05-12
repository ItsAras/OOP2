#include "header.h"

void getGrades(Student &tmp)
{
    int x;
    vector<int> grades;
    char userInput;

    do
    {
        cout << "Student's [" << tmp.getGrades().size() + 1 << "] grade: ";
        
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
    double average;

    for (int i = 0; i < tmp.getGrades().size(); i++)
    {
        sum += tmp.getGrades()[i];
    }

    average = (double)sum / tmp.getGrades().size();

    tmp.setAverage(average);
}

void findMedian(Student &tmp)
{
    double median;

    tmp.sortGrades();
    
    int middle = (tmp.getGrades().size()) / 2;
    median = (tmp.getGrades().size() - 1) % 2 == 0 ? (tmp.getGrades()[middle - 1] + (double)tmp.getGrades()[middle]) / 2: tmp.getGrades()[middle];
    
    tmp.setMedian(median);
}

void getStudent(Student &tmp)
{
    string userInput;
    int x;

    cout << "Student's name and surname: ";
    cin >> userInput;
    tmp.setName(userInput);

    cin >> userInput;
    tmp.setSurname(userInput);

    getGrades(tmp);
    findAverage(tmp);
    findMedian(tmp);
    tmp.clearGrades();

    cout << "Student's exam grade: ";

    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. You need to type a number... ";
    }
    
    tmp.setExam(x);
}

void printStudents(vector<Student> tmp)
{
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << left << "Name" << setw(30) << "Surname" << setw(30) << "Final (Avg.)" << setw(15) << "Final (Med.)" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (auto &i : tmp)
    {
        cout << setw(30) << left << i.getName() << setw(30) << i.getSurname() << setw(30) << fixed << setprecision(2) << 0.4 * i.getAverage() + 0.6 * i.getExam() << setw(15) << setprecision(2) << 0.4 * i.getMedian() + 0.6 * i.getExam() << endl;
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
        fr << setw(30) << left << i.getName() << setw(30) << i.getSurname() << setw(30) << fixed << setprecision(2) << 0.4 * i.getAverage() + 0.6 * i.getExam() << setw(15) << setprecision(2) << 0.4 * i.getMedian() + 0.6 * i.getExam() << endl;
    }
}

void readFile(vector<Student> &tmp, Student &temp, vector<Student> noob, vector<Student> nerd)
{
    string userInput;
    vector<int> grades;
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
        fd >> userInput;
        temp.setName(userInput);

        fd >> userInput;
        temp.setSurname(userInput);
        
        
        for (int i = 0; i < numberOfGrades; i++)
        {
            fd >> x;
            temp.grades.push_back(x);
        }

        findAverage(temp);
        findMedian(temp);

        fd >> x;
        temp.setExam(x);

        tmp.push_back(temp);
        temp.clearGrades();
    }

    sort(tmp.begin(), tmp.end(), [](Student& A, Student& B)
    { 
        return A.getName() < B.getName(); 
    });

    fd.close();

    methodOne ? sortStudentsMethodOne(tmp, noob) : sortStudentsMethodTwo(tmp, noob, nerd);

    cout << "Program finished. You can find your results in the new files." << endl;
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
    string userInput;
    vector<int> grades;
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
        fd >> userInput;
        temp.setName(userInput);

        fd >> userInput;
        temp.setSurname(userInput);

        for (int i = 0; i < numberOfGrades; i++)
        {
            fd >> x;
            temp.grades.push_back(x);
        }

        findAverage(temp);
        findMedian(temp);

        fd >> x;
        temp.setExam(x);

        tmp.push_back(temp);
        temp.clearGrades();
    }

    fd.close();

    auto timeEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = timeEnd - timeStart;
    cout << "Reading completed in " << fixed << setprecision(2) << elapsedTime.count() << " seconds. Sorting students..." << endl;

    timeStart = std::chrono::system_clock::now();

    sort(tmp.begin(), tmp.end(), [](Student& A, Student& B)
    { 
        return A.getName() < B.getName(); 
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
    auto findNoob = [](auto &i) { return 0.4 * i.getAverage() + 0.6 * i.getExam() < 5; };

    for (auto &i : tmp)
    {
        if (0.4 * i.getAverage() + 0.6 * i.getExam() < 5) 
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
        if (0.4 * i.getAverage() + 0.6 * i.getExam() < 5) noob.push_back(i);
        else if(0.4 * i.getAverage() + 0.6 * i.getExam() >= 5) nerd.push_back(i);

    }

    printStudentsToFile(nerd, "nerds");
    printStudentsToFile(noob, "noobs");
}

void runTest()
{
    Student s1;

    s1.setName("Testas");
    s1.setSurname("Testuotojas");
    s1.setExam(10);

    cout << "Student S1: " << s1.getName() << " " << s1.getSurname() << " " << s1.getExam() << endl;

    Student s2(s1);

    cout << "Student S2: " << s2.getName() << " " << s2.getSurname() << " " << s2.getExam() << endl;

    s2.setName("ABC");
    s2.setSurname("DEF");
    s2.setExam(1);

    cout << "Student S2: " << s2.getName() << " " << s2.getSurname() << " " << s2.getExam() << endl;

    Student s4 = s2;

    cout << "Student S4: " << s4.getName() << " " << s4.getSurname() << " " << s4.getExam() << endl;
}

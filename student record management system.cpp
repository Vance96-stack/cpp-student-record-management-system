#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student
{
public:
    int id;
    string name;
    string course;
    double marks;

    void display() const
    {
        cout << left << setw(10) << id
        << setw(25) << name
        << setw(20) << course
        << setw(10) << marks
        << endl;
    }
};

vector<Student>students;

void saveRecords()
{
    ofstream file("students.txt");

    for(const auto& s : students)
    {
        file << s.id << "|" << s.name << "|"
        << s.course << "|" << s.marks << endl;
    }
    file.close();
}

void loadRecords()
{
    ifstream file("students.txt");
    string line;

    while(getline(file, line))
    {
        Student s;
        size_t p1 = line.find('|');
        size_t p2 = line.find('|',p1 + 1);
        size_t p3 = line.find('|',p2 + 1);

        if(p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;

        try
        {
            s.id = stoi(line.substr(0,p1));
            s.name = line.substr(p1 + 1,p2-p1-1);
            s.course = line.substr(p2 + 1,p3-p2-1);
            s.marks = stod(line.substr(p3 + 1));
            students.push_back(s);
        } catch(...)
        {
            continue;
        }
    }
    file.close();
}

void addStudent()
{
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    for(const auto& student:students)
    {
        if(student.id == s.id)
        {
            cout << "ID already exists!\n";
            return;
        }
    }

    cin.ignore(10000,'\n');

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter Marks (0 - 100): ";
    cin >> s.marks;

    if(s.marks < 0 || s.marks > 100)
    {
        cout << "Invalid marks!\n";
        return;
    }

    students.push_back(s);
    saveRecords();

    cout << "Student Added Successfully!\n";
}

void displayStudents()
{
    if(students.empty())
    {
        cout << "No student records found!\n";
        return;
    }

    cout << "\nID    Name           Course"
    <<"              Marks\n";

    for(const auto& s:students)
    {
        s.display();
    }
}

void searchStudent()
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for(const auto& s:students)
    {
        if(s.id == id)
        {
            cout << "\nStudent Found: \n";
            s.display();
            return;
        }
    }

    cout << "Student Not Found!\n";
}

void deleteStudent()
{
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(), [id](const Student& s)
                      {
                          return s.id == id;
                      });

                      if(it != students.end())
                      {
                          students.erase(it);
                          saveRecords();
                          cout << "Record Deleted Successfully!\n";
                      }
                      else
                      {
                          cout << "Student Not Found!\n";
                      }
}

void updateStudent()
{
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto& s:students)
    {
        if(s.id == id)
        {
            cin.ignore(10000,'\n');

            cout << "Enter new name: ";
            getline(cin, s.name);

            cout << "Enter new course: ";
            getline(cin, s.course);

            cout << "Enter new marks: ";
            cin >> s.marks;

            if(s.marks < 0 || s.marks > 100)
            {
                cout << "Invalid marks.Update canceled!\n";
                return;
            }

            saveRecords();
            cout << "Record Updated!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

void showAverage()
{
    if(students.empty())
    {
        cout << "No records available!\n";
        return;
    }

    double total = 0;

    for(const auto& s:students)
    {
        total += s.marks;
    }

    cout << "Class Average: "
    << fixed << setprecision(2)
    << total / students.size() << "%\n";
}

int main()
{
    loadRecords();

    int choice;

    do
    {
        cout << "\n ==== STUDENT MANAGEMENT SYSTEM ====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Calculate Class Average\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";

        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid Input!\n";
            continue;
        }

        switch(choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            showAverage();
            break;

        case 0:
            cout << "Exiting System...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    } while(choice != 0);

    return 0;
}

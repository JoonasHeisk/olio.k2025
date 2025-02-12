#include <iostream>
#include <student.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main ()
{
    int selection = 0;
    vector<Student> studentList;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch(selection)
        {
        case 0:
        {
            string name;
            int age;
            cout << "Student name?" << endl;
            cin >> name;
            cout << "Student age?" << endl;
            cin >> age;
            studentList.push_back(Student(name, age));
            break;
        }

        case 1:
        {
            if (studentList.empty()) {
                cout << "No students available." << endl;
            } else {
                for (Student& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;
        }

        case 2:
        {
            if (studentList.empty()) {
                cout << "No students to sort." << endl;
            } else {
                sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                    return a.getName() < b.getName();
                });
                for (Student& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;
        }

        case 3:
        {
            if (studentList.empty()) {
                cout << "No students to sort." << endl;
            } else {
                sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                    return a.getAge() < b.getAge();
                });
                for (Student& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;
        }

        case 4:
        {
            string searchName;
            cout << "Student name to search: ";
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(), [&searchName](const Student& s) {
                return s.getName() == searchName;
            });

            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}

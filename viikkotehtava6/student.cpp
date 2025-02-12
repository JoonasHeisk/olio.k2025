#include "student.h"
#include <string>

Student::Student(string n, int i) : Name(n), Age(i) {}

void Student::setName(string n)
{
    Name = n;
}

void Student::setAge(int i)
{
    Age = i;
}

string Student::getName() const
{
    return Name;
}

int Student::getAge() const
{
    return Age;
}

void Student::printStudentInfo() const
{
    cout << "Student " << Name << " Age " << Age << endl;
}

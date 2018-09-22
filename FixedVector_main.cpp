#include <stdexcept>
#include <iostream>
#include <string>

#include "FixedVector.h"
using namespace std;

class Student {
private:
    string name;
    int numOfSemesters;

public:
    void print() {
        cout << "Name:" << name << "; No. of semesters=" << numOfSemesters << endl;
    }
    void setName(string newName) {
        name = newName;
    }
    void setNSemesters(int n) {
        numOfSemesters = n;
    }
    void updateNSemesters() {
        numOfSemesters++;
    }
};

int main() {
    FixedVector<Student> students(10);

    Student s;
    for (int i = 0; i < 5; i++) {
        s.setName("Student_" + to_string(i));
        s.setNSemesters(2);
        students.set(i, s);
    }

    for (int i = 0; i < students.getSize(); ++i) {
        students.get(i).print();
    }
}

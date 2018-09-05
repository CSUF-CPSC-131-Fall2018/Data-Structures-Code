#include <stdexcept>
#include <iostream>
#include <string>

#include "FixedVector.h"
using namespace std;

class Student {
private:
    string _name;
    int _num_of_semesters;

public:
    void print() {
        cout << "Name:" << _name << "; No. of semesters=" << _num_of_semesters << endl;
    }
    void setName(string name) {
        _name = name;
    }
    void setNSemesters(int n) {
        _num_of_semesters = n;
    }
    void updateNSemesters() {
        _num_of_semesters++;
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

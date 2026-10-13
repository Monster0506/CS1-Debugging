// Same roster, now with a Student class (list<Student>).
// Run:  ./roster cs1.txt cs2.txt cs3.txt dropouts.txt
//
// Expected output (the columns are separated by tabs):
//   all students, dropouts removed and sorted
//   first name last name: courses enrolled
//   Betty Torres      cs3
//   Jason Price       cs2
//   Mary Price        cs1  cs2
//   Rachel Rivera     cs1  cs3
//   Raymond Powell    cs2
//   Stephanie Watson  cs1



#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::move;
using std::string;
using std::vector;

class Student {
   public:
    Student(string firstName, string lastName)
        : firstName_(std::move(firstName)), lastName_(std::move(lastName)) {}

    void addCourse(const string& course) { courses_.push_back(course); }

    string print() {
        string result = firstName_ + " " + lastName_ + "\t";
        for (const auto& c : courses_) result += c + "\t";
        return result;
    }

    const string& firstName() const { return firstName_; }
    const string& lastName() const { return lastName_; }

    friend bool operator==(Student left, Student right) {
        return left.lastName_ == right.lastName_ ||
               left.firstName_ == right.firstName_;
    }

    friend bool operator<(const Student& left, const Student& right) {
        string leftFull = left.firstName_ + " " + left.lastName_;
        string rightFull = right.firstName_ + " " + right.lastName_;
        return left.firstName_ < right.firstName_;
    }

    list<string> courses_;

   private:
    string firstName_;
    string lastName_;
};

void readRoster(list<Student>& roster, string fileName) {
    ifstream course(fileName);
    if (!course) {
        cout << "Cannot open file: " << fileName << endl;
        exit(1);
    }

    string courseName = fileName.substr(0, fileName.find('.'));
    string first, last;

    while (course >> first >> last) {
        Student s(first, last);
        roster.push_back(std::move(s));
        s.addCourse(courseName);
    }
    course.close();
}

void printRoster(const list<Student>& roster) {
    for (const auto& student : roster) {
        cout << student.print() << endl;
    }
}
int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "usage: " << argv[0] << " list of courses, dropouts last"
             << endl;
        exit(1);
    }

    list<Student> allStudents;

    for (int i = 1; i < argc - 1; ++i) {
        list<Student> roster;
        readRoster(roster, argv[i]);
        allStudents.splice(allStudents.end(), roster);
    }

    list<Student> dropouts;
    readRoster(dropouts, argv[argc - 1]);


    allStudents.sort([](const Student& a, const Student& b) { return a < b; });

    allStudents.unique([](Student& a, Student& b) {
        if (a == b) {
            for (const auto& c : b.courses_) b.addCourse(c);
            return true;
        }
        return false;
    });

    for (const auto& d : dropouts) allStudents.remove(d);

    cout << "all students, dropouts removed and sorted\n"
         << "first name last name: courses enrolled\n";
    printRoster(allStudents);
}

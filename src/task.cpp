#include "MutableArraySequence.h"

struct StudentMark {
    std::string name;
    std::string area;
    int mark;

    StudentMark(std::string& name, std::string& area, int mark) {
        this->name = name;
        this->area = area;
        this->mark = mark;
    }

};

int main() {
    auto students = MutableArraySequence<std::string>();
    auto areas = MutableArraySequence<std::string>();
    auto studentMarks = MutableArraySequence<StudentMark>();




}

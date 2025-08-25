#include <iostream>
#include <ostream>

#include "MutableArraySequence.h"

template <typename T>
void printSequence(Sequence<T>* seq) {
    for (int i = 0; i < seq->GetLength(); i++) {
        std::cout << seq->Get(i) << std::endl;
    }
}

struct StudentMark {
    std::string name;
    std::string area;
    int mark;

    StudentMark() : name(""), area(""), mark(0) {}

    StudentMark(const std::string& name, const std::string& area, int mark)
        : name(name), area(area), mark(mark) {}


};

int main() {
    auto* marks = new MutableArraySequence<StudentMark>();
    auto* students = new MutableArraySequence<std::string>();
    // Математический анализ, Физика, Информатика, Линейная алгебра, Теория графов
    // Игнат, Борис, Моисей, Леонид, Олег, Игорь, Степан, Адам, Константин, Илья

    students->Append("Игнат");
    students->Append("Борис");
    students->Append("Моисей");
    students->Append("Леонид");
    students->Append("Олег");
    students->Append("Игорь");
    students->Append("Степан");
    students->Append("Адам");
    students->Append("Константин");
    students->Append("Илья");

    marks->Append(StudentMark("Игнат", "Математический анализ", 5));
    marks->Append(StudentMark("Игнат", "Физика", 4));
    marks->Append(StudentMark("Игнат", "Информатика", 5));
    marks->Append(StudentMark("Игнат", "Линейная алгебра", 4));
    marks->Append(StudentMark("Игнат", "Теория графов", 5));

    marks->Append(StudentMark("Борис", "Математический анализ", 3));
    marks->Append(StudentMark("Борис", "Физика", 3));
    marks->Append(StudentMark("Борис", "Информатика", 4));
    marks->Append(StudentMark("Борис", "Линейная алгебра", 4));
    marks->Append(StudentMark("Борис", "Теория графов", 4));

    marks->Append(StudentMark("Моисей", "Математический анализ", 5));
    marks->Append(StudentMark("Моисей", "Физика", 5));
    marks->Append(StudentMark("Моисей", "Информатика", 4));
    marks->Append(StudentMark("Моисей", "Линейная алгебра", 5));
    marks->Append(StudentMark("Моисей", "Теория графов", 5));

    marks->Append(StudentMark("Леонид", "Математический анализ", 4));
    marks->Append(StudentMark("Леонид", "Физика", 4));
    marks->Append(StudentMark("Леонид", "Информатика", 4));
    marks->Append(StudentMark("Леонид", "Линейная алгебра", 3));
    marks->Append(StudentMark("Леонид", "Теория графов", 4));

    marks->Append(StudentMark("Олег", "Математический анализ", 3));
    marks->Append(StudentMark("Олег", "Физика", 3));
    marks->Append(StudentMark("Олег", "Информатика", 3));
    marks->Append(StudentMark("Олег", "Линейная алгебра", 3));
    marks->Append(StudentMark("Олег", "Теория графов", 3));

    marks->Append(StudentMark("Игорь", "Математический анализ", 5));
    marks->Append(StudentMark("Игорь", "Физика", 5));
    marks->Append(StudentMark("Игорь", "Информатика", 5));
    marks->Append(StudentMark("Игорь", "Линейная алгебра", 5));
    marks->Append(StudentMark("Игорь", "Теория графов", 4));

    marks->Append(StudentMark("Степан", "Математический анализ", 4));
    marks->Append(StudentMark("Степан", "Физика", 4));
    marks->Append(StudentMark("Степан", "Информатика", 3));
    marks->Append(StudentMark("Степан", "Линейная алгебра", 4));
    marks->Append(StudentMark("Степан", "Теория графов", 4));

    marks->Append(StudentMark("Адам", "Математический анализ", 4));
    marks->Append(StudentMark("Адам", "Физика", 3));
    marks->Append(StudentMark("Адам", "Информатика", 5));
    marks->Append(StudentMark("Адам", "Линейная алгебра", 4));
    marks->Append(StudentMark("Адам", "Теория графов", 4));

    marks->Append(StudentMark("Константин", "Математический анализ", 5));
    marks->Append(StudentMark("Константин", "Физика", 4));
    marks->Append(StudentMark("Константин", "Информатика", 5));
    marks->Append(StudentMark("Константин", "Линейная алгебра", 4));
    marks->Append(StudentMark("Константин", "Теория графов", 5));

    marks->Append(StudentMark("Илья", "Математический анализ", 4));
    marks->Append(StudentMark("Илья", "Физика", 4));
    marks->Append(StudentMark("Илья", "Информатика", 4));
    marks->Append(StudentMark("Илья", "Линейная алгебра", 4));
    marks->Append(StudentMark("Илья", "Теория графов", 3));


    auto studentAverageMarks = students->Map<std::pair<std::string, double>>(
        [marks](const std::string& name) {
        auto* marksByStudent = marks->Where(
            [name](const StudentMark& mark_info) {
            return mark_info.name == name;
        });
        double mark = static_cast<double>(marksByStudent->Reduce<int>(
            [](int result, const StudentMark& current_mark) {
            return current_mark.mark + result;
        }, 0)) / marksByStudent->GetLength();
        auto studentAverageMark = std::make_pair(name, mark);
        delete marksByStudent;
        return studentAverageMark;
    });

    studentAverageMarks->Sort([](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second < b.second;
    });

    std::cout << "Топ 5 студентов с наивысшым средним баллом:" << std::endl;
    for (int i = 0; i < 5; i++) {
        auto mark = studentAverageMarks->Get(i);
        std::cout << mark.first << " (" << mark.second << ")" << std::endl;
    }

    auto filteredStudentAverageMarks = studentAverageMarks->Where(
        [marks](const std::pair<std::string, double>& studentAverageMark) {
        auto marksForFilter = marks->Where(
            [studentAverageMark](const StudentMark& mark) {
            return mark.name == studentAverageMark.first
                && (mark.area == "Математический анализ" || mark.area == "Физика")
                && mark.mark >= 4;
        });
        bool result = marksForFilter->GetLength() == 2;
        delete marksForFilter;
        return result;
    });

    double averageFilteredMark = filteredStudentAverageMarks->Reduce<double>(
        [](double result, const std::pair<std::string, double>& studentAverageMark) {
            return result + studentAverageMark.second;
        },
        0.0) / filteredStudentAverageMarks->GetLength();


    auto resultStudentAverageMarks = studentAverageMarks->Where(
        [averageFilteredMark](const std::pair<std::string, double>& studentAverageMark) {
        return studentAverageMark.second < averageFilteredMark;
    });

    std::cout << std::endl << "Топ 5 студентов со средним баллом ниже среднего арифметического балла среди студентов сдавших все дисциплины матан и физика на 4 и выше:" << std::endl;
    for (int i = 0; i < 5; i++) {
        auto mark = resultStudentAverageMarks->Get(i);
        std::cout << mark.first << " (" << mark.second << ")" << std::endl;
    }

    delete studentAverageMarks;
    delete marks;
    delete students;
    delete filteredStudentAverageMarks;


}

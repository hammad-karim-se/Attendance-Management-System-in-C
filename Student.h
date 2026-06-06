#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

struct Student
{
    string name;
    int roll_no;
    int present_days;
    float percentage;

    Student()
    {
        present_days = 0;
        percentage = 0.0;
    }
};
#endif
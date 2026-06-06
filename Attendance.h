#ifndef ATTENDANCE_H
#define ATTENDANCE_H
#include "Student.h"

class Attendance
{
private:
    Student students[50];
    int total_days;
    int n;
public:
    Attendance();
    void run();
    void add_student();
    void mark_attendance();
    void display_attendance();
    void display_one();
    void calculate_percentage();
    void save_data();
    void load_data();
    void save_report();
};
#endif
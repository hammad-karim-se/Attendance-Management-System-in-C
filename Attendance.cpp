#include "Attendance.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Attendance::Attendance()
{
    n = 0;
    total_days = 0;
}

void Attendance::run()
{
    int choice;
    while (1)
    {
        cout << "\n--- Attendance Management System ---"<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. Mark Attendance"<<endl;
        cout << "3. Display Attendance Report"<<endl;
        cout << "4. Display Individual Attendance"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            mark_attendance();
            break;
        case 3:
            display_attendance();
            break;
        case 4:
            display_one();
            break;
        case 5:
            save_data();
            cout << "Data Saved Successfully!"<<endl;
            return;
        default:
            cout << "Invalid Choice!"<<endl;
        }
    }
}

void Attendance::add_student()
{
    cout << "--- Adding Student ---"<<endl;
    if (n >= 50)
    {
        cout << "Maximum Students Reached!"<<endl;
        return;
    }
    cin.ignore(1000, '\n');
    cout << "Enter Student Name: ";
    getline(cin, students[n].name);
    students[n].roll_no = n + 1;
    cout << "Assigned Roll Number: "<<students[n].roll_no << endl;
    n++;
    save_data();
    cout << "Student Added Successfully!"<<endl;
}

void Attendance::mark_attendance()
{
    if (n == 0)
    {
        cout << "No Students Added Yet."<<endl;
        return;
    }
    total_days++;
    cout << "--- Mark Attendance ---"<<endl;
    cout<< "Roll No.\tName\t\tStatus"<<endl;
    for (int i = 0; i < n; i++)
    {
        char status;
        cout << students[i].roll_no<< "\t\t"<< students[i].name<< "\t(P/A): ";
        cin >> status;
        while (status != 'P' && status != 'p' && status != 'A' && status != 'a')
        {
            cout << "Invalid Input! Enter P or A: ";
            cin >> status;
        }
        if (status == 'P' || status == 'p')
        {
            students[i].present_days++;
        }
    }
    save_data();
    cout << "Attendance Marked Successfully!"<<endl;
}

void Attendance::calculate_percentage()
{
    for (int i = 0; i < n; i++)
    {
        if (total_days > 0)
        {
            students[i].percentage = (students[i].present_days / (float)total_days) *100;
        }
        else
        {
            students[i].percentage = 0;
        }
    }
}

void Attendance::display_attendance()
{
    if (n == 0)
    {
        cout << "No Students Added Yet."<<endl;
        return;
    }
    calculate_percentage();
    cout << "\n--- Attendance Report ---"<<endl;
    cout << "Roll\tName\t\t\tPresent\tAbsent\tPercentage"<<endl;
    for (int i = 0; i < n; i++)
    {
        int absent =total_days - students[i].present_days;
        cout << students[i].roll_no<< "\t"<< students[i].name<< "\t\t  "<< students[i].present_days<< "\t  "<< absent<< "\t "<< fixed<< setprecision(2)<< students[i].percentage<< "%"<<endl;
    }
    save_report();
}

void Attendance::display_one()
{
    calculate_percentage();
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;
    for (int i = 0; i < n; i++)
    {
        if (students[i].roll_no == roll)
        {
            int absent =
                total_days -
                students[i].present_days;
            cout << "\n--- Student Report ---"<<endl;
            cout << "Roll No: " << students[i].roll_no << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Present Days: " << students[i].present_days << endl;
            cout << "Absent Days: " << absent << endl;
            cout << "Total Classes: " << total_days << endl;
            cout << "Attendance Percentage: " << fixed << setprecision(2) << students[i].percentage << "%"<<endl;
            if (students[i].percentage < 75)
            {
                cout << "Warning: Attendance Below 75%"<<endl;
            }
            return;
        }
    }
    cout << "Student Not Found."<<endl;
}

void Attendance::save_data()
{
    ofstream fout("students.txt");
    fout << n << endl;
    fout << total_days << endl;
    for (int i = 0; i < n; i++)
    {
        fout << students[i].name << endl;
        fout << students[i].roll_no << endl;
        fout << students[i].present_days << endl;
    }
    fout.close();
}

void Attendance::load_data()
{
    ifstream fin("students.txt");
    if (!fin)
    {
        cout << "No Previous Record Found."<<endl;
        return;
    }
    fin >> n;
    fin >> total_days;
    fin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(fin, students[i].name);
        fin >> students[i].roll_no;
        fin >> students[i].present_days;
        fin.ignore();
    }
    fin.close();
}

void Attendance::save_report()
{
    calculate_percentage();
    ofstream fout("Attendance_Report.txt");
    fout << "Roll No.\tName\tPresent\tAbsent\tPercentage"<<endl;
    for (int i = 0; i < n; i++)
    {
        int absent = total_days - students[i].present_days;
        fout << students[i].roll_no << "\t" << students[i].name << "\t" << students[i].present_days << "\t" << absent << "\t" << fixed << setprecision(2) << students[i].percentage << "%"<<endl;
    }
    fout.close();
    cout << "Report Saved Successfully!\n";
}
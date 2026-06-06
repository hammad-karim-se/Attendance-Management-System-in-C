# 📚 Attendance Management System

A console-based **Attendance Management System** built in **C++** that allows users to manage student attendance records, generate reports, and store data permanently using file handling.

---

## 🚀 Features

- Add new students
- Mark daily attendance
- View attendance records of all students
- View individual student attendance details
- Generate attendance reports
- Save attendance records to files
- Load previous records automatically on startup
- Attendance percentage calculation
- Low attendance warning (below 75%)

---

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Structures (`struct`)
- File Handling

---

## 📂 Project Structure

```text
Attendance-System/
│
├── main.cpp
├── Attendance.cpp
├── Attendance.h
├── Student.h
├── students.txt
├── Attendance_Report.txt
├── Attendance System.exe
├── Attendance_System.dev
└── README.md
```



---

## 📋 Menu

```text
=================================
   Attendance Management System
=================================

1. Add Student
2. Mark Attendance
3. Display Attendance Report
4. Display Individual Attendance
5. Exit
```

---

## 📖 How It Works

### 1️⃣ Add Student

- Enter student name
- Roll number is assigned automatically

---

### 2️⃣ Mark Attendance

Attendance can be marked using:

```text
P = Present
A = Absent
```


---

### 3️⃣ Generate Attendance Report

The system calculates:

- Present Days
- Absent Days
- Attendance Percentage

---

## 💾 File Handling

The application automatically stores data in:

### students.txt

Stores:

- Student Names
- Roll Numbers
- Present Days
- Total Classes

### Attendance_Report.txt

Stores the generated attendance report.

This allows data to persist even after closing the application.

---

## 🎯 Learning Outcomes

This project helped me practice:

- Classes and Objects
- Constructors
- Structures
- Arrays
- File Handling
- Data Persistence
- Header and Source File Organization

---


## 👨‍💻 Author

**Hammad Karim**

Software Engineering Student passionate about learning C++ through hands-on projects.

---

⭐ If you found this project useful, consider giving it a star!

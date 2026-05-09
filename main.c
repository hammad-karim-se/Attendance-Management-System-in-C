#include <stdio.h>
//Students Data
char name[10][50] = {
    "Hassan Ali","Saad Khan","Junaid Ahmad","Hussain Shah","Ahmad Ali",
    "Kashan Farooq","Huzaifa Saleem","Umar Khan","M. Sanaullah","Abdullah Javed"};
int id[10] = {1,2,3,4,5,6,7,8,9,10};
int presentDays[10];
int students=10;
int totalDays=0;
//Shows Menu
void menu(){
    printf("\n--- Attendance Management System ---\n");
    printf("1. Mark Attendance\n");
    printf("2. View All Attendance\n");
    printf("3. View Individual Student\n");
    printf("4. Exam Eligibility Status\n");
    printf("5. Exit\n");
    }
//Save Data to File
void saveToFile() {
    FILE *fp = fopen("attendance.txt", "w");
    if (fp == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fprintf(fp, "%d\n", totalDays);
    for (int i = 0; i < students; i++) {
        fprintf(fp, "%d %d\n", id[i], presentDays[i]);
    }
    fclose(fp);
}
//Mark Attendance
void mark(){
    printf("\n--- Class Attendance ---\n");
    totalDays++;
    printf("Class No\t\tName\t\tAttendance\n");
    for (int i = 0; i<students; i++) {
        char present;
        printf(" %d\t\t\t%s\t(P/A): ", id[i], name[i]);
        scanf(" %c", &present);
        if (present =='P' || present =='p')
        presentDays[i]++;}
        printf("\nAttendance marked successfully!\n");
        saveToFile();
    }
//Load Data from File
void loadFromFile() {
    FILE *fp = fopen("attendance.txt", "r");
    if (fp == NULL) {
        return; // No previous data
    }
    fscanf(fp, "%d", &totalDays);
    for (int i = 0; i < students; i++) {
        fscanf(fp, "%d %d", &id[i], &presentDays[i]);
    }
    fclose(fp);
}
//Calculate Attendance Percentage
float percentage(int present, int total){
    if(total==0){return 0;}
    return (present * 100.0) / total;
    }
//Displays Record of All Students
void view(){
    printf("\n--- Attendance Record ---\n");
    printf("Class No\tName\t\t\tPresent\t\tPercentage\n");
    for (int i=0; i<students; i++){
        float percent = percentage(presentDays[i],totalDays);
        printf("%d\t\t%s\t\t%d\t\t%.2f%%\n",id[i],name[i],presentDays[i],percent); }
    }
//Finds Student By Entering Class Number
int find(int sid){
    for (int i=0; i<students; i++)
        if (id[i]==sid)
        return i;
return 0;
    }
//Displays Details of a Student
void viewone(){
    int sid;
    printf("\nEnter Class No of Student: ");
    scanf("%d", &sid);
    if(sid>10){
        printf("Student Not Found!\n");}
    int index = find(sid);
    float percent = percentage(presentDays[index], totalDays);
    printf("\n----- Student Details -----\n");
    printf("Student Name: %s\n", name[index]);
    printf("Class Number: %d\n", id[index]);
    printf("Total Days  : %d\n", totalDays);
    printf("Present Days: %d\n", presentDays[index]);
    printf("Attendance  : %.2f%%\n", percent);
    }
//Displays Eligibility for Exam
void eligibility(){
    printf("\n----- Exam Eligibility -----\n");
    printf("Class No\tName\t\t\tAttendance\t\tStatus\n");
    for (int i=0; i<students; i++) {
        float percent = percentage(presentDays[i], totalDays);
        printf("%d\t\t%s\t\t%.2f%%\t\t ",id[i], name[i], percent);
        if (percent>=75)
        printf("\tAllowed To Appear In Exam.\n");
        else
        printf("\tNot Allowed To Appear In Exam.\n"); }
    }
int main() {
    loadFromFile();
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            mark();
            break;
        case 2:
            view();
            break;
        case 3:
            viewone();
            break;
        case 4:
            eligibility();
            break;
        case 5:
            return 0;
        default:
            printf("\nInvalid choice! Try again.\n");
            break; }}}

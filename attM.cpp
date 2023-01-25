/* COPYRIGHT INFO */
/*
    AUTHOR: RAJJIT LAISHRAM
    DATE CREATED: SEPTEMBER 06, 2022
    PURPOSE: FOR MANAGING THE ATTENDANCE OF STUDENTS BY THE TEACHERS. 
    THIS APPLICATION CAN BE USED TO MANAGE ALL THE ACTIVITIES OF THE STUDENTS.

    DATE MODIFIED: JANUARY 25, 2023
    CHANGES: ADDED INFOR FOR EACH SECTION
*/

//  C++ Program on Attendance Management of Students

// INCLUDES THE REQUIRED LIBRARY FILES
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <typeinfo>
#include <windows.h>

using namespace std;

// USER DEFINED FUNCTIONS
void title(); // TO GIVE THE TITLE                                                  
void date(); // TO GIVE THE DATE                                                   
int delay(); // TO DELAY THE DISPLAY               
void delay(unsigned int mseconds);                             
int adminLogin(); // LOGIN FUNCTION FOR TEACHERS                                              
int adminView(); // DISPLAY FOR THE TEACHERS                                              
int registerStudent(); // TO REGISTER STUDENTS                        
int checkListOfStudentsRegistered(); // TO CHECK THE LIST OF STUDENTS                       
int studentLogin(); // LOGIN FUNCTION FOR STUDENTS             
int studentView(); // DISPLAY FOR THE STUDENTS                                             
int checkStudentCredentials(string userName, string password); // CHECK PASSWORD
int markMyAttendance(string username); // MARK THE ATTENDANCE                       
int countMyAttendance(string username); // COUNT THE ATTENDANCE                       
int sendLeaveApplication(string username); // TO SEND LEAVE
int deleteAllStudents(); // TO DELETE ALL THE STUDENTS    
int getListOFStudentsRegistered(); // GET THE LIST OF STUDENTS
int deleteStudentAllData(); // DELETE STUDENT DATA

using namespace std;

int m = 0;
int total = 100;

void title()
{
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t    -----------------------------------\n";
    cout << "\t\t\t\t    |Attendance Management Of Students|\n";
    cout << "\t\t\t\t    -----------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
}

void date()
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout << "\n\n\n";
    printf("\t\t\t\t\t   Date:%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int delay()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\nSaving Records ...\n";
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }

    cout << "\nExiting Now ...";
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }
    return 0;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

// Login part for Admin
int adminLogin()
{
    system("cls");
    date();
    title();
    cout << "\n --------- Admin Login --------- \n\n";

    string username;
    string password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;

    if (username == "admin" && password == "admin@2")
    {
        adminView();
        getchar();
        delay();
    }
    else
    {
        cout << "\n\nError! Invalid Credentials ...";
        cout << "\n\nPress any key for main menu ...";
        getchar();
        getchar();
    }
    return 0;
}

// Options for Admin
int adminView()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        date();
        title();
        cout << "\n\n\nPlease select an option ...\n";
        cout << "---------------------------\n";
        cout << "\n1. Register a Student";
        cout << "\n2. Check list of Students registered and view Roll No.";
        cout << "\n3. Delete all registered Students";
        cout << "\n4. Get list of Students registered by Username";
        cout << "\n5. Delete Data of Students";
        cout << "\n0. Go back <-\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            registerStudent();
            break;
        case 2:
            checkListOfStudentsRegistered();
            break;
        case 3:
            deleteAllStudents();
            break;
        case 4:
            getListOFStudentsRegistered();
            break;
        case 5:
            deleteStudentAllData();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\nInvalid choice. Please enter again.";
            getchar();
        }
        if (goBack == 1)
        {
            break; // breaking the loop
        }
    }
    return 0;
}

// Registering Student
int registerStudent()
{
    cout << "\n ------ Form to Register Student ------ \n\n";
    string name, username, password, rollno, address, fathersname, mothersname;
    int total;
    cout << "\nEnter Name: ";
    cin >> name;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    cout << "\nEnter Roll No.: ";
    cin >> rollno;
    getchar();

    char add[100];
    cout << "\nEnter Address: ";
    cin.getline(add, 100);
    cout << "\nEnter Father's Name: ";
    cin >> fathersname;
    cout << "\nEnter Mother's Name: ";
    cin >> mothersname;
    cout << "\nEnter initial number of atendance: ";
    cin >> m;

    // check if record already exist ...
    ifstream read;
    read.open("db.dat");
    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == username + ".dat")
            {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 1)
        {
            cout << "\nUsername already Registered. Please choose another username ...";
            getchar();
            getchar();
            delay();
            read.close();
            return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    out << username + ".dat"
        << "\n";
    out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << name << "\n";
    out1 << username << "\n";
    out1 << password << "\n";
    out1 << rollno << "\n";
    out1 << add << "\n";
    out1 << fathersname << "\n";
    out1 << mothersname << "\n";
    out1 << m << "\n";
    out1.close();

    cout << "\nStudent Registered Successfully!!\n";
    cout << "\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

// Checking list of Students registered with roll no
int checkListOfStudentsRegistered()
{
    cout << "\n --- Check list of Students registered and view Roll No.--- \n\n";

    // check if record already exist ...
    ifstream read;
    read.open("db.dat");
    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            string filename = name;
            cout << "\n"
                 << filename;

            int total_lines = 0;
            ifstream read1;
            read1.open(filename.c_str(), ios::app);
            string line;
            while (getline(read1, line))
            {
                ++total_lines;
            }
            read1.close();
            ifstream read;
            read.open(filename.c_str(), ios::app);
            string l;
            if (read)
            {
                int line_no = 0;
                while (line_no != total_lines && getline(read, l))
                {
                    ++line_no;
                }
                if (line_no == total_lines)
                {
                    cout << " -> " << l << "\n";
                }
                read.close();
            }
            read.close();
        }
    }
    else
    {
        cout << "\nNo Record found :(";
    }

    cout << "\nPlease any key to continue..";
    getchar();
    getchar();
    return 0;
}

//  Login part for Student
int studentLogin()
{
    system("cls");
    date();
    title();
    cout << "\n --------- Student Login --------- \n\n";
    studentView();
    return 0;
}

// Options for Student
int studentView()
{
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;
    int res = checkStudentCredentials(username, password);
    if (res == 0)
    {
        cout << "\n\nInvalid Credentials!!";
        cout << "\n\nPress any key for Main Menu ...";
        getchar();
        getchar();
        return 0;
    }

    int goBack = 0;
    while (1)
    {
        cout << "\n\nPlease select an option ...\n";
        cout << "---------------------------\n";
        cout << "\n1. Mark Attendance for Today";
        cout << "\n2. Count my Attendance";
        cout << "\n3. Send a leave application";
        cout << "\n0. Go Back <-\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            markMyAttendance(username);
            break;
        case 2:
            countMyAttendance(username);
            break;
        case 3:
            sendLeaveApplication(username);
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\nInvalid choice. Please enter again.";
            getchar();
        }
        delay();
        if (goBack == 1)
        {
            break; // breaking the loop
        }
    }
    return 0;
}

// Checking information/credentials of Student
int checkStudentCredentials(string username, string password)
{
    // read file line by line and check if username-password.dat exist?
    // if it exist return 1 else 0

    ifstream read;
    read.open("db.dat");
    int recordFound = 0;
    if (read)
    {
        // the file exist, and open for input
        string line;
        string temp = username + ".dat";
        cout << "\nFile name is: " << temp;
        while (getline(read, line))
        {
            if (line == temp)
            {
                recordFound = 1;
            }
        }
    }
    read.close();
    cout << "\n\nRecord found " << recordFound << "\n\nusername: " << username << "\n\npassword: " << password;

    if (recordFound == 1)
    {
        ifstream read;
        string filename = username + ".dat";
        read.open(filename);
        int line_number = 0;
        string line;
        while (line_number != 3 && getline(read, line))
        {
            cout << "\n\nLine " << line;
            ++line_number;
        }
        cout << "\n\n";
        cout << "\n\n --- Credentials matched!! --- \n\n";
        read.close();
        if (password == line)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

// Marking attendance of Student
int markMyAttendance(string username)
{
    cout << "\n\n --- Marking Attendance for today!! --- \n\n";
    int total_lines = 0;
    string filename = username + ".dat";
    ifstream read;
    read.open(filename);
    string line;
    while (getline(read, line))
    {
        ++total_lines;
    }
    read.close();

    ifstream read1;
    read1.open(filename);
    if (read1)
    {
        int line_no = 0;
        while (line_no != total_lines && getline(read1, line))
        {
            ++line_no;
        }
        if (line_no == total_lines)
        {
            cout << "\n\nInitial Attendance: " << line;
            cout << "\n\nAttendance marked!!!";
            int i;
            istringstream(line) >> i;
            i++;
            cout << "\n\nTotal present: " << i;
            cout << "\n\nPercentage of attendance: " << (i * 100 / total) << "%";
        }
    }

    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

// Counting attendance of Student
int countMyAttendance(string username)
{
    cout << "\n\n --- Counting attendance for today!! --- \n\n";
    int total_lines = 0;
    string filename = username + ".dat";
    ifstream read;
    read.open(filename);
    string line;
    while (getline(read, line))
    {
        ++total_lines;
    }
    read.close();

    ifstream read1;
    read1.open(filename);
    if (read1)
    {
        int line_no = 0;
        while (line_no != total_lines && getline(read1, line))
        {
            ++line_no;
        }
        if (line_no == total_lines)
        {
            cout << "\n\nInitial  attendance: " << line;
            int i;
            istringstream(line) >> i;
            i++;
            cout << "\n\nAttendance Report - Total present: " << i;
        }
    }

    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

// Sending leave for absence
int sendLeaveApplication(string username)
{
    char add[1000];
    cout << "\nWrite your application here: ";
    getchar();
    cin.getline(add, 1000);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    ofstream out;
    out.open("application.dat", ios::app);
    out << add << " -> " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " -> " << username << "\n";
    out.close();
    cout << "\nApplication successfully sent !!";
    cout << "\n\nPlease press any key to continue..";
    getchar();
    return 0;
}

// Deleting all registered Students
int deleteAllStudents()
{
    cout << "\n\n --- Deleting all registered students!! --- \n\n";
    cout << "Deleting";
    for (int process = 0; process < 25; process++)
    {
        delay(150);
        printf(".");
    }
    remove("db.dat");
    remove("application.dat");

    cout << "\n\nAll registered Students deleted successfully...";
    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

int getListOFStudentsRegistered()
{
    DIR *di;
    char *ptr1, *ptr2, name;
    int retn, result;
    struct dirent *dir;
    di = opendir("."); // specify the directory name
    if (di)
    {
        cout << "\n\n --- Lsit of Students registered by Username --- \n\n";
        while ((dir = readdir(di)) != NULL)
        {
            ptr1 = strtok(dir->d_name, ".");
            ptr2 = strtok(NULL, ".");
            if (ptr2 != NULL)
            {
                retn = strcmp(ptr2, "dat");
                if (retn == 0)
                {
                    cout << "\n\n";
                    printf("%s\t", ptr1);
                    cout << "\n\n";
                }
            }
        }
        closedir(di);
    }

    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

// Delete data of Students
int deleteStudentAllData()
{
    system("cls");
    DIR *di;
    char *ptr1, *ptr2;
    char name[20];
    int retn;
    int status;
    struct dirent *dir;
    di = opendir("."); // specify the directory name
    if (di)
    {
        cout << "\n\n --- Lsit of Students with data --- \n\n";

        while ((dir = readdir(di)) != NULL)
        {
            ptr1 = strtok(dir->d_name, ".");
            ptr2 = strtok(NULL, ".");
            if (ptr2 != NULL)
            {
                retn = strcmp(ptr2, "dat");
                if (retn == 0)
                {
                    cout << "\n";
                    printf("%s", ptr1);
                    cout << ".dat";
                    cout << "\n\n";
                }
            }
        }
        closedir(di);
    }

    cout << "\n\nEnter the name of the file which is to be deleted: ";
    cin >> name;
    status = remove(name);
    if (status == 0)
        cout << "\nFile Deleted Successfully!";
    else
    {
        cout << "\n\nError Occurred!";
        cout << "\n\nPlease enter a valid data";
    }

    cout << "\n\nPlease press any key to continue ...";
    getchar();
    getchar();
    return 0;
}

// Main part of the Program
int main(int argc, char **argv)
{
    system("cls");
    date();
    cout << "\n";
    cout << "\t\t\t\t    -----------------------------------\n";
    cout << "\t\t\t\t    |Attendance Management Of Students|\n";
    cout << "\t\t\t\t    -----------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Prepared By    :    Rajjit Laishram";
    cout << "\n\n\t\t\t\tSchool Project :   Attendance Management of Students";
    cout << "\n\n\t\t\t\tPress Enter to continue......";
    getchar();
    printf("\n\n\t\t\t\tLoading");

    for (int process = 0; process < 25; process++)
    {
        delay(150);
        printf(".");
    }

    while (1)
    {
        system("cls");
        date();
        title();
        cout << "\n";
        cout << "1. Student Login\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            studentLogin();
            break;
        case 2:
            adminLogin();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\nAre you sure you want to exit? Y | N or y | n \n";
                char ex;
                cin >> ex;

                if (ex == 'y' || ex == 'Y')
                    exit(0);
                else if (ex == 'n' || 'N')
                {
                    break;
                }
                else
                {
                    cout << "\nInvalid Choice!!";
                    getchar();
                }
            }
            break;
        default:
            cout << "\nInvalid Choice. Please enter again.";
            getchar();
        }
    }
    return 0;
}

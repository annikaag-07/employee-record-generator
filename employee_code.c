/*
 * Title: Employee Record Generation Using Structures and Enumerations in C
 * Date: 5 January 2026
 */

#include <stdio.h>      // for printf
#include <stdlib.h>     // for rand(), srand()
#include <stdbool.h>    // for boolean type (not strictly needed here)
#include <time.h>       // for time()

// Enumeration representing different business departments
typedef enum department_name{
    HR,
    Sales,
    Research,
    Software,
    Executive
} department_name;

// Converts enum department value to a readable string
const char* get_department_name(department_name dept){
    switch (dept){
        case HR: return "HR";
        case Sales: return "Sales";
        case Research: return "Research";
        case Software: return "Software";
        case Executive: return "Executive";
        default: return "Unknown";
    }
}

// Returns a base salary depending on the department
int general_salary(department_name dept){
    switch (dept){
        case HR: return 50000;
        case Sales: return 60000;
        case Research: return 70000;
        case Software: return 80000;
        case Executive: return 90000;
        default: return 0;
    }
}

// Structure representing an employee
typedef struct Member {
    department_name name;              // employee department
    int salary;                        // annual salary
    unsigned social_security_number;   // social security number
} Member;

// Array to store 10 employees
Member arr[10];

// Generates random employee data
void data_dept(void){
    for (int i = 0; i < 10; i++){
        arr[i].name = (department_name)(rand() % 5);
        arr[i].salary = general_salary(arr[i].name);
        arr[i].social_security_number = rand() % 99999999 + 1;
    }
}

// Prints employee details
void print_dept(void){
    for (int i = 0; i < 10; i++){
        printf(
            "Department: %s, Salary: %d, SSN: %u\n",
            get_department_name(arr[i].name),
            arr[i].salary,
            arr[i].social_security_number
        );
    }
}

// Main function
int main(void){
    srand(time(NULL));   // Seed random number generator
    data_dept();         // Generate employee data
    print_dept();        // Display employee records
    return 0;
}

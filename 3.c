#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
struct Student {
    char name[50];
    int rollNumber;
    int birthDay;
    int birthMonth;
    int birthYear;
    int admissionDay;
    int admissionMonth;
    int admissionYear;
};

// Function to calculate age at the time of admission
int calculateAge(int birthYear, int birthMonth, int birthDay, int admissionYear, int admissionMonth, int admissionDay) {
    int age = admissionYear - birthYear;
    if (admissionMonth < birthMonth) {
        age--;
    } else if (admissionMonth == birthMonth && admissionDay < birthDay) {
        age--;
    }
    return age;
}

int main() {
    // Declare a student variable
    struct Student student;

    // Read student information from user
    printf("Enter student name: ");
    fgets(student.name, 50, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline character
    printf("Enter student roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter student birthday (DD MM YYYY): ");
    scanf("%d %d %d", &student.birthDay, &student.birthMonth, &student.birthYear);
    printf("Enter admission date (DD MM YYYY): ");
    scanf("%d %d %d", &student.admissionDay, &student.admissionMonth, &student.admissionYear);

    // Calculate age at the time of admission
    int age = calculateAge(student.birthYear, student.birthMonth, student.birthDay,
                            student.admissionYear, student.admissionMonth, student.admissionDay);

    // Print student information and age at the time of admission
    printf("\nStudent Information:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Birthday: %d/%d/%d\n", student.birthDay, student.birthMonth, student.birthYear);
    printf("Admission Date: %d/%d/%d\n", student.admissionDay, student.admissionMonth, student.admissionYear);
    printf("Age at the time of admission: %d\n", age);

    return 0;
}

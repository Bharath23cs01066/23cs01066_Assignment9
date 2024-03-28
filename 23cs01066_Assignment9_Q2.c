#include <stdio.h>

struct Student {
    char rollNo[10];
    char name[50];
    char address[100];
    int age;
    float avgMarks;
};

void displayDetails(struct Student s);

int main() {
    struct Student students[6];
    int i;

    for(i = 0; i < 6; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Roll No: ");
        scanf("%s", students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
    }

    for(i = 0; i < 6; i++) {
        displayDetails(students[i]);
    }

    return 0;
}

void displayDetails(struct Student s) {
    printf("\nStudent Details:\n");
    printf("Roll No: %s\n", s.rollNo);
    printf("Name: %s\n", s.name);
    printf("Address: %s\n", s.address);
    printf("Age: %d\n", s.age);
    printf("Average Marks: %.2f\n", s.avgMarks);
}
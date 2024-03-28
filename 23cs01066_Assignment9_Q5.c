#include <stdio.h>



struct CourseRecord {
    char firstName[50];
    char lastName[50];
    char rollNumber[10];
    char department[50];
    char courseCode[10];
    int testMarks[3];
};


float calculateAverage(struct CourseRecord cr) {
    int total = 0;
    for(int i = 0; i < 3; i++) {
        total += cr.testMarks[i];
    }
    return total / 3.0;
}


int hasPassed(struct CourseRecord cr) {
    float average = calculateAverage(cr);
 if(average >= 35){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {

    struct CourseRecord cr = {"Vikranth", "M", "0", "CS", "CS101", {40, 50, 60}};


    float average = calculateAverage(cr);
    printf("Average Test Marks: %.2f\n", average);


    int passed = hasPassed(cr);
    printf("Has Passed: %s\n", passed ? "True" : "False");

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_STUDENTS 100

struct Student
{
    char name[50];
    int rollNumber;
    float percentage;
};

struct Student database[MAX_STUDENTS];
int numStudents = 0;

void insert(struct Student s)
{
    int i = numStudents - 1;

    while (i >= 0 && database[i].rollNumber > s.rollNumber)
    {
        database[i + 1] = database[i];
        i--;
    }

    database[i + 1] = s;
    numStudents++;
}

void sortName()
{
    int i, j;
    struct Student temp;

    for (i = 0; i < numStudents - 1; i++)
    {
        for (j = 0; j < numStudents - i - 1; j++)
        {
            if (strcmp(database[j].name, database[j + 1].name) > 0)
            {
                temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
}

struct Student *findOne(char *name)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (strncmp(database[i].name, name, strlen(name)) == 0)
        {
            return &database[i];
        }
    }
    return;
}

struct Stats
{
    int count;
    float maxPercentage;
    float minPercentage;
    float mean;
    float standardDeviation;
};

struct Stats specs()
{
    struct Stats stats;
    float sum = 0, sumSq = 0;
    float min = 100, max = 0;

    for (int i = 0; i < numStudents; i++)
    {
        float p = database[i].percentage;
        sum += p;
        sumSq += p * p;
        if (p < min)
            min = p;
        if (p > max)
            max = p;
    }

    stats.count = numStudents;
    stats.maxPercentage = max;
    stats.minPercentage = min;
    stats.mean = sum / numStudents;
    stats.standardDeviation = sqrt(sumSq / numStudents - stats.mean * stats.mean);

    return stats;
}

void delete(int rollNumber)
{
    int i = 0;

    while (i < numStudents && database[i].rollNumber != rollNumber)
    {
        i++;
    }

    if (i == numStudents)
    {
        return;
    }

    for (; i < numStudents - 1; i++)
    {
        database[i] = database[i + 1];
    }
    numStudents--;
}
int main()
{
    struct Student s1 = {"A", 1, 90.0};
    insert(s1);
    struct Student s2 = {"B", 2, 80.0};
    insert(s2);
    sortName();
    struct Student *s = findOne("A");
    printf("Name: %s\n", s->name);
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Percentage: %.2f\n", s->percentage);
    struct Stats s3 = specs();
    printf("Count: %d\n", s3.count);
    printf("Max Percentage: %.2f\n", s3.maxPercentage);
    printf("Min Percentage: %.2f\n", s3.minPercentage);
    printf("Mean: %.2f\n", s3.mean);
    printf("Standard Deviation: %.2f\n", s3.standardDeviation);
    delete (1);
    struct Student *s4 = findOne("B");
    printf("Name: %s\n", s4->name);
    printf("Roll Number: %d\n", s4->rollNumber);
    printf("Percentage: %.2f\n", s4->percentage);
    struct Stats s5 = specs();
    printf("Count: %d\n", s5.count);
    printf("Max Percentage: %.2f\n", s5.maxPercentage);
    printf("Min Percentage: %.2f\n", s5.minPercentage);
    printf("Mean: %.2f\n", s5.mean);
    printf("Standard Deviation: %.2f\n", s5.standardDeviation);
    return 0;
}
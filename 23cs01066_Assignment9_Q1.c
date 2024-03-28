#include <stdio.h>
#include <string.h>

struct Company {
    char name[100];
    char address[100];
    char phone[10];
    char employeeID[10];
};

int main() {
    struct Company E1;
    struct Company *p;
    p = &E1;
    strcpy(p->name, "Vikranth");
    strcpy(p->address, "RHR");
    strcpy(p->phone, "7666570883");
    strcpy(p->employeeID, "0");


    // Access the members of the structure using the pointer
    printf("Name: %s\n", p->name);
    printf("Address: %s\n", p->address);
    printf("Phone: %s\n", p->phone);
    printf("ID: %s\n", p->employeeID);

    return 0;
}
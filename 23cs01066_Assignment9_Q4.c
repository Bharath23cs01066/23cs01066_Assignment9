#include <stdio.h>
#include<string.h>

struct Address {
    char street[100];
    char city[50];
    int zip;
};


struct Person {
    char name[50];
    struct Address address;
};

int main() {

    struct Person p;


    strcpy(p.name, "Vikranth");
    strcpy(p.address.street, "RHR");
    strcpy(p.address.city, "BBS");
    p.address.zip = 123456;


    printf("Name: %s\n", p.name);
    printf("Street: %s\n", p.address.street);
    printf("City: %s\n", p.address.city);
    printf("Zip: %d\n", p.address.zip);

    return 0;
}
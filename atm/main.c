#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ATM System project

void print_account(){

    // Opening account file and if no file is open, exit the program
    FILE *file = fopen("C:/Users/firmt/Git/ATM Syetem/ATM-System/accounts.csv", "r");
    if (file == NULL){
        printf("Error\n");
        exit(1);
    }
    // Declaring a string to store a line read by fgets
    char line[200];

    // Using token to split the line into string then print it out
    while(fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        while(token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
}

int main() {
//    printf("Hello, World!\n");
//    printf("Test GitHub\n");
//    printf("I love pizza\n");
//    printf("Test form, i also love pepporoni pizza\n");
//    printf("I bet Jesus loves pizza too\n");

    print_account();

    return 0;
}

#include <stdio.h>
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
//#include <curses.h>
//                    username    pin
void change_pin_new(char C[], char B[]){
    char line[200];

    char user[50];
    char pin[50];
    char balance[50];
    char user_n[50];
    char pin_n[50];
    char balance_n[50];
    FILE *str = fopen("../accounts.csv", "r");
    FILE *new = fopen("../new.csv", "w");
    if (str == NULL) {
        printf("Error opening file");
        fclose(str);}
    if (new == NULL) {
        printf("Error opening file");
        fclose(new);}

    while(fgets(line, 200, str)){
        char *token;
//        THIS FIRST 'IF CONDITION' CHUNK CHECKS  AND FINDS FOR THE DESIGNATED CHANGE TARGET
        token = strtok(line, ",");
        if (strcmp(token, C) == 0){
            strcpy(user, token);
            token = strtok(NULL, ",");
            strcpy(pin, token);
            token = strtok(NULL, ",");
            strcpy(balance, token);
            token = strtok(NULL, ",");
            strcpy(pin, B);
            fprintf(new, "%s,%s,%s", user, pin, balance);
        }
//        THIS SECOND 'IF CONDITION' CHUNK REWRITES EVERY OTHER THING THAT ISN'T THE CHANGE TARGET INTO NEW FILE
        else{
            strcpy(user_n, token);
            token = strtok(NULL, ",");
            strcpy(pin_n, token);
            token = strtok(NULL, ",");
            strcpy(balance_n, token);
            token = strtok(NULL, ",");
            fprintf(new, "%s,%s,%s", user_n, pin_n, balance_n);
        }
    }
    remove("../accounts.csv");
    rename("../new.csv", "../accounts.csv");
    fclose(str);
    fclose(new);
}
//remove("../accounts.csv");
//rename("../new.csv", "../accounts.csv");

void exit_program(){
    printf("Thank you and have a nice day");
    exit(0);
}

void print_receipt(){
//        int amount_new;
//        amount_new = amount;
//        int thousand = amount_new / 1000;
//        amount = amount_new % 1000;
//        int fvehundred = amount_new / 1000;
//        amount = amount_new % 1000;
//        int onehundred = amount_new / 1000;
//        amount = amount_new % 1000;
//        int ten = amount_new / 1000;
//        amount = amount_new % 1000;
//        int one = amount_new / 1000;
//        amount = amount_new % 1000;
//        if(thousand != 0){
//            printf("Thousand Bank Notes: \t\t%d\n", thousand);
//        }
//        if(fvehundred != 0){
//            printf("Five Hundred Bank Notes: \t%d\n", fvehundred);
//        }
//        if(onehundred != 0){
//            printf("One hundred Bank notes: \t%d\n", onehundred);
//        }
//        if(ten != 0){
//            printf("Ten Baht Coins: \t\t%d\n", ten);
//        }
//        if(one != 0){
//            printf("One Baht Coins: \t\t%d\n", one);
//        }
}
void user_withdraw(double balance, double amount, char*u){
    char date[] = "11/1/2021";
    char line[200];
    char user[50];
    char pin[50];
    char balance_old[50];
    char user_n[50];
    char pin_n[50];
    char balance_n[50];
    char new_balance[50];
    if(balance < 0){
        printf("Unable to continue withdrawal.\n");
        printf("Your remaining balance: .2%lf\n", balance);
    }
    else if (amount < 20){
        printf("Minimum withdrawal: 20 Baht\n");
    }
    else if (amount > balance){
        printf("Request failed\nAmount exceeding balance\n");
        printf("Your remaining balance: .2%lf\n", balance);
    }
    else if (amount <= balance){
        balance = balance - amount;
        printf("Withdrawal Successful\n");
        printf("Your remaining balance: %.2lf\n", balance);
        snprintf(new_balance, 50, "%f", balance);
        FILE *acc = fopen("../accounts.csv", "r");
        FILE *new = fopen("../new.csv", "w");
        if (acc == NULL) {
            printf("Error opening file");
            fclose(acc);}
        if (new == NULL) {
            printf("Error opening file");
            fclose(new);}
        while(fgets(line, 200, acc)){
            char *token;
//        THIS FIRST 'IF CONDITION' CHUNK FINDS FOR THE DESIGNATED CHANGE TARGET THEN REPLACES THE BALANCE VALUE
            token = strtok(line, ",");
            if (strcmp(token, u) == 0){
                strcpy(user, token);
                token = strtok(NULL, ",");
                strcpy(pin, token);
                token = strtok(NULL, ",");
                strcpy(balance_old, token);
                token = strtok(NULL, ",");
                strcpy(balance_old, new_balance);
                fprintf(new, "%s,%s,%s", user, pin, new_balance);
            }
//        THIS SECOND 'IF CONDITION' CHUNK REWRITES EVERY OTHER THING THAT ISN'T THE CHANGE TARGET INTO "NEW" FILE
            else{
                strcpy(user_n, token);
                token = strtok(NULL, ",");
                strcpy(pin_n, token);
                token = strtok(NULL, ",");
                strcpy(balance_n, token);
                token = strtok(NULL, ",");
                fprintf(new, "%s,%s,%s", user_n, pin_n, balance_n);
            }
        }
        remove("../accounts.csv");
        rename("../new.csv", "../accounts.csv");
        fclose(acc);
        fclose(new);
        FILE *update_action = fopen("../Action.csv", "a");
        if (update_action == NULL) {
            printf("Error opening file");
            fclose(update_action);
        }
        fprintf(update_action, "\n%s,%s,-%lf", u, date, amount);
        fclose(update_action);
    }
}

void user_deposit(double balance, double amount, char*u) {
    char date[] = "11/1/2021";
    char line[200];
    char user[50];
    char pin[50];
    char balance_old[50];
    char user_n[50];
    char pin_n[50];
    char balance_n[50];
    char new_balance[50];
    if (amount <= 0) {
        printf("Please enter a valid amount.\nMinimum amount of deposit: 1 Baht\n");
    } else if (amount > 0) {
        balance = balance + amount;
        printf("Deposit Successful\n");
        printf("Your remaining balance: %.2lf\n", balance);
        snprintf(new_balance, 50, "%f", balance);
        FILE *acc = fopen("../accounts.csv", "r");
        FILE *new = fopen("../new.csv", "w");
        if (acc == NULL) {
            printf("Error opening file");
            fclose(acc);}
        if (new == NULL) {
            printf("Error opening file");
            fclose(new);}
        while(fgets(line, 200, acc)){
            char *token;
//        THIS FIRST 'IF CONDITION' CHUNK CHECKS FINDS FOR THE DESIGNATED CHANGE TARGET THEN REPLACES BALANCE VALUE
            token = strtok(line, ",");
            if (strcmp(token, u) == 0){
                strcpy(user, token);
                token = strtok(NULL, ",");
                strcpy(pin, token);
                token = strtok(NULL, ",");
                strcpy(balance_old, token);
                token = strtok(NULL, ",");
                strcpy(balance_old, new_balance);
                fprintf(new, "%s,%s,%s", user, pin, new_balance);
            }
//        THIS SECOND 'IF CONDITION' CHUNK REWRITES EVERY OTHER THING THAT ISN'T THE CHANGE TARGET INTO "NEW" FILE
            else{
                strcpy(user_n, token);
                token = strtok(NULL, ",");
                strcpy(pin_n, token);
                token = strtok(NULL, ",");
                strcpy(balance_n, token);
                token = strtok(NULL, ",");
                fprintf(new, "%s,%s,%s", user_n, pin_n, balance_n);
            }
        }
        remove("../accounts.csv");
        rename("../new.csv", "../accounts.csv");
        fclose(acc);
        fclose(new);
    }

    FILE *update_action = fopen("../Action.csv", "a");
    if (update_action == NULL) {
        printf("Error opening file");
        fclose(update_action);
    }
    fprintf(update_action, "\n%s,%s,+%lf", u, date, amount);
    fclose(update_action);
}

void user_transfer(double balance, char destination[], double destination_balance) {
    char line[200];

    FILE *stream = fopen("../accounts.csv", "r");
    if (stream == NULL) {
        printf("Error opening file");
        fclose(stream);
        exit(1);
    }

    while (fgets(line, sizeof(line), stream)) {
        char *token;
        token = strtok(line, ",");
        if (strcmp(token, destination) == 0) {
            printf("Enter amount of transaction: ");
            double amount;
            scanf("%lf", &amount);
            if(amount <= 0){
                printf("Minimum amount of transaction is 1 Baht\n");
            }
            else if(amount > balance){
                printf("Amount exceeding your balance.\n");
                printf("Your remaining balance: %lf\n", balance);
            }
            else if(amount <= balance){
                destination_balance += amount;
                balance -= amount;
                printf("Transaction successful.\n");
                printf("Your remaining balance: %lf\n", balance);
            }
        }
    }
}

void history(char A[]) {
    char l[200];
    char user[50];
    char date[50];
    char action[50];
    FILE *hist = fopen("../Action.csv", "r");
    if (hist == NULL) {
        printf("Error opening file");
        fclose(hist);
    }

    while (fgets(l, sizeof(l) , hist)) {
        char *token;
        token = strtok(l, ",");
        while (token != NULL) {
            if (strcmp(token, A) == 0) {
                strcpy(user, token);
                token = strtok(NULL, ",");
                strcpy(date, token);
                token = strtok(NULL, ",");
                strcpy(action, token);
                token = strtok(NULL, ",");
            }
        }
        if (atoi(action) < 0) {
            printf("%s has transferred/withdraw\t: %d\t on %s\n", user, atoi(action), date);
        }
        else {
            printf("%s has deposited\t\t\t: +%d\t on %s\n", user, atoi(action), date);
        }
    }
    fclose(hist);
}

double balance_check(char *username){
    char line[200];
    FILE *accounts = fopen("../accounts.csv", "r");
    if (accounts == NULL){
        printf("Unable to open file");
        exit(1);
    }
    while(fgets(line, sizeof(line), accounts)){
        char *token;
        token = strtok(line, ",");
        while(token != NULL){
            if (strcmp(token, username) == 0){
                token = strtok(NULL, ",");
                token = strtok(NULL, ",");
                return atof(token);
            }
            else{
                token = strtok(NULL, ",");
            }
        }
    }
    fclose(accounts);
    return 0;
}

char* login(){
    char user_input[50];
    char line[200];
    int user_count = 3;
    FILE *stream = fopen("../accounts.csv", "r");
    if (stream == NULL){
        printf("Error opening file");
        fclose(stream);
        exit(1);
    }
    // Checking if user_input is a username in accounts.csv or not
    // User can input username 3 times, after the third time
    // if username is still not found, the program will terminate
    while (user_count != 0) {
        printf("Enter username: ");
        scanf("%s", user_input);
        if (strcmp(user_input, "quit") == 0) {
            fclose(stream);
            exit_program();
        }
        // Inside this loop, token is the value of usernames stored in accounts.csv
        // If username is matched, it will exit the loop and continue to ask for PIN
        while (fgets(line, sizeof(line), stream)) {
            char *token;
            token = strtok(line, ",");
            if (strcmp(token, user_input) == 0){
                // Username FOUND
                goto JUMP;
            }
        }
        printf("Username NOT found\n");
        printf("You have %d chance(s) left\n", --user_count);
        fseek(stream, 0, SEEK_SET);
    }
    printf("Please contact XXX to unlock your account\n");
    fclose(stream);
    exit(0);
    // End of username checking
    JUMP:
    printf("\n");
    // Begin of PIN checking
    // token is now the PIN of that specific username
    char *token;
    token = strtok(NULL, ",");
    fclose(stream);
    int pin_count = 3;
    // Username has 3 chances to enter PIN correctly
    while (pin_count != 0){
        printf("Enter PIN: ");
        char pin_input[10];
        scanf("%s", pin_input);
        if (strcmp(line, "quit") == 0) {
            fclose(stream);
            exit_program();
        }
        if (strcmp(token, pin_input) == 0){
            // Enter PIN successfully
            goto END;
        }
        printf("Wrong PIN\n");
        printf("You have %d chance(s) left\n", --pin_count);
    }
    printf("Account locked\n");
    exit(0);
    END:
    printf("Login successful\n");
    // Function is returning a char pointer to the username
    // user_input is only a local variable, so we need to create
    // a variable that can be accessed from main()
    char *rtn_user = (char*)malloc(sizeof(user_input));
    strcpy(rtn_user, user_input);
    return rtn_user;
}

void create_username(){
    printf("Welcome to Mega bank New User!\nWe are extremely happy that you chose our service\n"
           "We are thrilled to serve you with our upmost service\n");
    sleep(2);
    printf("------------------------------------------------------------------------\n");
    char line[200];
    char user_input[50];
    char pin_input[10];
    int duplicate = 0;
    int digits = 0;
    int count = 0;
    int number = 0;
    int str_cmp;
    printf("Create an account\nYour PIN must be 6 digits and contain all numbers.\n");
    printf("Type \"quit\" to exit the program\n");
    printf("---------------------------------\n");
    begin_create:
    // User input username
    printf("Enter your username: ");
    gets(user_input);
    duplicate = 0;
    digits = 0;
    count = 0;
    number = 0;
    FILE *stream = fopen("../accounts.csv", "r");
    // exit point if type "quit"
    if (strcmp(user_input, "quit") == 0){
        printf("Thank you!");
        fclose(stream);
        exit(0);
    }
    // Check if username has already taken or not
    while (fgets(line, sizeof(line), stream)){
        char *token;
        token = strtok(line, ",");
        while (token != NULL){
            str_cmp = strcmp(token, user_input);
            if (str_cmp == 0){
                printf("Username has already been taken\n");
                printf("------------------------\n");
                duplicate++;
            }
            token = strtok(NULL, ",");
        }
    }
    // Check if user_input is between 8 - 12 or not
    if ((strlen(user_input) < 8) || (strlen(user_input) > 12)) {
        printf("Your username must be in between 8-12 characters\n");
        printf("------------------------\n");
        count++;
    }
    // Goto begin_create if user_input is invalid
    if ((duplicate || count) > 0){
        fclose(stream);
        goto begin_create;
    }
    // Success inputting username and closing the read mode file
    fclose(stream);
    stream = NULL;
    // End of inputting username
    // User input PIN
    printf("Enter PIN: ");
    gets(pin_input);
    // exit point if type "quit"
    if (strcmp(pin_input, "quit") == 0){
        printf("Thank you!");
        exit(1);
    }
    // Check if PIN is 6 digits or not
    if ((strlen(pin_input) < 6) || (strlen(pin_input) > 6)){
        printf("Your PIN must be 6-digits\n");
        printf("------------------------\n");
        digits++;
    }
    // Check if pin_input is all numbers or not
    for (int i = 0; i < strlen(pin_input); i++){
        if ((pin_input[i] < 48) || (pin_input[i] > 57)){
            printf("PIN must be in numbers. \n");
            printf("------------------------\n");
            number++;
            break;
        }
    }
    // Goto begin_create if pin_input is invalid
    if ((number || digits) > 0){
        goto begin_create;
    }
    // Minimum cash to create an account
    float cash;
    printf("Minimum cash of 200BHT is needed to be deposited to create an account\n");
    printf("------------------------------------------\n");
    minimum_cash:
    printf("Please enter the about of cash you want to deposit: \n");
    scanf("%f", &cash);
    if (cash < 200){
        printf("Minimum is 200BHT\n");
        cash = 0;
        goto minimum_cash;
    }
    // Opening csv file as append mode
    FILE* file = fopen("../accounts.csv", "a");
    if (stream == file){
        printf("Open file to append error");
        exit(1);
    }
    // Set file to the end and start appending user inputs.
    fseek(file, 0, SEEK_END);
    fprintf(file, "%s,%s,%f\n", user_input, pin_input, cash);
    fclose(file);
    // End of creating user
    printf("To proceed, the system will be taking you back to login menu\n");
    sleep(2);
    printf("------------------------------------------------------------------------\n");
//    The function end here and continue at the main function from the line after this function
}

void border_line(){
//    sleep(2);
    printf("------------------------------------------------------------------------\n");
}

// This function is not a feature that user can access.
// This is just for running checks
void print_account(){
    FILE* stream = fopen("../accounts.csv", "r");
    if (stream == NULL){
        printf("Error can't open file");
        exit(1);
    }
    char line[200];
    while (fgets(line, sizeof(line), stream)){
        char *token;
        token = strtok(line, ",");
        if (token != NULL){
            printf("%s", token);
            strtok(NULL, token);
        }
    }
}

int main() {
//    char username[] = "babywoowoo";
//    char pin[] = "111111";
//    change_pin_new(username, pin);

    char* username;
    char user_password[50];

    int main_menu_input;
    int page_input;


    greetings:
    fflush(stdin);
    main_menu_input = 0;
    printf("Hello welcome to Mega bank ;3\nWe are the project of Firm, Fill and Zhen\n");
    sleep(2);
    printf("Please login to proceed further\n\n");
    border_line();
    printf("[1]\tLogin\n");
    printf("[2]\tCreate New Username\n");
    printf("Enter your number:");
    scanf("%d", &main_menu_input);
    switch (main_menu_input) {
        case 1:
            border_line();
            goto login;
        case 2:
            border_line();
            goto create_user;
        default:
            printf("Invalid operator\n Please try again");
            border_line();
            goto greetings;
    }

    create_user:
    create_username();
    goto greetings;

    login:
    fflush(stdin);
    username = login();
    printf("Username is: %s\n", username);// This is just for checking if it works or not

    main_menu:
    printf("*Please type in the number of the service you wish to operate*\n");
    printf("[1]\tDeposit\n");
    printf("[2]\tWithdraw\n");
    printf("[3]\tCheck Balance\n");
    printf("[4]\tSee History\n");
    printf("[5]\tChange Pin\n");
    printf("[6]\tTransfer\n");
    printf("[7]\tExit Program\n");
    printf("Enter your number:");
    scanf("%d", &main_menu_input);
    switch (main_menu_input) {
        case 1:
            border_line();
            goto deposit;
        case 2:
            border_line();
            goto withdraw;
        case 3:
            border_line();
            goto balance;
        case 4:
            border_line();
            goto history;
        case 5:
            border_line();
            goto pin_change;
        case 6:
            border_line();
            goto transfer;
        case 7:
            border_line();
            printf("Thank you for using our bank have a good time!\n");
            goto exit;

        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto main_menu;
    }


    pin_change:
//    The code for changing pin here, however if it's too long Then use a function
    printf("Process finished, taking you back to main menu");
    border_line();
    goto main_menu;

    transfer:
    printf("---TRANSFER MENU---\n");
    char line[200];
    FILE *stream = fopen("../accounts.csv", "r");
    double transfer_balance = balance_check(username);
    char destination[50];
    while (1 == 1) {
        printf("Enter name of recipient: ");
        scanf("%s", destination);
        if (strcmp(destination, "quit") == 0) {
            fclose(stream);
            exit_program();
        }
        // Inside this loop, token is the value of usernames stored in accounts.csv
        // If username is matched, it will exit the loop and continue to ask for PIN
        while (fgets(line, sizeof(line), stream)) {
            char *token;
            token = strtok(line, ",");
            if (strcmp(token, destination) == 0){
                double destination_balance = balance_check(destination);
                user_transfer(transfer_balance, destination, destination_balance);
                goto transfer_option;
            }
        }
        printf("USERNAME NOT FOUND\nTRY AGAIN\n");
        goto transfer_option;
    }

    transfer_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tTransfer Again\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        case 3:
            border_line();
            goto transfer;
        default:
            border_line();
            goto transfer_option;
    }


    exit:
    _exit(0);


    balance:
    printf("%s your balance is: ", username);
    double balance = balance_check(username);
    printf("%.2f", balance);
    printf("\n");
    balance_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        default:
            border_line();
            goto balance_option;
    }

    history:
    history(username);
    printf("[1]\tGo back to main menu\n");
    history_option:
    printf("[2]\tExit\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto history_option;
    }


    deposit:
    printf("*Select command*\n");
    deposit_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tDeposit\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        case 3:
            border_line();
            goto deposit_process;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto deposit_option;
    }

    withdraw:
    printf("*Select command*\n");
    withdraw_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tWithdraw\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        case 3:
            border_line();
            goto withdraw_process;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto withdraw_option;
    }

    withdraw_process:
    printf("Please enter amount of withdrawal: ");
    double amount;
    scanf("%lf", &amount);
    double withdraw_balance = balance_check(username);
    user_withdraw(withdraw_balance, amount, username);
    user_withdraw_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tGet receipt\n");
    printf("[4]\tWithdraw Again\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        case 3:
            border_line();
            goto get_receipt;
        case 4:
            border_line();
            goto withdraw_process;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto user_withdraw_option;
    }


    deposit_process:
    printf("Please enter amount to deposit: ");
    scanf("%lf", &amount);
    double deposit_balance = balance_check(username);
    user_deposit(deposit_balance, amount, username);
    user_deposit_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tGet receipt\n");
    printf("[4]\tDeposit Again\n");
    printf("Enter your number:");
    scanf("%d", &page_input);
    switch (page_input) {
        case 1:
            border_line();
            goto main_menu;
        case 2:
            border_line();
            goto exit;
        case 3:
            border_line();
            goto get_receipt;
        case 4:
            border_line();
            goto deposit_process;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto user_deposit_option;
    }

    get_receipt:
//        If this is a hassle you can place the code directly into the switch case
    print_receipt();
    printf("Process finished, going back to main menu");
    border_line();
    goto main_menu;

    return 0;
}




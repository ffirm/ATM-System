#include <stdio.h>
#include "string.h"
#include <unistd.h>
//#include <curses.h>

void print_receipt(){
//    code for printing receipt
}
void user_withdraw(){
//    The code for withdrawing
}
void user_deposit(){
//    The code for depositing
}
void history_check(){
//    The code for checking history
}
void balance_check(){
//    The code for printing balance
}

void check_login(){
//    The code for checking username from file
}

void create_username(){
    printf("Welcome to Mega bank New User!\nWe are extremely happy that you chose to user our service\n"
           "We are thrilled to serve you with our upmost service\n");
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
    printf("%s%s%f", user_input, pin_input, cash);
    fprintf(file, "%s,%s,%f\n", user_input, pin_input, cash);
    fclose(file);
    // End of creating user
    printf("To proceed, the system will be taking you back to login menu");
    sleep(2);
    printf("------------------------------------------------------------------------\n");
//    The function end here and continue at the main function from the line after this function
}

void border_line(){
    sleep(2);
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
    char username_input[50];
    char user_password[50];

    char og_user[]="MEGA";
    char og_password[]="123456";
    int comparison;

    int main_menu_input;
    int page_input;

    greetings:
    printf("Hello welcome to Mega bank ;3\nWe are the project of Firm, Fill and Zhen\n");
    sleep(2);
    printf("Please login to proceed further\n\n");
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
//        Create_user function should be here
    create_username();
    goto greetings;


    login:
    printf("\n");
    printf("Note: For this test please enter username as MEGA and pin as 123456\nThe pin shouldn't exceed 6 digits\n");
    printf("Please enter your username:");
    scanf("%s", username_input);
    printf("Please enter your banking pin:");
    scanf("%s", user_password);
//    strcmp is a function to compare two string, it returns int value of 0 when it is the same

// This is where the check_login function should be placed //VV//

    comparison = strcmp(username_input, og_user) + strcmp(user_password, og_password);
    if (comparison == 0){
        printf("Welcome to the banking system %s, have a great time!\n", username_input);
        printf("The system will now bring you to the main menu please stay put\n");
        border_line();
        goto main_menu;
    }
    else{
        printf("Incorrect attempt, please try again\n");
        border_line();
        goto login;
    }
// If you found that the code do not function properly you can manually code it in this space
//    ^^^^

    main_menu:
    printf("*Please type in the number of the service you wishes to operate*\n");
    printf("[1]\tDeposit, Withdraw\n");
    printf("[2]\tCheck Balance\n");
    printf("[3]\tSee History\n");
    printf("[4]\tChange Pin\n");
    printf("[5]\tTransfer\n");
    printf("[6]\tExit Program\n");
    printf("Enter your number:");
    scanf("%d", &main_menu_input);
    switch (main_menu_input) {
        case 1:
            border_line();
            goto deposit;
        case 2:
            border_line();
            goto balance;
        case 3:
            border_line();
            goto history;
        case 4:
            border_line();
            goto pin_change;
        case 5:
            border_line();
            goto transfer;
        case 6:
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
//    The code for transferring money here, however if it's too long Then use a function
    printf("Process finished, taking you back to main menu");
    border_line();
    goto main_menu;

    exit:
    _exit(0);


    balance:
//        Instead of this print line Use the provided function instead

    balance_check();
    printf("Your balance is ******* baht\n");

//    ^^^
    printf("[1]\tGo back to main menu\n");
    balance_option:
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
    //        Instead of this print line Use the provided function instead

    history_check();
    printf("Your history is *******\n");

//    ^^^
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
    printf("*Select command*\n*Note deposit and withdraw is still a work in progress*\n");
    deposit_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tDeposit\n");
    printf("[4]\tWithdraw\n");
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
        case 4:
            border_line();
            goto withdraw_process;
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto deposit_option;
    }


    withdraw_process:
    user_withdraw();
    user_withdraw_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tGet receipt\n");
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
        default:
            printf("Invalid operator, please enter again\n");
            border_line();
            goto user_withdraw_option;
    }


    deposit_process:
//  function call for deposit process
    user_deposit();
    user_deposit_option:
    printf("[1]\tGo back to main menu\n");
    printf("[2]\tExit\n");
    printf("[3]\tGet receipt\n");
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



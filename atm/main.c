#include <stdio.h>
#include "string.h"
#include <unistd.h>
//#include <curses.h>

void print_receipt(){
//    code for printing receipt
}
void user_withdraw(){
    int amount;
    printf("Enter the amount of money you would like to withdraw\n");
    scanf("%d", &amount);


}
void user_deposit(){
    int username;
    printf("Enter the username of your recipient\n");
    scanf("%d", &username);

}
void history_check(){
//    The code for checking history
}
void balance_check(){
    FILE *accounts = fopen("accounts.csv", "r");
    if (accounts == NULL){
        printf("Bruh\n");
        exit(1);
    }
    char line[200];
    while(fgets(line, sizeof(line), accounts))  {
        char *token;
        token = strtok(line, ",");
        while(token != NULL)                    {
            printf("%s", token);
            token = strtok(NULL, ",");
                                                }
        printf("\n");7777
                                                }
    printf("Your balance is ******* baht\n");
}

void check_login(){
//    The code for checking username from file
}

void create_username(){
    printf("Welcome to Mega bank New User!\nWe are extremely happy that you chose to user our service\n"
           "We are thrilled to serve you with our upmost service\n");
    // The code for creating user_name
    printf("To proceed, the system will be taking you back to login menu");
    sleep(2);
    printf("------------------------------------------------------------------------\n");
//    The function end here and continue at the main function from the line after this function
}

void border_line(){
    sleep(2);
    printf("------------------------------------------------------------------------\n");
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
    printf("*Please type in the number of the service you wish to operate*\n");
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
            goto deposit_withdraw;
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


    deposit_withdraw:
    printf("*Select command*\n");
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



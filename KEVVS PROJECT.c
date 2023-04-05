#include<stdio.h>
#include<string.h>

int trials=3;
char d[20]= "Kevv321";
char u[20];
int c, option, wish, deposit, proceed, acc_no;
float withdrawal;
float balance=1000;

void login_page();
void second_transaction();
void withdraw_transfer();
void login_success();

int main(){
login_page();
scanf("%s", &u);
trials--;
c=strcmp(d,u);
if(c==0){
login_success();
}
else{
    if(trials>0){
        printf("Wrong password\n");
        main();
    }
    else{
        printf("You have exhausted your attempts\nPlease try again later\n\n");
        
    }
}
return 0;
}


void login_page(){
printf("Please enter your password\n %d attempts remaining\n", trials);
}
void login_success(){
        printf("\n.........................\n");
        printf("    KEVVS ATM MACHINE       ");
        printf("\n'''''''''''''''''''''''''\n");
        printf("    ATM SERVICES\n");
        printf("   1.Check Balance\n   2.Deposit\n   3.Withdraw\n   4.Transfer Cash\n   5.Quit\n.........................\n  Choose your option: ");
        scanf("%d",&option);
    switch (option){
    case 1:
        printf("\nYour balance is: Ksh%f\n", balance);
       second_transaction();
        break;
    case 2:
        printf("\nEnter the amount you wish to deposit\n   Ksh");
        scanf("%d", &deposit);
        balance=balance+deposit;
        printf("\nDeposit successful, your new balance is Ksh%f\n", balance);
        second_transaction();
        break;
    case 3:
        printf("\nEnter the amount you wish to withdraw\n   Ksh");
        scanf("%f", &withdrawal);
        withdraw_transfer();
        break;
    case 4:
        printf("\nEnter the recipient's account number:");
        scanf("%d", &acc_no);
        printf("\nEnter the amount you wish to transfer\n   Ksh");
        scanf("%f", &withdrawal);
        withdraw_transfer();
        break;
    case 5:
        printf("\nThank you for using DKUT ATM\n");
       
        break;
    default:
        printf("\nPlease enter a valid option");
        break;
    }
}
void second_transaction(){
            printf("Do you wish to perform another transaction?\n1.Yes  2.No\nYour option: ");
        scanf("%d", &wish);
        if(wish==1){
            login_success();
        }
        else if(wish==2){
                printf("\nThank you for using DKUT ATM\n");
           
        }
        else{
            printf("\nPlease enter a valid option!\n");
            second_transaction();
        }
        }
void withdraw_transfer(){
    float charges=withdrawal*0.02;
    float deduction=withdrawal+charges;
    if(deduction<=balance){
        printf("\nA transaction fee of Ksh%f will apply\nTotal amount to be deducted will be Ksh%f\nDo you wish to continue?\n1.Yes  2.No\n", charges, deduction);
        scanf("%d", &proceed);
        if(proceed==1){
            balance=balance-deduction;
            printf("\n Transaction successful, your new balance is %f", balance);
            second_transaction();
        }
        else if(proceed==2){
            printf("\n Transaction cancelled\n");
            second_transaction();
        }
        else {
             printf("\nPlease enter a valid option!\n");
            withdraw_transfer();
        }
    }
    else {
        printf("\nFailed, you have insufficient funds in your account\n");
        second_transaction();
    }
        }

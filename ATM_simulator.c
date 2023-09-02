/*Task 7 : ATM Simulator
Write a program that simulates an ATM machine and allows users to deposit, withdraw, and check their balance.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_USERS 10
struct User
{
    int accountNumber;
    int pin;
    int balance;
};
int findUser(struct User users[], int accountNumber, int totalUsers)
{
    for (int i = 0; i < totalUsers; i++)
    {
        if (users[i].accountNumber == accountNumber)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    struct User users[MAX_USERS];
    int totalUsers = 0;
    srand(time(NULL));
    while (true)
    {
        printf("\nATM Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                if (totalUsers < MAX_USERS)
                {
                    struct User newUser;
                    newUser.accountNumber = rand() % 9000 + 1000;
                    printf("Your account number: %d\n", newUser.accountNumber);
                    printf("Enter a 4-digit PIN: ");
                    scanf("%d", &newUser.pin);
                    printf("Enter initial deposit amount: ");
                    scanf("%d", &newUser.balance);
                    users[totalUsers++] = newUser;
                    printf("Account created successfully!\n");
                }
                else
                {
                    printf("Maximum number of users reached.\n");
                }
                break;
            }
            case 2:
            {
                int accountNumber, depositAmount;
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                int userIndex = findUser(users, accountNumber, totalUsers);
                if (userIndex != -1)
                {
                    printf("Enter amount to deposit: ");
                    scanf("%d", &depositAmount);
                    users[userIndex].balance += depositAmount;
                    printf("Amount deposited: Rs %d\n", depositAmount);
                }
                else
                {
                    printf("Account not found.\n");
                }
                break;
            }
            case 3:
            {
                int accountNumber, withdrawalAmount, enteredPin;
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                int userIndex = findUser(users, accountNumber, totalUsers);
                if (userIndex != -1)
                {
                    printf("Enter your PIN: ");
                    scanf("%d", &enteredPin);
                    if (enteredPin == users[userIndex].pin)
                    {
                        printf("Enter amount to withdraw: ");
                        scanf("%d", &withdrawalAmount);
                        if (withdrawalAmount <= users[userIndex].balance)
                        {
                            users[userIndex].balance -= withdrawalAmount;
                            printf("Amount withdrawn: Rs %d\n", withdrawalAmount);
                        }
                        else
                        {
                            printf("Insufficient balance.\n");
                        }
                    }
                    else
                    {
                        printf("Invalid PIN.\n");
                    }
                }
                else
                {
                    printf("Account not found.\n");
                }
                break;
            }
            case 4:
            {
                int accountNumber, enteredPin;
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                int userIndex = findUser(users, accountNumber, totalUsers);
                if (userIndex != -1)
                {
                    printf("Enter your PIN: ");
                    scanf("%d", &enteredPin);
                    if (enteredPin == users[userIndex].pin)
                    {
                        printf("Your current balance is: Rs %d\n", users[userIndex].balance);
                    }
                    else
                    {
                        printf("Invalid PIN.\n");
                    }
                }
                else
                {
                    printf("Account not found.\n");
                }
                break;
            }
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int accountNo;
    char name[50];
    float balance;
};

void printLowBalanceCustomers(struct Customer customers[], int numCustomers) {
    printf("\nCustomers with low balance:\n");
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].balance < 100) {
            printf("Account No.: %d, Name: %s\n", customers[i].accountNo, customers[i].name);
        }
    }
}

int main() {

    struct Customer customers[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter customer %d account number: ", i+1);
        scanf("%d", &customers[i].accountNo);
        printf("Enter customer %d name: ", i+1);
        scanf("%s", customers[i].name);
        printf("Enter customer %d balance: ", i+1);
        scanf("%f", &customers[i].balance);
    }

    printLowBalanceCustomers(customers, 3);

}

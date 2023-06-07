#include <stdio.h>

struct Account_info {
	char name[50];
	int acc_num;
	int balance;
};
void low_balance_customer(struct Account_info acc_holder[20]) {
	printf("Account Holders with balance less than $200: \n");
	printf("Name\n");
	for(int i = 0; i < 20; i++) {
		if(acc_holder[i].balance < 200) {
			printf("%s\n", &acc_holder[i].name);
		}
		else {
			continue;
		}
	}
}
void special_increment(struct Account_info acc_holder[20]) {
	printf("Account Holders with Incremented Balances: \n");
	printf("Name\t\tBalance\n");
	for(int i = 0; i < 20; i++) {
		if(acc_holder[i].balance > 1000) {
			acc_holder[i].balance = acc_holder[i].balance + 100;
			printf("%s\t\t%d\n", acc_holder[i].name, acc_holder[i].balance);
		}
		else {
			continue;
		}
	}

}
int main() {
	struct Account_info acc_holder[20];

	for(int i = 0; i < 20; i++) {
		printf("Enter name of account holder - ");
		scanf("%s", &acc_holder[i].name);
		printf("Enter account number - ");
		scanf("%d", &acc_holder[i].acc_num);
		printf("Enter bank balance - ");
		scanf("%d", &acc_holder[i].balance);
	}
	low_balance_customer(acc_holder);
	special_increment(acc_holder);

	FILE *fptr;
	fptr = fopen("Bank_info.txt","w");
	fprintf(fptr, "Name\t\tBalance\n");
	for(int i = 0; i < 20; i++) {
		fprintf(fptr, "%s\t\t%d\n", acc_holder[i].name, acc_holder[i].balance);
	}

	return 0;
}

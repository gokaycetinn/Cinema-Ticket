#include <stdio.h>
#include <stdlib.h>
int money= 0;
int ct = 1;
int A = 40;
int B = 40;
int C = 40;
int D = 40;
int ap = 100;
int bp = 80;
int cp = 60;
int dp = 40;


int CalculateBill(int price, int num);
void printMainMenu(int *A, int *B, int *C, int *D, int *ap, int *bp, int *cp, int *dp);
void printSeatInformation(int *A, int *B, int *C, int *D);
void printTicketPrices(int *ap, int *bp, int *cp, int *dp);
void printCashInfo();
int Control(int seat, int num);
void updatePrices(int *ap, int *bp, int *cp, int *dp);
void sell(int *A, int *B, int *C, int *D, int *ap, int *bp, int *cp, int *dp);
void printTickets(int *A, int *B, int *C, int *D);


//1
void printMainMenu(int *A, int *B, int *C, int *D, int *ap, int *bp, int *cp, int *dp){

    int ch;
    int money = 0;
    printf("\n---------------\nOPERATIONS:\n---------------\n");
    printf("1. Seat Info\n2. Sell a ticket\n3. Current cash info\n4. Quit\nSelect your operation:");
	scanf("%d", &ch);
	
	if (ch == 1){
        printf("**************************************\n");
        printSeatInformation(A, B, C, D);
        printTicketPrices(ap, bp, cp, dp);
        printf("**************************************\n\n");
		
} 
  
    
    else if (ch == 2)
    {
        printf("**************************************\n");
        printSeatInformation(A, B, C, D);
        printTicketPrices(ap, bp, cp, dp);
        printf("**************************************\n");
        sell(A, B, C, D, ap, bp, cp, dp);
        printf("\n**************************************\n");
        printSeatInformation(A, B, C, D);
        printf("**************************************\n");
        printf("\n---------------\nOPERATIONS:\n---------------\n");
        printf("1. Continue to sell a ticket\n2. Return to main menu\n");
        int nwch;
        printf("Select your operation : ");
        scanf("%d", &nwch);
        if (nwch == 1)
        {
            
            printSeatInformation(A, B, C, D);
            
            printTicketPrices(ap, bp, cp, dp);
            printf("**************************************\n");
            sell(A, B, C, D, ap, bp, cp, dp);
            printf("**************************************\n");
            printSeatInformation(A, B, C, D);
            printf("**************************************");
        }
        else if (nwch == 2)
        {
        }
    }

else if (ch == 3)
    {
        
        printCashInfo();
        printf("**************************************\n");
    }
    
    else if (ch == 4)
    {
       
        printCashInfo();
        printf("\nBye!\n");
        ct = 0;}
}

//2
void printTicketPrices(int *ap,int *bp,int *cp,int *dp){
	printf("Current Price Information :\n");
    printf("Level A : %d\n", *ap);
    printf("Level B : %d\n", *bp);
    printf("Level C : %d\n", *cp);
    printf("Level D : %d\n", *dp);
	}
    

//3
void printSeatInformation(int *A,int *B,int *C,int *D){
	printf("Current Seat Information :\n");
    printf("Level A : %d\n", *A);
    printf("Level B : %d\n", *B);
    printf("Level C : %d\n", *C);
    printf("Level D : %d\n", *D);
	}
//4
int Control(int seat, int num)

{
    if (seat >= num)
    {
        return 1;
}
    else
    {
        return 0; }
}
//5
void sell(int *A, int *B, int *C, int *D, int *ap, int *bp, int *cp, int *dp){
	
	char level;
    printf("Select level : ");
    scanf(" %c", &level);
    if (level == 'd' || level == 'D'){
	
    
        int ticket;
        printf("Enter number of tickets for level D seat : ");
        scanf("%d", &ticket);
        if (Control(*D, ticket))
        {
            printf("%d Seats from Level D is sold\n", ticket);
            int bill = CalculateBill(*dp, ticket);
            *D = *D- ticket;
            money = bill+ money;
            printf("Your bill is %d*%d=%d TL", ticket, *dp, bill);
        }
	else
        {
            printf("There is no enough seat for this level\n");
        }
    }
    else if (level == 'b' || level == 'B')
    {
        int ticket;
        printf("Enter number of tickets for level B seat : ");
        scanf("%d", &ticket);
        if (Control(*B, ticket))
        {
            printf("%d Seats from Level B is sold\n", ticket);
            int bill = CalculateBill(*bp, ticket);
            *B = *B - ticket;
            money = money + bill;
            printf("Your bill is %d*%d=%d TL", ticket, *bp, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
	}

else if (level == 'a' || level == 'A')
    {
        int ticket;
        printf("Enter number of tickets for level A seat : ");
        scanf("%d", &ticket);
        if (Control(*A, ticket))
        {
            printf("%d Seats from Level A is sold\n", ticket);
            int bill = CalculateBill(*ap, ticket);
            *A = *A - ticket;
            money = money + bill;
            printf("Your bill is %d*%d=%d TL", ticket, *ap, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
	}

else if (level == 'C' || level == 'C')
    {
        int ticket;
        printf("Enter number of tickets for level C seat : ");
        scanf("%d", &ticket);
        if (Control(*C, ticket))
        {
            printf("%d Seats from Level C is sold\n", ticket);
            int bill = CalculateBill(*bp, ticket);
            *C = *C - ticket;
            money = money + bill;
            printf("Your bill is %d*%d=%d TL", ticket, *cp, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
	}
}
//6


void printCashInfo()

{
    printf("\n\nTotal bill : %d TL\n", money);
    
}
//7
void printTickets(int *A, int *B, int *C, int *D)

{
    printf("Current Seat Information :\n");
    printf("\t\t\tLevel A : %d\n", *A);
    printf("\t\t\tLevel B : %d\n", *B);
    printf("\t\t\tLevel C : %d\n", *C);
    printf("\t\t\tLevel D : %d\n", *D);
}
//8
int CalculateBill(int price, int num)

{
    return price * num;
}

	
int main(){
    int ch;
	while (ct)
    {
        printMainMenu(&A, &B, &C, &D, &ap, &bp, &cp, &dp);
    }
}

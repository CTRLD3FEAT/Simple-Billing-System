#include <stdio.h>
#include <stdlib.h>



 //Function to display all the offerings in the menu in a left aligned, clear format.
void printMenu(char menu[][25], float prices[]){
    printf("---------------------------------\n");
    printf("       CAFE ALPHA OFFERINGS        ");
    printf("\n---------------------------------\n");

    for(int i=0; i<8; i++) {
        printf("%d.%-12s $%.2f\n",i+1, menu[i], prices[i]);
    }
}

 //Function to print the final receipt

void Receipt(char menu[][25], float prices[], int billqty[], float billTotal[], float Total) {
    printf("---------------------------------\n");
    printf("           Receipt                 ");
    printf("\n---------------------------------\n");

    printf("%-12s %-6s %-8s %-8s\n","Item", "qty", "Price", "Total");

    for(int i=0; i<8; i++) {       //Checks all the user bought products & makes a bill from what they bought.
        if (billqty[i] > 0){
            printf("%-12s %-6d $%-7.2f $%-7.2f\n", menu[i], billqty[i], prices[i], billTotal[i]);
        }
    }

    printf("\n---------------------------------\n");
    printf("     Total Price: $%.2f", Total        );
    printf("\n---------------------------------\n");

    printf("\nCopyright (c) 2025 GWU/HICT/2023/08 \nAll Rights Reserved.\n");

}


int main()
{
                     //initialising an array of char strings to store menu data.
    char menu[8][25]=
    {"Coffee",
     "Espresso",
     "Americano",
     "Cappuccino",
     "Brownie",
     "Muffin",
     "Pastry",
     "Milkshakes" };

                //storing prices of all the offerings.
     float prices[8]= {1.99, 2.99, 2, 4.99, 4, 6, 3.99, 4};
     int choice, qty;
     float Total=0.0, ItemTot=0.0;
     char Yes;


          //arrays to store bill details.
     int billqty[8]={0};
     float billTotal[8]={0};


     printMenu(menu,prices); //Calling the menu function


       //Using infinite while loop to give the customer infinite amount opportunities to buy what they want.

    while(1){
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        if(choice<1 || choice>8) {        //checks for valid choice
            printf("Invalid Choice!\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &qty);

         if (qty<=0) {
           printf("Invalid quantity!\n");   //checks for valid quantity
           continue;
        }

        ItemTot= prices[choice-1]*qty;  //computing total price.
        Total+=ItemTot;

        billqty[choice-1]+=qty;  //stores the total quantity of each item.
        billTotal[choice-1] += ItemTot;  //stores the total cost of each item.

        while(1){           //Ask to add more items.
                printf("Add more items? (Y/N): ");
                scanf(" %c", &Yes);
                if (Yes == 'y' || Yes == 'Y'){
                        break;
                }
                else if (Yes == 'n' || Yes == 'N'){
                        goto BILL;  //if the above condition is true the program jumps to the part where label BILL is.
                }
                else {
                        printf("Invalid choice!\n");
                }
  } }

BILL:

    Receipt(menu,prices,billqty,billTotal,Total);


    return 0;
  }

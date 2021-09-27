//Kate Anderson
//U21933376
//This program takes in input from a user regarding how long they were parked in 
//a parking garage and outputs their balance due based on a number of pricing rules.
//The first 30 mins is free, each additional 20 minutes is $1, and the daily max is $12


#include <stdio.h>
#include <math.h>

int main(){
    int hours;
    int minutes;
    double amountDue = 0;
    double newHours;
    double totalTime;
    int numDays;
    double remain;
    int invalid = 0;

    printf("Enter hours parked: ");
    scanf("%d", &hours);

    printf("Enter minutes parked: ");
    scanf("%d", &minutes);

    if (hours < 0 || minutes > 60){
        printf("Invalid input. Hours should be positive and minutes should be in range 0 to 60");
        invalid = 1;
    }

    newHours = hours * 60;
    totalTime = newHours + minutes - 30;

    amountDue = ceil((totalTime) / 20) * 1;

    if (totalTime < 1440 && amountDue > 12){
        amountDue = 12;
    }

    else if (totalTime >= 1440){
        numDays = (totalTime / 1440);
        totalTime = totalTime - (1440 * numDays);
        remain  = ceil(totalTime / 20);


        if (remain > 12){
            remain = 12;
        }

        amountDue = (numDays * 12) + remain;
    
    }

    
    if (invalid == 0){
        printf("Amount due ($): $%.0f", amountDue);
    }
    



    
}
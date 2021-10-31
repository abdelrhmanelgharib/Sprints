#include <stdio.h>
#include <stdlib.h>

// Software Engineer Name: Abdelrhman El-Gharib

// All inputs are unsigned character

/*
- Define your global variables if needed here:
actual_result
expected_result
- Please concider the memoery optimization.
*/

/*
- Define your functional prototypes used here:
sum
unittest
- Please concider optimum Misra C when writing your functions.
*/
int sum(unsigned char , unsigned char );
void unittest(int , int );

int main()
{
    // Please declare your initializations here.
    unsigned int  Numb1 = 0;
    unsigned int Numb2 = 0;
    int ExpectedResult = 0;
    int ActualResult = 0;

    // Please define your infinite loop here.
    while (1)
    {
        // Please insert your screen visualization here.

        // Please write an expression that takes 2 numbers from the user here (concider screen readability).
        printf("\nEnter First Number:");
        scanf("%d", &Numb1);

        printf("Enter Second Number:");
        scanf("%d", &Numb2);


        printf("Enter The Expected Result:");
        scanf("%d", &ExpectedResult);
        
        
        // Please write an expression that calls the two function, the activation logic function and the unit test function in sequence.
        ActualResult = sum(Numb1, Numb2);
        unittest(ActualResult, ExpectedResult);
    
    }
    return 0;
}

// Please write the functional description of the sum function here:
int sum(unsigned char Numb1, unsigned char Numb2)
{
    int Result = 0;

    Result = (unsigned int)Numb1 + (unsigned int)Numb2;
    return Result;
}

// Pleas write the functional description of the unittest function here:
void unittest(int ActualResult, int ExpectedResult)
{
    if (ActualResult == ExpectedResult)
    {
        printf("Test Case Passed\n");
    }
    else
    {
        printf("Test Case Failed\n");
    }
}
/*
Filename: Chapter5Exercise11Population.cpp 
Programmer: Morgan Thorne
Date: April 2025
Requirements:
-Write a program that will predict the size of a population of organisms.
-The program should ask the user for the starting number of organisms, their average daily population increase (as a percentage),
and the number of days they will multiply. A loop should display the size of the population for each day.
-Input Validation: Do not accept a number less than 2 for the starting size of the population.
-Do not accept a negative number for average daily population increase.
-Do not accept a number less than 1 for the number of days they will multiply.
*/

#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
int Get_User_Input_Population_Increase_Day(float & User_Population, float & Daily_Population_Increase, int & Days);
void Display_Population_Increase(float User_Population, float Daily_Population_Increase, int Days);
bool GetRepeatInfo();


int main()
{
    float User_Population = 0;
    float Daily_Population_Increase = 0;
    float Population_Over_Time = 0;
    
    int Days = 0;
    
    bool User_Repeat;

    //Will run once, User will have to enter Y or N to either repeat the loop or end it.
    do {

        Get_User_Input_Population_Increase_Day(User_Population, Daily_Population_Increase, Days);

        Display_Population_Increase(User_Population, Daily_Population_Increase, Days);

        User_Repeat = GetRepeatInfo();
    } 
    while (User_Repeat); {
        cout << "Thank you for using Population Calculator V1!";
        return 0;
    }
}



//Function asks user for Population, Increase Percentage, and the amount of days it will grow, returns users answers to main
int Get_User_Input_Population_Increase_Day(float & User_Population, float & Daily_Population_Increase, int & Days) {
   
    
    //User enters population
    cout << "What is the population of the city: ";
    cin >> User_Population;

    while (User_Population < 2) { //Answer Validation, Input be less than 2
        cout << "Error, Please enter a number greater than 2";
        cin >> User_Population;
    }

    //User enters daily population increase  
    cout << "Enter daily population increase (%): "; 
    cin >> Daily_Population_Increase;

    while (Daily_Population_Increase <= 0) { //Answer Validation, Input cannot equal 0 or lower
        cout << "Error, Please enter a positive integer: ";
        cin >> Daily_Population_Increase;
    }

    

    //User enters the amount of days this population will grow
    cout << "Enter in the amount of days the population will increase over: ";
    cin >> Days;

    while (Days < 1) { //Answer Validation, Input cannot be lower than 1
        cout << "Please enter a number greater than 1:";
        cin >> Days;
    }
    
    
    return (User_Population, Daily_Population_Increase, Days);
  
}

//Calculates the Population increase over time and creates a loop to display population increase by each day
void Display_Population_Increase(float User_Population, float Daily_Population_Increase, int Days){
    cout << fixed << setprecision(2);
    cout << "\nDay\tPopulation\n";
    cout << "---------------------\n";
    



    double Starting_Population = User_Population;
    for (int Number_of_Days = 1; Number_of_Days <= Days; ++Number_of_Days) {
        cout << Number_of_Days << "\t" << setw(10) << right << Starting_Population << endl;
        Starting_Population += Starting_Population * (Daily_Population_Increase / 100.0);
    }


}

//Allows user to choose whether they want to repeat program or end it
bool GetRepeatInfo() {
    char choice;
    cout << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
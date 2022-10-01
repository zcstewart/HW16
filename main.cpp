//HW 16

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to document the 
 *                      number of miles run by five different people for 
 *                      seven days of the week. The program will take
 *                      the data and store it into appropriately sized arrays.
 *                      A 1-D Array will be used to store the names, a 2-D
 *                      A 2-D ARray with five rows and seven columns will
 *                      be created to store the miles run by each runner
 *                      on each day. Another 1-D Array will be created to store
 *                      the average number of miles run each day.
                        
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               2-1-2017 12:47 PST
 */

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>


//Namespace
using namespace std;

//Global const variables for array size
const int numRunners = 5;
const int numDays = 7;

//--------------------------------------------------------------------------//

//Function Prototypes

// Reads the data from the file into the appropriate arrays. 
void readData(ifstream &inFile, string runners[numRunners], 
        double data[numRunners][numDays]); 
// Calculates the total miles and average miles run 
void calculateData(double data[numRunners][numDays], 
                   double totalMiles[numRunners], 
                   double averageMiles[numDays]); 
// Prints the data to the screen 
void printData(string runners[numRunners], double data[numRunners][numDays], 
               double totalMiles[numRunners], double averageMiles[numDays]); 

//-------------------------------------------------------------------------//

//Main function

int main(int argc, char** argv)
{
    //Declare variables for use in program
    double data[numRunners][numDays] = {0};
    string runners[numRunners] = {""};
    double totalMiles[numRunners] = {0};
    double averageMiles[numDays] = {0};
    
    
    char fileName[51];   
    
    //Prompt user to enter name of data file
    cout << "Enter the name of the data file log: " << endl;
    cin >> fileName;
    
    //Declare filestream variable
    ifstream inData;
    ofstream outData;
    
    //Open data file. Use c_str function to convert to a c-string to allow
    //the file to be opened
    inData.open(fileName);
    outData.open("LogRunner");
    
    //Terminate program if file not opened.
    if(!inData)
    {
        cout << "Data file not found. Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    
    readData(inData, runners, data);
    
    calculateData(data, totalMiles, averageMiles);
    
    printData(runners, data, totalMiles, averageMiles);
    
    inData.close();
    outData.close();
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

//Function Definitions

//--------------------------------------------------------------------------//

void readData(ifstream &inFile, string runners[numRunners], 
              double data[numRunners][numDays])
{
    
    for(int row = 0; row < numRunners; row++)
    {
        inFile >> runners[row];
        for(int col = 0; col < numDays; col++)
        {
            inFile >> data[row][col];
        }
    }
}

void calculateData(double data[numRunners][numDays], 
                   double totalMiles[numRunners], 
                   double averageMiles[numDays])
{
    double sumMiles = 0;
    double average = 0;
    
    //For loop to calculate total Miles for each runner and store in array
    for(int row = 0; row < numRunners; row++)
    {
        for(int col = 0; col < numDays; col++)
        {
            totalMiles[row] += data[row][col];
        }
    }
    
    //For loop to sum the total miles run by each runner and divide that
    //number by the total number of runners to get the average.
    for(int col = 0; col < numDays; col++)
    {
        sumMiles = 0;
        for(int row = 0; row < numRunners; row++)
        {
            sumMiles += data[row][col];
        }
        average = sumMiles / numRunners;
        averageMiles[col] = average;
    }
}

void printData(string runners[numRunners], double data[numRunners][numDays], 
               double totalMiles[numRunners], double averageMiles[numDays])
{
    string s1 = "Name";
    string s2 = "Day 1";
    string s3 = "Day 2";
    string s4 = "Day 3";
    string s5 = "Day 4";
    string s6 = "Day 5";
    string s7 = "Day 6";
    string s8 = "Day 7";
    string s9 = "Total";
    string s10 = "Ave Miles";
    
    cout << left;
    cout << setw(10) << s1;
    cout << setw(6) << s2;
    cout << setw(6) << s3;
    cout << setw(6) << s4;
    cout << setw(6) << s5;
    cout << setw(6) << s6;
    cout << setw(6) << s7;
    cout << setw(6) << s8;
    cout << setw(6) << s9 << endl;
    cout.unsetf(ios::left);
    
    for(int row = 0; row < numRunners; row++)
    {
        cout << left << setw(10) << runners[row];
        for(int col = 0; col < numDays; col++)
        {
            cout << setw(6) << fixed << showpoint << setprecision(1);
            cout << data[row][col];
        }
        cout.unsetf(ios::left);
        cout << setw(5) << totalMiles[row];
        cout << endl;
    }
    cout << endl;
    cout << left << setw(6) << s10;
    cout.unsetf(ios::left);
    for(int col = 0; col < numDays; col++)
    {
        cout << setw(7) << fixed << showpoint << setprecision(1);
        cout << averageMiles[col];
    }
}
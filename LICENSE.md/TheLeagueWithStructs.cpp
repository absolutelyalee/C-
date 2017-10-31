/* Name: Alessandra Tsai
   CS 110B: Programming Assignment 8- The League with Structs
   Date: 10/28/2017
*/
#include<iostream>
#include<cstring>
using namespace std;

// read in a line of text and return it in a dynamically allocated array
char* getLine()
{
    const int BUFFER_SIZE = 1000;

    // Allocate a buffer local to this function
    char buffer[BUFFER_SIZE];

    // Use cin.getline() to input the buffer from the user
    cin.getline(buffer, BUFFER_SIZE);

    // Find the length of the string in buffer
    int length = strlen(buffer);

    // Dynamically allocate an array, to be returned
    char *rValue = new char[length + 1];

    // Copy the string into the dynamically allocated array
    strncpy(rValue, buffer, length);

    // Return the address of the dynamically allocated array
    return rValue;
}

struct WinRecord{
    int wins;
    char* name;
};

void initializeData(WinRecord* standings, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << "Enter name for team #" << count + 1 << endl;
        cin.ignore();
        standings[count].name = getLine();
        cout << "Enter wins for team #" << count + 1 << endl;
        cin >> standings[count].wins;
    }
}

void sortData(WinRecord* standings, int size)
{
    int startIndex, maxIndex, maxValue;

    for (startIndex = 0; startIndex < size-1; startIndex++)
    {
        maxIndex = startIndex;
        maxValue = standings[startIndex].wins;

        for (int index = startIndex + 1; index < size; index++)
        {
            if (standings[index].wins > maxValue)
            {
                maxValue = standings[index].wins;
                maxIndex = index;
            }

        }
        standings[maxIndex].wins = standings[startIndex].wins;
        standings[startIndex].wins = maxValue;
    }
}

void displayData(WinRecord* standings, int size)
{
    cout << "League Standings:" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << standings[count].name << ":" << standings[count].wins << endl;
    }
}

int main()
{
    int numTeams;
    cout << "Enter the number of teams: " << endl;
    cin >> numTeams;


    WinRecord *RecPtr = new WinRecord[numTeams];

    initializeData(RecPtr,numTeams);

    sortData(RecPtr,numTeams);

    displayData(RecPtr, numTeams);

    for (int count = 0; count < numTeams; count++)
    {
        delete[] RecPtr[count].name;
        RecPtr = NULL;
    }

    return 0;

}

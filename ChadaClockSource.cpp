/* Author: Amanda Dubois
*  Course: CS-210-T2589
   3-1 Project One: Chada Tech Clock
   Date: 11.08.2021
*/

#include<iostream>
using namespace std;
#include <string>
#include <ctime>
#include <time.h>
#include <conio.h>
#pragma warning(disable: 4996)

// Adjust specified hour, minute, or second by one
int makeChange(int valueToEdit) {
    valueToEdit = valueToEdit + 1;
    return valueToEdit;
}

int decreaseTwelve(int hour) {
    hour = hour - 12;
    return hour;

}

int main() {
    //display 12 hour and 24 hour clock next to each other
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int twelveHour;
    int twentyFourHour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;
    std::string amOrPm;

    int userInput = 0;

    if (ltm->tm_hour > 12) {
        twelveHour = decreaseTwelve(ltm->tm_hour);
        amOrPm = "PM";

    }
    else {
        twelveHour = ltm->tm_hour;
        amOrPm = "AM";
    }

    // Wait one second for input, adjust clock if 1 second is reached
    // Start the clock
    clock_t start = clock();
    // Repeat until user quits
    while (userInput != 4) {
        while (!_kbhit()) {
            // Run a one second timer
            if (((clock() - start) / CLOCKS_PER_SEC) >= 1)
            {
                //ADJUST TIME BY ONE SECOND
                second = makeChange(second);
                if (second > 59) {
                    minute++;
                    second = second - 60;
                }

                //Display clocks
                //12 hour

                cout << "**************************" << "       " << endl;
                cout << "*      12-Hour Clock     *" << "       " << endl;
                cout << "*     " << twelveHour << ":" << minute << ":"
                    << second << " " << amOrPm << "         *" << "     " << endl;
                cout << "**************************" << "     " << endl;

                // 24 hour
                cout << "**************************" << endl;
                cout << "*      24-Hour Clock     *" << endl;
                cout << "*     " << twentyFourHour << ":" << minute << ":"
                    << second << " " << amOrPm << "        *" << "     " << endl;
                cout << "**************************" << endl;

                cout << endl;
                cout << endl;

                {
                    //prompt user to: add hour, minute, second, or exit
                    cout << "**************************" << endl;
                    cout << "* 1 - Add One Hour       *" << endl;
                    cout << "* 2 - Add One Minute     *" << endl;
                    cout << "* 3 - Add One Second     *" << endl;
                    cout << "* 4 - Exit Program       *" << endl;
                    cout << "**************************" << endl;

                    // Start again
                    start = clock();
                }
            }
            cin >> userInput;
            if (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4)
            {
                cout << "Please select from the menu." << endl;
            }
            switch (userInput) {
            case 1:
                twelveHour = makeChange(twelveHour);
                twentyFourHour = makeChange(twentyFourHour);
                break;
            case 2:
                minute = makeChange(minute);
                if (minute > 59) {
                    twelveHour++;
                    twentyFourHour++;
                    minute = minute - 60;
                }
                break;
            case 3:
                second = makeChange(second);
                if (second > 59) {
                    minute++;
                    second = second - 60;
                }
                break;
            case 4:
                cout << "Exiting Program" << endl;
                exit(1);
                break;
            default:
                cout << "Error! Invalid choice!\n";
                break;
            }

            // Check to see if the clocks are beyond 12:59 or 23:59 respectively.
                // If the time is beyond its limit, subtract by the limit to get the new time
            if (twelveHour > 12) {
                twelveHour = decreaseTwelve(twelveHour);
                // Adjust the AM/PM value as it changes whenever the time passes 12.
                if (amOrPm == "AM") {
                    amOrPm = "PM";
                }
                else {
                    amOrPm = "AM";
                }
            }
            if (twentyFourHour > 23) {
                twentyFourHour = twentyFourHour - 23;
            }
        }
    }
}

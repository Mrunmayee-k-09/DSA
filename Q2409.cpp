#include<iostream>
using namespace std;
class Solution {
public:
    int convertToDays(string date) {
        int daysInMonth[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        //First number → Where to start.
        //Second number → How many characters to take.

        int totalDays = day;

        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }

        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int aStart = convertToDays(arriveAlice);
        int aEnd = convertToDays(leaveAlice);
        int bStart = convertToDays(arriveBob);
        int bEnd = convertToDays(leaveBob);

        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
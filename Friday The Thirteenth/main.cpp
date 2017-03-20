#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int dayOfWeek(int d, int m, int y);
void dateVerifier(string x);
void monthYearStabilizer();
void fridayTheThirteenth();
string monthAssigner(int month);
void finalOutput();

static int iniDay, iniMonth, iniYear, finDay, finMonth, finYear;
vector<string> finalMonth;
vector<int> finalYear;
int dateSetter[3]; //Used to return date from dateVerifier() function.

int main() {
    string initialDate, finalDate;
    cout << "Enter initial date (DD-MM-YYYY): ";
    cin >> initialDate;
    dateVerifier(initialDate);
    iniDay = dateSetter[0];
    iniMonth = dateSetter[1];
    iniYear = dateSetter[2];

    cout << "Enter final date (DD-MM-YYYY): ";
    cin >> finalDate;
    dateVerifier(finalDate);
    finDay = dateSetter[0];
    finMonth = dateSetter[1];
    finYear = dateSetter[2];

    fridayTheThirteenth();
    finalOutput();

    return 0;
};

int dayOfWeek(int d, int m, int y) { //Used to determine day of the week on given date.
    static int offset[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= (m < 3);
    int day = (y + y/4 - y/100 + y/400 + offset[m-1] + d)%7;

    return day;

};

void dateVerifier(string x) { //Used to verify the format of entered date, and obtain independent values of day, month and year.
    int length = 0;
    bool pass, pass2; //Pass is used to see if date format is correct. Pass2 is used to chck if date is logistically correct.
    bool leap;

    pass = true;
    pass2 = true;
    leap = false;
    length = x.length();

     {//Checks format of date entered.
        for (int a=0; a<length; a++) {//Used to check if numbers and hyphens are in the rightplaces.
            if (a == 2 || a == 5) {
                if (x.substr(a, 1) != "-") {//Checks for hyphens.
                    pass = false;
                    break;

                };
            }

            else {//Else check ASCII values for numerical digits.
                if (+x[a] < 48 || +x[a] > 57) {
                    pass = false;
                    break;
                };
            };
        };
    }

    if (length != 10 || pass == false) {//Shows error to the user.
        cout << "Error. Type date in correct format." << endl;
        main();
    }

    else {//After verification, sets values of variables.
        dateSetter[0] = atoi((x.substr(0, 2)).c_str()); //dateSetter[0] stores value of 'Day' entered.
        dateSetter[1] = atoi((x.substr(3, 5)).c_str()); //dateSetter[1] stores value of 'Month' entered.
        dateSetter[2] = atoi((x.substr(6, 10)).c_str()); //dateSetter[2] stores value of 'Year' entered.
    };

    if ((dateSetter[2]%4==0) && (dateSetter[2]%100!=0 || dateSetter[2]%400==0)) {
        leap = true;
    };

    { //Checks logistic validity of date entered.
        if (dateSetter[1]>12) {
            pass2 = false;
        }

        else if ((dateSetter[1]==1 || dateSetter[1]==3 || dateSetter[1]==5 || dateSetter[1]==7 || dateSetter[1]==8 || dateSetter[1]==10 || dateSetter[1]==12) && (dateSetter[0]>31)) {
            pass2 = false;
        }

        else if ((dateSetter[1]==4 || dateSetter[1]==6 || dateSetter[1]==9 || dateSetter[1]==11) && (dateSetter[0]>30)) {
            pass2 = false;
        }

        else if (dateSetter[1]==2) {
            if (leap==true && dateSetter[1]>29) {
                pass2 = false;
            }
            else if (leap==false && dateSetter[1]>28) {
                pass2 = false;
            }
        }
    }

    if (pass2==false) {
        cout << "Enter valid date.";
        main();
    };
}

void fridayTheThirteenth() {
    iniMonth += (iniDay>13); //Nullifies extra month where the 13th has already passed.
    finMonth -= (finDay<13); //Does the same thing fo the final date, where the 13th is yet to come.

    monthYearStabilizer(); //Corrects overshooting which might happen in the increment done before.

    int tempMonth, tempYear;

    tempMonth = iniMonth;
    tempYear = iniYear;

    int a=0;

    do { //Stores values of all months and respective years, which satisfy 'Friday The Thirteenth'.
        if (dayOfWeek(13, tempMonth, tempYear) == 5) {
            finalMonth.push_back(monthAssigner(tempMonth));
            finalYear.push_back(tempYear);
            a++;
        }
        tempMonth++;

        if (tempMonth>12) {
            tempYear++;
            tempMonth-=12;
        }
    } while ((tempMonth<finMonth) || (tempYear<finYear));
}

void monthYearStabilizer() {
    if (iniMonth>12) {
        iniMonth -= 12;
        iniYear++;
    }

    if (finMonth<1) {
        finMonth += 12;
        finYear--;
    }
 }

 void finalOutput() { // Prints final Output.
    if (finalMonth.size()==1) {cout << "There is " << finalMonth.size() << " Friday the Thirteenth:" << endl;}
    else {cout << "There are " << finalMonth.size() << " Friday the Thirteenth's:" << endl;}

    for(int a=0; a<=(finalMonth.size()-1); a++){
        cout << "13 " << finalMonth[a] << ", " << finalYear[a] << endl;
    };
 }


string monthAssigner(int month) {
if (month==1) {return "Jan";};
if (month==2) {return "Feb";};
if (month==3) {return "Mar";};
if (month==4) {return "Apr";};
if (month==5) {return "May";};
if (month==6) {return "Jun";};
if (month==7) {return "July";};
if (month==8) {return "Aug";};
if (month==9) {return "Sept";};
if (month==10) {return "Oct";};
if (month==11) {return "Nov";};
if (month==12) {return "Dec";};
}

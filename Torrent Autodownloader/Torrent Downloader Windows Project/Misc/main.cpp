#include <iostream>
#include <windows.h>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

string curl();

int main()
{
/*    string cas = "C:\\Users\\Gupta\\Desktop";
//    char[100] = cas +
    ifstream x((cas + "\\torrentLocation.txt").c_str());
    string y;
    x >> y;
    cout << y;
*/
    char r[230];
    FILE *blah = popen("echo %PROGRAMFILES(x86)%", "r");
    fgets(r, sizeof(r), blah);
    for (int i=0; i<50; i++) {
        if (r[i] ==  '\n') {
                r[i] = '\0';
        };
    };
}

string curl() {
    return " \"%PROGRAMFILES(x86)%\\Torrent Autodownloader\\curl\" ";
};

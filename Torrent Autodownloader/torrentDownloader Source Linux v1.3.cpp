#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

/* v1.2 Added History feature to prevent redundant donwloads */
/* v1.3 Added Notifiication support */

using namespace std;

void showFound(istream &katcr);
bool verify720(string tempLine);

ofstream log("/home/ekansh/Log/torrentDownloaderLog.txt", std::ios::app);

int main(){

    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );

    int Day    = localTime->tm_mday;
    int Month  = localTime->tm_mon + 1;
    int Year   = localTime->tm_year + 1900;
    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;

    log << "-----RUN AT " << Day << "/" << Month << "/" << Year << " " << Hour << ":" << Min << ":" << Sec << "-----" << endl << endl;

    system("curl --compressed https://kickass.cd/tv/ > /media/ekansh/Stuff/Torrents/Torrent\\ Downloader/katcr.txt");

    ifstream theList("/media/ekansh/Stuff/Torrents/Torrent Downloader/The List.txt");
    string nameOfShow;

    while (getline(theList, nameOfShow)) {
        string tempLine;
        ifstream katcr("/media/ekansh/Stuff/Torrents/Torrent Downloader/katcr.txt");

        int count1 = 0;

        while (getline(katcr, tempLine)) {
            count1++;
            int posNameOfShow = tempLine.find(nameOfShow);
            if (posNameOfShow != -1) {
            	bool not720p = verify720(tempLine);

            	if (not720p) {
	                cout << nameOfShow << "----" << "LINE NUMBER-----" << count1 << endl;
	                showFound(katcr);
	                break;
	            }

	            else {
	            	continue;
	            };
            };
        };

        katcr.close();
    };

    log << endl << endl;
    log.close();
    theList.close();
};

void showFound(istream &katcr) {
	ifstream historyIn("/media/ekansh/Stuff/Torrents/Torrent Downloader/history.txt");
    string tempLine;
    getline(katcr, tempLine);
    getline(katcr, tempLine);

    int posOfSite1 = tempLine.find("href=\"");
    int posOfSite2 = tempLine.find(".torrent?", posOfSite1+6);
    int posOfName = tempLine.find("[kat.cr]");
    int posOfName2 = tempLine.find("\"", posOfName+ 10);
    string nameOfTorrent = tempLine.substr(posOfName+8, posOfName2-posOfName-8);

    log << "Name Of Torrent: " << nameOfTorrent << endl;

	string addOfSubpage = "https:" + tempLine.substr(posOfSite1+6, posOfSite2-posOfSite1+2);

    log << "Address of torrent page: " << addOfSubpage << endl;

    string command = "curl --compressed -o /media/ekansh/Stuff/Torrents/Torrent\\ Downloader/Torrent\\ Files/" + nameOfTorrent + ".torrent -A \"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.109 Safari/537.36\" \""
     + addOfSubpage + "\"";

    char commandChar[1000];
    strncpy (commandChar, command.c_str(), 1000);

    bool downloadedBefore = false;
    string tempHistoryIn;

	while (getline(historyIn, tempHistoryIn)) {
		if (tempHistoryIn == nameOfTorrent) {downloadedBefore = true;};
	};

	historyIn.close();


	if (!(downloadedBefore)) {
		log << "Status: DOWNLOADING" << endl;
		log << "Command run: " << command << endl << endl;
		ofstream historyOut("/media/ekansh/Stuff/Torrents/Torrent Downloader/history.txt", std::ios::app);
		historyOut << nameOfTorrent << endl;
		historyOut.close();

        string notifCommand = "notify-send \"Torrent Autodownloader: Started the download of " + nameOfTorrent + "\"";
        cout << endl << notifCommand << endl << endl;
        char notifCommandChar[1000];
        strncpy (notifCommandChar, notifCommand.c_str(), 1000);

	    system(commandChar);
        system(notifCommandChar);
	}

	else {
		log << "Status: ABORTED - DOWNLOADED BEFORE" << endl;
		log << "Command NOT run: " << command << endl << endl;
	};
};

bool verify720(string tempLine) {
	int x = tempLine.find("720p");

	return (x == -1)? true:false;
}
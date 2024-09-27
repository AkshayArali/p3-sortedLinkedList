
#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;

string title;
string url;
string comment;
float length;
int rating;

// Purpose: To read the command and perform the required method.
//  Input Parameters: Video list
//  Output Parameters: Print, length, lookup, remove.
//  Return Value: Boolean
void read_input(Vlist &vlist)
{
    string command;
    while (getline(cin, command))
    {
        if (command == "insert") // Check if the command is insert, if it is go to insert funciton.
        {
            getline(cin, title);
            getline(cin, url);
            getline(cin, comment);
            cin >> length;
            cin >> rating;
            Video *newVideo = new Video(title, url, comment, length, rating);

            vlist.insert(newVideo);
            cin.ignore();
        }

        else if (command == "print") // Check if the command is print, if it is go to print funciton.
        {
            if (vlist.length() != 0)
            {
                vlist.print();
            }
        }
        else if (command == "length") // Check if the command is length, if it is go to length funciton.
        {
            cout << vlist.length() << endl;
        }
        else if (command == "lookup") // Check if the command is lookup, if it is go to lookup funciton.
        {
            string userTitle;
            getline(cin, userTitle);
            vlist.lookup(userTitle);
        }

        else if (command == "remove") // Check if the command is remove, if it is go to remove funciton.

        {
            string newtitle;
            getline(cin, newtitle);
            vlist.remove(newtitle);
        }
        else
        {
            throw "<" + command + "> is not a legal command, giving up."; // Throw an error
        }
    }
}

int main()
{
    Vlist *vlist = new Vlist(); // Creating new list of video objects.
    try
    {
        read_input(*vlist);
    }
    catch (string error)
    {
        cerr << error << endl; // Try to catch the error and print throw the error.
        return 1;
    }

    return 0;
}
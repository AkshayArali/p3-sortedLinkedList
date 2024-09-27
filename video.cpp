
#include <iostream>
#include <string>
using namespace std;

#include "video.h"

// Creating Video class which will be predicate/prototype for objects
Video::Video(string title, string url, string comment, float length, int rating)
{
    m_title = title;
    m_url = url;
    m_comment = comment;
    m_length = length;
    m_rating = rating;
}

// Purpose: To get the Title.
//  Input Parameters: nothing
//  Output Parameters: Nothing
//  Return Value: String
string Video::getTitle()
{
    return this->m_title;
}

// Purpose: To print the video object.
//  Input Parameters: nothing
//  Output Parameters: Nothing
//  Return Value: nothing
void Video::print()
{
    string stars = "";
    for (int i = 0; i < m_rating; i++)
    {
        stars = stars + "*";
    }
    cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", " << stars << endl;
}

// Purpose: To send a boolean if the comapare is based on rating.
//  Input Parameters: otherVideo
//  Output Parameters: Nothing
//  Return Value: Boolean
bool Video::compareRatings(Video *otherVideo)
{
    return otherVideo->m_rating > this->m_rating;
}

// Purpose: To send a boolean if the length is based on rating.
//  Input Parameters: otherVideo
//  Output Parameters: Nothing
//  Return Value: Boolean
bool Video::compareLengths(Video *otherVideo)
{
    return otherVideo->m_length < this->m_length;
}

// Purpose: To send a boolean if the length is based on rating.
//  Input Parameters: otherVideo
//  Output Parameters: Nothing
//  Return Value: Boolean
bool Video::compareTitles(Video *otherVideo)
{
    return otherVideo->m_title < this->m_title;
}

// Purpose: To send a boolean based on the type of comparision is based on rating.
//  Input Parameters: otherVideo and sort
//  Output Parameters: Nothing
//  Return Value: Boolean
bool Video::compare(Video *otherVideo, string sort)
{
    if (sort == "rating")
        return compareRatings(otherVideo);

    else if (sort == "length")
        return compareLengths(otherVideo);

    return compareTitles(otherVideo);
}
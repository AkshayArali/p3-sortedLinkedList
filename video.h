
#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;
class Video
{
public:
    Video(string title, string url, string comment, float length, int rating);
    void print();
    bool compareRatings(Video *otherVideo);
    bool compareLengths(Video *otherVideo);
    bool compareTitles(Video *otherVideo);
    bool compare(Video *otherVideo, string sort);
    string getTitle();

private:
    string m_title;
    string m_url;
    string m_comment;
    float m_length;
    int m_rating;
};

// bool compareRatings(Video *otherVideo);
// bool compareLengths(Video *otherVideo);
// bool compareTitles(Video *otherVideo);
// bool compare(Video *otherVideo, string sort);

#endif
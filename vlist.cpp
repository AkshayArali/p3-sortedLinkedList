
#include <iostream>
#include "vlist.h"
#include <string>
using namespace std;

// Purpose: To insert the video object with all the attributes such as title, comment, length etc.
//  Input Parameters: video Object
//  Output Parameters: Nothing
//  Return Value: Void
void Vlist::insert(Video *video)
{

  // Throw another error, duplication.
  //  if list is empty, insert newNode as head
  bool checkExisiting = false;
  Node *current = m_head;
  while (current != nullptr)
  {
    // check for title being present in the vlist
    if (video->getTitle() == current->m_video->getTitle())
    {
      checkExisiting = true;
      break;
    }
    current = current->m_next;
  }
  if (checkExisiting)
  {
    cerr << "Could not insert video <" << video->getTitle() << ">, already in list." << endl;
    return;
  }
  if (m_head == nullptr)
  {
    m_head = new Node(video, nullptr);
    return;
  }
  if (m_head->m_video->compareTitles(video))
  {
    Node *temp = m_head;
    m_head = new Node(video, temp);
    return;
  }

  if (m_head->m_next == nullptr)
  {
    m_head->m_next = new Node(video, nullptr);
    return;
  }

  Node *prev = m_head;
  current = prev->m_next;

  while (current != nullptr)
  {

    if (current->m_video->compareTitles(video))
    {
      prev->m_next = new Node(video, current);
      break;
    }
    if (current->m_next == nullptr)
    {
      current->m_next = new Node(video, nullptr);
      break;
    }
    prev = current;
    current = current->m_next;
  }
}

// Purpose: To remove the given(title) video object from the list of videos.
//  Input Parameters: title
//  Output Parameters: void
//  Return Value: Void
void Vlist::remove(string title)
{
  Node *current = m_head;
  Node *prev = nullptr;
  if (current == nullptr)
  {
    cerr << "Title <" << title << "> not in list, could not delete." << endl;
    return;
  }
  // traverse the list until we find the node containing video or reach the end
  while (current != nullptr && current->m_video->getTitle() != title)
  {
    prev = current;
    current = current->m_next;
  }
  // if we didn't find the video in the list, do nothing
  if (current == nullptr)
  {
    cerr << "Title <" << title << "> not in list, could not delete." << endl;
    return;
  }

  // if the node containing video is the head, update the head
  if (current == m_head)
  {
    m_head = current->m_next;
  }
  else
  {
    prev->m_next = current->m_next;
  }

  // delete the node containing video and free up memory
  // delete current;
}
// Purpose: To print all the video objects.
//  Input Parameters: Nothing
//  Output Parameters: Nothing
//  Return Value: Void
void Vlist::print()
{
  Node *current = this->m_head;
  while (current != nullptr)
  {
    current->m_video->print();
    current = current->m_next;
  }
}
// Purpose: To calculate the number of video objects in the list.
//  Input Parameters: Nothing
//  Output Parameters: Nothing
//  Return Value: Integer
int Vlist::length()
{
  int count = 0;
  Node *current = m_head;
  while (current != nullptr)
  {
    count = count + 1;
    current = current->m_next;
  }
  return count;
}
// Purpose: To check if the given title is present in the list, if it is: print the object, else: Throw an error.
//  Input Parameters: Title
//  Output Parameters: Video object
//  Return Value: Void
void Vlist::lookup(string title)
{
  Node *current = m_head;
  while (current != nullptr)
  {
    if (current->m_video->getTitle() == title)
    {
      current->m_video->print();
      return;
    }
    current = current->m_next;
  }
  cerr << "Title <" << title << "> not in list." << endl;
}

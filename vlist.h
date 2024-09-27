

#ifndef VLIST_H
#define VLIST_H

#include "video.h"
#include <string>
using namespace std;

class Vlist
{
public:
  Vlist() { m_head = nullptr; }

  void insert(Video *video);
  void remove(string title);
  void print();
  int length();
  void lookup(string title);

private:
  class Node
  {
  public:
    Node(Video *video, Node *next)
    {
      m_video = video;
      m_next = next;
    }
    Video *m_video;
    Node *m_next;
    ~Node()
    {
      delete this->m_video;
      delete this->m_next;
    };
  };
  Node *m_head;
  ~Vlist()
  {
    Node *current = m_head;
    while (current != nullptr)
    {
      Node *next = current->m_next;
      delete current;
      current = next;
    }
    delete current;
  };
};
#endif

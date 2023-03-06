#include "headerA3.h"
#include "extraHeaderA3.h"

void addNodeToList(tweet ** tweetList, tweet * node)
{
  tweet * traverse;

  /*
    INSERTION - insert new node at the end of current list
      1. Navigate to the last node
      2. Make last node point to new node
  */
  traverse = *tweetList;
  if (traverse == NULL)
  {
    *tweetList = node;
  }
  else
  {
    while (traverse->next != NULL)
    {
      traverse = traverse->next;
    }
    traverse->next = node;
  }
}

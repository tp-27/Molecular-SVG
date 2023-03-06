#include "headerA3.h"
#include "extraHeaderA3.h"

void insertNode(tweet ** tweetList, tweet * node, int position)
{
  tweet *curr, *prev;
  int numTweets;
  int i;
  /*
    INSERT at i-th - insert tweet by location defined by int position
      1. Navigate to node before position to insert
      2. Make last node point to new node
  */

  numTweets = countTweets(*tweetList);
  printf("Num tweets after deleting: %d\n", numTweets);
  printf("inserting tweet %d at position %d\n", node->id, position);


  // inserting at the end
  if (position == (numTweets + 1))  // the node is deleted before we insert so number of tweets change and position 5 will not exist
  {
    curr = *tweetList;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = node;
  }
  // inserting at the beginning or in the middle
  else
  {
    curr = *tweetList;
    prev = NULL;
    for (i = 1; curr != NULL && i != position; prev = curr, curr = curr->next, i++);

    if (prev == NULL)
    {
      node->next = curr;
      curr = node;
    }
    else
    {
      node->next = curr;
      prev->next = node;
    }

  }

}

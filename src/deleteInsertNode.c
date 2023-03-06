#include "headerA3.h"
#include "extraHeaderA3.h"

void deleteInsertNode(tweet ** tweetList, int position)
{
  int i;
  tweet *curr, *prev;

    /*
     delete n-th tweet
      1. Traverse list until curr reaches n-th tweet to delete with trailing ptr behind
      2. Have the trailing ptr bypass deleted tweet and point to curr->next
      3. free block of memory curr points to
    */
    curr = *tweetList;
    prev = NULL;
    for (i = 1; curr != NULL && i != position; prev = curr, curr = curr->next, i++);

    if (curr == NULL)
    {
      printf("There are no tweets to Delete.\n");
    }
    if (prev == NULL)
    {
      *tweetList = (*tweetList)->next;
    }
    else
    {
      prev->next = curr->next;  // deleting node in linked list - bypass deleted tweet
    }

    printf("Deleted!\n");
    free(curr);
  }

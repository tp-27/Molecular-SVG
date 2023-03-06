#include "headerA3.h"
#include "extraHeaderA3.h"

void freeTweets(tweet *tweetList)
{
  tweet *curr;

  if (tweetList != NULL)
  {
    while (tweetList != NULL)
    {
      curr = tweetList;
      tweetList = curr->next;
      free(curr);
    }
  }
}

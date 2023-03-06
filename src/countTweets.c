#include "headerA3.h"
#include "extraHeaderA3.h"

int countTweets (tweet *tweetList)
{
  tweet * traverse;
  int numTweets;

  traverse = tweetList;
  numTweets = 0;

  if (tweetList == NULL)
  {
    return numTweets;
  }
  else
  {
    // count number of tweets
    while (traverse != NULL)
    {
      numTweets++;
      traverse = traverse->next;
    }
  }

  return numTweets;
}

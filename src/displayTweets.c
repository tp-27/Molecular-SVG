#include "headerA3.h"
#include "extraHeaderA3.h"

void displayTweets (tweet * tweetList)
{

  if (tweetList == NULL)
  {
    printf("No tweets in list.\n");
  }
  else if (tweetList->next == NULL)
  {
      printf("%d: Created by %s: %s\n", tweetList->id, tweetList->user, tweetList->text);
  }
  else
  {
    while (tweetList != NULL)
    {
      printf("%d: Created by %s: %s\n", tweetList->id, tweetList->user, tweetList->text);
      tweetList = tweetList->next;
    }
  }
  printf("\n");
}

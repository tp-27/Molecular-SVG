#include "headerA3.h"
#include "extraHeaderA3.h"

void deleteTweet(tweet ** tweetList)
{
  char nthDelete[50];
  int numTweets, tweetID;
  int numDelete;
  int i;
  tweet *curr, *prev;

  numTweets = countTweets(*tweetList);

  if (numTweets == 0)
  {
    printf("No tweets in the list.\n\n");
  }
  else
  {
    printf("Currently there are %d tweets.\n", numTweets);
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", numTweets);
    getchar();
    fgets(nthDelete, 50, stdin);
    nthDelete[strlen(nthDelete) - 1] = '\0';
    numDelete = atoi(nthDelete);
    while ((numDelete < 1) || (numDelete > numTweets))
    {
      printf("Invalid entry.\n");
      printf("Please enter a value between 1 and %d ", numTweets);
      nthDelete[0] = '\0';
      fgets(nthDelete, 50, stdin);
      nthDelete[strlen(nthDelete) - 1] = '\0';
      numDelete = atoi(nthDelete);
    }

    /*
     delete n-th tweet
      1. Traverse list until curr reaches n-th tweet to delete with trailing ptr behind
      2. Have the trailing ptr bypass deleted tweet and point to curr->next
      3. free block of memory curr points to
    */
    curr = *tweetList;
    prev = NULL;
    for (i = 1; curr != NULL && i != numDelete; prev = curr, curr = curr->next, i++);

    if (curr == NULL)
    {
      printf("There are no tweets to Delete!.\n");
    }
    if (prev == NULL)
    {
      *tweetList = (*tweetList)->next;
    }
    else
    {
      prev->next = curr->next;  // deleting node in linked list - bypass deleted tweet
    }

    tweetID = curr->id;
    numTweets = countTweets(*tweetList);
    if (numTweets == 0)
    {
        printf("Tweet %d deleted. There are now %d tweets left.\n", tweetID, numTweets);
    }
    else if (numTweets == 1)
    {
        printf("Tweet %d deleted. There is now %d tweet left.\n", tweetID, numTweets);
    }
    else
    {
        printf("Tweet %d deleted. There are now %d tweets left.\n", tweetID, numTweets);
    }
    free(curr);
  }
}

#include "headerA3.h"
#include "extraHeaderA3.h"

tweet * createTweet (tweet * tweetList)
{
  tweet * newTweet;
  tweet * temp;
  char tempUser[500];
  char tempText[500];
  int generateID, uniqueID;  // uniqueID; 0 - doesn't exist , 1 - exists
  int i;
  int length;

  // Get username + check correct length
  printf("Enter Tweeter username: ");
  //getchar();                                   // newline stays in buffer from function before
  fgets(tempUser, 500 , stdin);
  tempUser[strlen(tempUser) - 1] = '\0';       // get rid of newline char from username input
  length = strlen(tempUser);

  while (length == 0)
  {
    printf("Username is too short. Please enter a new username: ");
    fgets(tempUser, 500, stdin);
    tempUser[strlen(tempUser) - 1] = '\0';
    length = strlen(tempUser);
  }
  while (length > 50)
  {
    printf("Username is too long. Please enter a new username: ");
    fgets(tempUser, 500, stdin);
    tempUser[strlen(tempUser) - 1] = '\0';
    length = strlen(tempUser);
  }

  // Get user text + check correct length
  printf("Enter tweet: ");
  fgets(tempText, 500, stdin);
  tempText[strlen(tempText) - 1] = '\0';       // get rid of newline char from username input
  length = strlen(tempText);

  while (length == 0)
  {
    printf("Tweet is too short. Please enter a new tweet: ");
    fgets(tempText, 1000, stdin);
    tempText[strlen(tempText) - 1] = '\0';
    length = strlen(tempText);
  }

  while (length > 50)
  {
    printf("Username is too long. Please enter a new username: ");
    fgets(tempText, 500, stdin);
    tempText[strlen(tempText) - 1] = '\0';
    length = strlen(tempText);
  }

  /*
    Create a new node and copy temporary strings into new node:
     1. Allocate memory for newTweet
     2. Copy user data into struct that newTweet points to
  */

  newTweet = malloc(sizeof(tweet));
  newTweet->next = NULL;
  strcpy(newTweet->user, tempUser);
  strcpy(newTweet->text, tempText);

  /*
    Generate a userId based on characters in username and length of tweet:
     1. Find sum of ascii of chars in username
     2. Find length of user's tweet and add onto generateId
  */

  generateID = 0;
  for (i = 0; i < strlen(newTweet->user); i++)
  {
    // sum N random numbers from 0-999 ; N = number of characters in username
    generateID += newTweet->user[i];
  }

  generateID += strlen(newTweet->text);

  /*
    Check linked list to see if userID exists
     1. User a temp pointer of type struct tweet to navigate through list
     2. Compare generateID to temp->id

    Notes:
    - if list is empty, then don't need to check just assign ID to new tweet
    else check list
  */

  temp = NULL;
  uniqueID = 0;             // assume ID is unique
  if (tweetList == NULL)    // if list is empty - ID is unique
  {
    newTweet->id = generateID;
  }
  else
  {
    temp = tweetList;
    while (temp != NULL)    // navigate through each node untill last node
    {
      // while traversing - compare ID's in list to newly created ID
      if (generateID == temp->id)
      {
        uniqueID = 1;       // there exists an ID equal to generated ID
        temp = NULL;        // exit out of searching through list
      }
      else
      {
        temp = temp->next;  // move onto next node in list and compare
      }
    }
  }

  if (uniqueID == 0)
  {
    // assign ID to user
    newTweet->id = generateID;
  }
  else
  {
    // generate NEW random ID from numbers between 1 - 999
    srand((int)time(0));   // unique seed for pseudorandom numbers
    generateID = 0;
    while (uniqueID == 1)
    {
      // generate a random number from 0 - 999
      generateID = (rand() % 998 + 1) + generateID;
      // check if number exists in the list if it does, then add another random number until unique
      temp = tweetList;
      uniqueID = 0;           // assume ID is unique
      while (temp != NULL)    // navigate through each node until last node
      {
        // while traversing - compare ID's in list to newly created ID
        if (generateID == temp->id)
        {
          uniqueID = 1;   // if not unique then add another random number onto ID
          temp = NULL;
        }
        else
        {
          temp = temp->next;  // move onto next node in list and compare
        }
        // if uniqueID is still equal to 0 when temp = NULL then unique ID
      }
    }
    newTweet->id = generateID;
  }

  return newTweet;
}

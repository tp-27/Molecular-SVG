#include "headerA3.h"
#include "extraHeaderA3.h"

void sortID(tweet ** head)
{
  int *userID;
  tweet *traverse;
  int sizeList;
  int i, j;
  int minVal, minPos;
  int valTemp;


  // sort linked list nodes on ascending order of userids - any sorting algorithm in class
  traverse = *head;
  userID = NULL;

  if (*head == NULL)
  {
    printf("No tweets to sort.\n");
  }
  else
  {
    sizeList = countTweets(*head);
    printf("Sizelist: %d\n", sizeList);

    // **** extract userID's into int array ****
    userID = malloc(sizeof(int) * sizeList);
    for (i = 0; i < sizeList; i++)
    {
      userID[i] = traverse->id;
      traverse = traverse->next;
    }


    printf("Before: ");
    for (i = 0; i < sizeList; i++)
    {
      printf("%d, ", userID[i]);
    }
    printf("\n");


    // **** sort userID's by ascending order ****
    for (i = 0; i < sizeList; i++)
    {
      minVal = userID[i];
      minPos = i;

      for (j = i + 1; j < sizeList; j++)
      {
        if (userID[j] < minVal)
        {
          minPos = j;
          minVal = userID[j];
        }
      }
      //printf("Min Val = %d, min pos = %d \n", minVal, minPos);
      valTemp = userID[i];
      userID[i] = userID[minPos];
      userID[minPos] = valTemp;
    }


    printf("After: ");
    for (i = 0; i < sizeList; i++)
    {
      printf("%d, ", userID[i]);
    }
    printf("\n");


    /*
    // **** rearrange linked list based upon sorted ID's ****
    temp = malloc(sizeof(tweet));
    int i = 0;
    int ID;
    traverse = *head;

    while (i >= 0)
    {
      ID = userID[i];
      traverse = *head;
      while (traverse->next != NULL)
      {
        if (ID == traverse->id)
        {
          // Make a copy of the tweet
          temp->id = traverse->id;
          strcpy(temp->user, traverse->user);
          strcpy(temp->text, traverse->text);
          temp->next = NULL;
          printf("Tweet #%d\n", temp->id);

          // delete node
          deleteInsertNode(head, i + 1);
          // insert tweet into correct position
          insertNode(head, temp, i + 1);
        }
        else
        {
          traverse = traverse->next;
        }
      }
      i++;
      if (i >= sizeList)
      {
        break;
      }
    }
  }
  */
  }
  free(userID);
}

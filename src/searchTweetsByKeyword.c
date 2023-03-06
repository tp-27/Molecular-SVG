#include "headerA3.h"
#include "extraHeaderA3.h"

int searchTweetsByKeyword(tweet * tweetList)  // FOUND = 1 , NOT FOUND = 0
{
  char *origKeyword;
  char keyword[142];
  char *tempText;
  int i,j;
  int numSubstrings, match, current;
  int totalSubstrings;
  int length;

  tempText = NULL;
  origKeyword = NULL;
  totalSubstrings = 0;
  length = 0;
  if (tweetList == NULL)
  {
    printf("No tweets in list.\n");
  }
  else
  {
    // prompt user for keyword
    printf("Enter a keyword to search: ");
    fgets(keyword, 142, stdin);
    keyword[strlen(keyword) - 1] = '\0';
    length = strlen(keyword) + 1;
    origKeyword = malloc(sizeof(char) * length);
    strcpy(origKeyword, keyword);

    while (tweetList != NULL)
    {
      // copy text into temp char array to inspect for keyword
      length = strlen(tweetList->text) + 1;
      tempText = malloc(sizeof(char) * length);
      strcpy(tempText, tweetList->text);

      // search for keyword is case-insensitive so make both strings lowercase
      for (i = 0; i < strlen(tempText); i++)
      {
        if (isupper(tempText[i]) > 0)
        {
          tempText[i] = tolower(tempText[i]);
        }
      }
      
      for (i = 0; i < strlen(keyword); i++)
      {
        if (isupper(keyword[i]) > 0)
        {
          keyword[i] = tolower(keyword[i]);
        }
      }
      // now search for keyword within user's text
      numSubstrings = 0;
      match = 0;
      j = 0;
      for (i = 0; i < strlen(tempText); i++)
      {
        if (tempText[i] == keyword[j])  // found first letter
        {
          // store current location of first letter in keyword
          current = i;
          match++;
          // compare next letters in keyword to following letters after tempText[current]
          for (j = 1; j < strlen(keyword); j++) // j = 1 - skip first letter of keyword
          {
            current++;
            if (tempText[current] == keyword[j])
            {
              match++;
              continue;
            }
            else
            {
              match = -1;
              break;
            }
          }
          // increment numSubstrings if match equals to length of keyword
          if (match == strlen(keyword))
          {
            numSubstrings++;
            match = 0;      // reset match for next user's tecxt
          }
          else
          {
            match = 0;
          }
        }
      }
      if (numSubstrings > 0)
      {
        printf("Match found for '%s': %s wrote: \"%s\"\n", origKeyword, tweetList->user, tweetList->text);
        totalSubstrings++;
      }
      // move to next node
      numSubstrings = 0;
      tweetList = tweetList->next;
      free(tempText);
    }
    free(origKeyword);
  }
  printf("\n");
  if (totalSubstrings > 0)
  {
    return 1;
  }
  return 0;
}

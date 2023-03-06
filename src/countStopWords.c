#include "headerA3.h"
#include "extraHeaderA3.h"

void countStopWords(tweet * tweetList)
{
  char stopWords[25][5]; // 25 stop words , 5 - max length of stop word is 4 + 1 (NULL)
  char *tempText, *tempWord;
  char *token;
  int individualStopWords, totalStopWords;
  int numTweets;

  // copy stop words into array stopWords;
  strcpy(stopWords[0], "a");
  strcpy(stopWords[1], "an");
  strcpy(stopWords[2] , "and");
  strcpy(stopWords[3] , "are");
  strcpy(stopWords[4] ,"as");
  strcpy(stopWords[5] , "at");
  strcpy(stopWords[6] , "be");
  strcpy(stopWords[7] , "by");
  strcpy(stopWords[8] , "for");
  strcpy(stopWords[9] , "from");
  strcpy(stopWords[10] , "has");
  strcpy(stopWords[11] , "he");
  strcpy(stopWords[12] , "in");
  strcpy(stopWords[13] , "is");
  strcpy(stopWords[14] , "it");
  strcpy(stopWords[15] , "its");
  strcpy(stopWords[16] , "of");
  strcpy(stopWords[17] , "on");
  strcpy(stopWords[18] , "that");
  strcpy(stopWords[19] , "the");
  strcpy(stopWords[20] , "to");
  strcpy(stopWords[21] , "was");
  strcpy(stopWords[22] , "were");
  strcpy(stopWords[23] , "will");
  strcpy(stopWords[24] , "with");

  individualStopWords = 0;
  totalStopWords = 0;
  numTweets = 0;
  if (tweetList == NULL)
  {
    printf("No tweets in list.\n");
  }
  else
  {
    // traverse linked list - tweetList
    while (tweetList != NULL)
    {
      // copy user's Text into tempText
      tempText = malloc(sizeof(char) * (strlen(tweetList->text) + 1));
      strcpy(tempText, tweetList->text);

      // use strTok to split string up into words - copy each word into tempWord
      token = strtok(tempText, " ");
      tempWord = malloc(sizeof(char) * (strlen(token) + 1));
      strcpy(tempWord, token);

      /*
        Additional function: matchStopWords
          - returns 1 if tempWord matches any of the 25 stop words
          - individualStopWords is incremented
      */

      individualStopWords += matchStopWords(tempWord, stopWords);
      free(tempWord);

      while (token != NULL)
      {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
          tempWord = malloc(sizeof(char) * (strlen(token) + 1));
          strcpy(tempWord, token);
          individualStopWords += matchStopWords(tempWord, stopWords);
          free(tempWord);
        }

      }

      // if previous tweet had found stop words then increment numTweets
      if (individualStopWords > 0)
      {
        // sum stopWords found in user's tweet to totalStopWords
        numTweets++;
        totalStopWords += individualStopWords;
      }
      // refresh individualStopWords count for next user's tweet
      individualStopWords = 0;

      // move to next user's tweet
      free(tempText);
      tweetList = tweetList->next;
    }

    printf("Across %d tweets, %d stop words were found.\n", numTweets, totalStopWords);
  }
}

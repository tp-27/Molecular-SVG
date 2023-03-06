/*
  Additional function: numberStopWords
    - returns 1 if tempWord matches any of the 25 stop words
    - individualStopWords is incremented
*/

#include "headerA3.h"
#include "extraHeaderA3.h"

int matchStopWords (char * word, char stopWords[25][5])
{
  int numStopWords;
  int i;

  // compare word from tweet to array of stop words
  numStopWords = 0;
  for (i = 0; i < 25; i++)
  {
    if (strcmp (word, stopWords[i]) == 0)
    {
      numStopWords++;
    }
  }

  return numStopWords;
}

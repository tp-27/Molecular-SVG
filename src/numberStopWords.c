#include "headerA3.h"
#include "extraHeaderA3.h"

int numberStopWords (char * word, char stopWords[25][5])
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

#include "headerA3.h"
#include "extraHeaderA3.h"

void saveTweetsToFile(tweet * tweetList)
{
  char fileName[100];
  FILE *inFile;

  printf("Enter the file name where you would like to store tweets: ");
  scanf("%s", fileName);
  inFile = fopen(fileName, "w");
  if (inFile == NULL)
  {
    printf("Error opening file.\n");
  }
  else
  {
    while (tweetList != NULL)
    {
      fprintf(inFile, "%d,%s,%s\n", tweetList->id, tweetList->user, tweetList->text);
      tweetList = tweetList->next;
    }

    printf("Tweets importing...\nSucessfully created file!\n");
  }

  fclose(inFile);
}

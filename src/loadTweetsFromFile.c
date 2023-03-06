#include "headerA3.h"
#include "extraHeaderA3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
  char fileName[100];
  FILE *inFile;
  tweet *inputTweet;
  char userInput[500];
  char *token;
  char convert[100];
  int temp;
  int column;


  printf("Enter a filename to load from: ");
  scanf("%s", fileName);
  printf("\n");

  inputTweet = NULL;
  inFile = fopen(fileName, "r");
  if (inFile == NULL)
  {
    printf("Error. File: %s was unable to open. Please try again.\n", fileName);
  }
  else
  {
    while (fgets(userInput, 500, inFile))
    {
    	inputTweet = malloc(sizeof(tweet));
    	column = 0;
    	token = strtok(userInput, ",");
    	while (token)
    	{
        // Extract userID
    		if (column == 0)
    		{
    			strcpy(convert,token);
    			temp = atoi(convert);
    			inputTweet->id = temp;
          token = strtok(NULL, ",");
    		}

        // Extract username
    		if (column == 1)
    		{
    			strcpy(inputTweet->user, token);
          token = strtok(NULL, "\n");
    		}

        // Extract user text
    		if (column == 2)
    		{
    			strcpy(inputTweet->text, token);
          // remove comma from end of user text
          if (inputTweet->text[strlen(inputTweet->text) - 1] == ',')
          {
             inputTweet->text[strlen(inputTweet->text) - 1] = '\0';
          }
          else if (inputTweet->text[strlen(inputTweet->text) - 2] == ',')
          {
             inputTweet->text[strlen(inputTweet->text) - 2] = '\0';
          }
          else
          {
            inputTweet->text[strlen(inputTweet->text) - 3] = '\0';
          }
          break;
    		}
    		column++;
    	}
      addNodeToList(tweetList, inputTweet);
    }
    printf("Tweets imported!\n");
    fclose(inFile);
  }

  printf("\n");
}

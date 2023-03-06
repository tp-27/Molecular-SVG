#include "headerA3.h"
#include "extraHeaderA3.h"

int main ()
{
  tweet * tweetList;
  tweet * newTweet;
  int inMenu;
  int menuOption;
  char menu[50];

  displayMenu();
  printf("Choose a menu option: ");
  fgets(menu, 50, stdin);
  menu[strlen(menu) - 1] = '\0';
  menuOption = atoi(menu);
  printf("\n");

  while ((menuOption < 1) || (menuOption > 9))
  {
    printf("Invalid menu option. Please enter a valid number: ");
    menu[0] = '\0';
    fgets(menu, 50, stdin);
    menu[strlen(menu) - 1] = '\0';
    menuOption = atoi(menu);
  }

  tweetList = NULL;             // list is initially empty
  inMenu = 1;
  newTweet = NULL;
  while (inMenu == 1)
  {
    switch (menuOption)
    {
      case 1:
        newTweet = createTweet(tweetList);
        addNodeToList(&tweetList, newTweet);
        break;

      case 2:
        displayTweets(tweetList);
        break;

      case 3:
        searchTweetsByKeyword(tweetList);
        break;

      case 4:
        countStopWords(tweetList);
        break;

      case 5:
        deleteTweet(&tweetList);
        break;

      case 6:
        saveTweetsToFile(tweetList);
        break;

      case 7:
        loadTweetsFromFile(&tweetList);
        break;

      case 8:
        sortID(&tweetList);
        break;

      case 9:
        freeTweets(tweetList);
        printf("Exiting...\n");
        return 0;
    }

    displayMenu();
    printf("Choose a menu option: ");
    fgets(menu, 50, stdin);
    menu[strlen(menu) - 1] = '\0';
    menuOption = atoi(menu);
    printf("\n");

    while ((menuOption < 1) || (menuOption > 9))
    {
      printf("Invalid menu option. Please enter a valid number: ");
      fgets(menu, 50, stdin);
      menu[strlen(menu) - 1] = '\0';
      menuOption = atoi(menu);
      printf("\n");
    }
  }

  return 0;
}

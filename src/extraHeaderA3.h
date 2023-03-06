#include <time.h>
#include <ctype.h>

// additional functions
void displayMenu ();

int matchStopWords (char * word, char stopWords[25][5]);

int countTweets (tweet * tweetList);

void deleteInsertNode(tweet ** tweetList, int position);

void insertNode (tweet ** tweetList, tweet * node, int position);

void freeTweets (tweet * tweetList);

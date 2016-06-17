/*
* a simply funtion call before rand(),just make rand() get more different;
* 
*/
#include <stdlib.h>

//Your can set the SEED_COUNTS value as your wish
#define COUNTS_OF_SEEDS 5

void setRandSeed()
{
  int i=0;	
  int seeds[COUNTS_OF_SEEDS]={0};
  srand(time(0));
  for(i=0;i<COUNTS_OF_SEEDS;i++)
  {
    seeds[i]=rand();
  }		
  int var = seeds[rand()%COUNTS_OF_SEEDS];		
  srand(var);
}

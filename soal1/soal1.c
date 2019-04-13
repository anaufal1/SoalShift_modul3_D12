#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t thread[100];
int t[100];
int x;

void* factorial()
{
	int input = t[x];
	int jawaban = 1;

	while(input > 0)
	{
		jawaban *= input;
	 	input--;
	}

	printf("%d! = %d\n", t[x], jawaban);
}

int main(int argc, char *argv[])
{
	int n = argc-1, a, b, iter, tukar;


	for(iter = 0; iter < n; iter++)
	{
		t[iter] = atoi(argv[iter+1]);
	}

	
  	for (iter = 0 ; iter < n-1; iter++)
  	{
    	  for (b = 0 ; b < n-a-1; b++)
    	  {
      		if (t[b] > t[b+1])
      		{
        	  tukar = t[b];
        	  t[b] = t[b+1];
        	  t[b+1] = tukar;
      		}
    	  }
  	}


	for(x = 0; x < n; x++)
	{
		pthread_create(&(thread[x]),NULL,&factorial,NULL);
	 	pthread_join(thread[x], NULL);
	}

	return 0;
}

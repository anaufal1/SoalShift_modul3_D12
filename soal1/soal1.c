#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *factorial(void* p);
int fact(int n);

int main()
{
	int z;
    pthread_t thread[100];
    
    for(z=0; ;z++){

    pthread_create( &thread[z], NULL, factorial, NULL); 

     pthread_join( thread[z], NULL);
}
    exit(EXIT_SUCCESS);
}

int fact(int n){
if(n==0 || n==1)
return 1;
else 
return n*fact(n-1);
}

void *factorial(void *p){
int t;
printf("berapa parallel:");
scanf("%d",&t);	
int i,j,num[t];
int n = sizeof(num)/sizeof(num[0]);
int temp;
for(i=0 ;i<n; i++){
scanf("%d", &num[i]);
}
for(i=0 ; i<n-1 ; i++){
for(j=0 ; j<n-i-1 ; j++){
		if(num[j] > num[j+1]){
			temp = num[j];
			num[j] = num[j+1];
			num[j+1] = temp;
	}
	}
	}
for(i=0 ; i<n ; i++){
printf("%d! = %d\n",num[i],fact(num[i]));
}
pthread_exit(0);
}

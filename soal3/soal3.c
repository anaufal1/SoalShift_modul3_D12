#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 
pthread_t tid1, tid2;

int WakeUp_Status = 0;
int Spirit_Status = 100;
int kelar=0;
int counta=0, counti=0; 
int agmal_s=0, iraj_s=0;

void* Agmal(void *arg){
	while(1){
		if(agmal_s == 1){
			sleep(10);
			agmal_s = 0;
}
}
}

void* Iraj(void *arg){
	while(1){
		if(iraj_s == 1){
			sleep(10);
			iraj_s = 0;
}
}
}

int main(){
	char string[100];
	
	pthread_create(&(tid1), NULL, Agmal, NULL);
	pthread_create(&(tid2), NULL, Iraj, NULL);

	while(1){
		if(kelar == 1){
			break;
}
	gets(string);
	
	if(strcmp(string,"agmal ayo bangun") == 0){
		if(agmal_s == 0){
			WakeUp_Status = WakeUp_Status + 15;
			printf("Agmal WakeUp_Status = %d\n",WakeUp_Status);
			counta++;
}
	else{
		printf("Agmal Ayo Bangun disabled 10 s \n");
}
}
	else if(strcmp(string,"iraj ayo tidur") == 0){
		if(iraj_s == 0){
			Spirit_Status = Spirit_Status - 20;
			printf("Iraj Spirit_Status = %d\n",Spirit_Status);
			counti++;
}
	else{
		printf("Fitur Iraj Ayo Tidur disabled 10 s \n");
}
}
	else if(strcmp(string,"all status") == 0){
		printf("Agmal WakeUp_Status = %d\n",WakeUp_Status);
		printf("Iraj Spirit_Status = %d\n",Spirit_Status);
}
	if(counti == 3){
		agmal_s = 1;
		counti = 0;
}
	if(counta == 3){
		iraj_s=1;
		counta=0;
}
	if(WakeUp_Status >= 100){
		printf("Agmal Terbangun,mereka bangun pagi dan berolahraga\n");
		kelar = 1;
}
	if(Spirit_Status <= 0){
		printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
		kelar = 1;
}
	printf("\n");
}
       return 0;
}


#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define PORT 8080
int *value;

void* tulis(void *arg)
{
        while (1) {
                printf("stok ada %d\n", *value);
                sleep(5);
}
         
    return NULL;
}
int main(int argc, char const *argv[]) {
        key_t key = 1234;
pthread_t tid1;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
        *value = 5;
pthread_create(&(tid1), NULL, tulis, NULL);
   int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
        while (1) {
                valread = read( new_socket , buffer, 1024);
                if (strcmp(buffer,"tambah")==0)
                *value+=1;
                memset(buffer,0,sizeof(buffer));
        }

pthread_join(tid1, NULL);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

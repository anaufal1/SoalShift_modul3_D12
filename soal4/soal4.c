#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[5];
int iter;

void* creating_file(void *arg){
    
    pthread_t id=pthread_self(); //id self itu pthread id pas waktu dijalanin atau thread keberapa gitu maksudnya
    
    iter=0;
    if(pthread_equal(id,tid[0])){
        system("ps aux | head -11 > /home/absolutlubis/Documents/FolderProses1/SimpanProses1.txt");   //head -11 itu buat berapa file proses yang masuk di file system, pakek -11 itu soale buat maksimalnya 10
    }
    
    else if(pthread_equal(id,tid[1])){
        system("ps aux | head -11 > /home/absolutlubis/Documents/FolderProses2/SimpanProses2.txt");
    }
    
    iter=1;
    return NULL;
}

void* compress_file(void *arg){
    
    while(iter!=1){
    }
    
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[2])){
        system("zip -qmj /home/absolutlubis/Documents/FolderProses1/KompresProses1.zip /home/absolutlubis/Documents/FolderProses1/SimpanProses1.txt"); //pakai -qmj buat compress agar yang di kompres itu tidak beserta file sourcenya, hanya file isinya aja karena saat compress kita menggunakan 2 source, 1 untuk tempat menyimpan, dan yang satunya untuk tempat file yang akan di compress
    }
    
    else if(pthread_equal(id,tid[3])){
        system("zip -qmj /home/absolutlubis/Documents/FolderProses2/KompresProses2.zip /home/absolutlubis/Documents/FolderProses2/SimpanProses2.txt");
    }
    
    iter=2;
    return NULL;
}

void* extract_file(void *arg){
    
    while(iter!=2){
    }
    
    sleep(15);
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[4])){
        system("unzip -qd /home/absolutlubis/Documents/FolderProses1 /home/absolutlubis/Documents/FolderProses1/KompresProses1.zip"); //pakai -qd untuk hasil ekstraknya dapat di arahkan ke folder tertentu
    }
    
    else if(pthread_equal(id,tid[5])){
        system("unzip -qd /home/absolutlubis/Documents/FolderProses2 /home/absolutlubis/Documents/FolderProses2/KompresProses2.zip");   
    }
    
    return NULL;
}

int main(void)
{
	
    int i=0, cek;
   
    while(i<2){ //while pertama kali untuk cek dua progam pertama, yaitu buat mencatat hasil ps -aux 
      cek=pthread_create(&(tid[i]),NULL,&creating_file,NULL);
        //if(cek!=0){
         //   printf("\n can't create thread : [%s]",strerror(cek));
       
        i++;
    }
    
    while(i<4){ //while kedua untuk cek dua progam untuk compress file
        cek=pthread_create(&(tid[i]),NULL,&compress_file,NULL);
        //if(cek!=0){
         //   printf("\n can't create thread : [%s]",strerror(cek));
        
        i++;
    }
    
    printf("\n Menunggu 15 detik untuk mengekstrak kembali \n");
    
    while(i<6){ //while ketiga untuk cek dua progam waktu unzip file
        cek=pthread_create(&(tid[i]),NULL,&extract_file,NULL);
     //   if(cek!=0){
     //       printf("\n can't create thread : [%s]",strerror(cek)); //streror itu perintah untuk cek progam eror atau tidak
     //   }
        i++;
    }
    
     
    pthread_join(tid[0],NULL); //pthread_join agar proses berjalan menunggu thread pertama selesai baru dilanjut ke thread selanjutnya
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    pthread_join(tid[3],NULL);
    pthread_join(tid[4],NULL);
    pthread_join(tid[5],NULL);
    return 0;
}

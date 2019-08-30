#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>

int main() {
  int shmid, a ,i;
  char *ptr, *shmptr;
  
  shmid = shmget(1000, 100, IPC_CREAT | 0666);
  shmptr = shmat(shmid, NULL, 0);
  ptr = shmptr;
  
  for(i = 0; i < 3; i++) {
    printf("Enter name: ");
    scanf("%s", ptr);
    a = strlen(ptr);
    printf("String length:%d\n", a);
    ptr[a] = ' ';
    
    printf("Enter ip: ");
    ptr = ptr+a+1;
    scanf("%s",ptr);
    a = strlen(ptr);
    ptr[a] = '\n';
    ptr = ptr+a+1;
  }
  
  ptr[strlen(ptr + 1)] = '\0';
  printf("\nARP table at serverside is = \n%s", shmptr);
  shmdt(shmptr);
}

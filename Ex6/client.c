#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>
int main() {
  int shmid, a;
  char *ptr, *shmptr;
  char ptr2[51], ip[12], mac[26];
  
  shmid = shmget(1000, 100, 0666);
  shmptr = shmat(shmid, NULL, 0);
  
  printf("The ARPtable is: \n");
  printf("%s", shmptr);
  printf("1.ARP\n2.RARP\n3.EXIT\n");
  scanf("%d", &a);
  
  switch(a) {
  case 1:
    printf("Enter IP address: ");
    scanf("%s", ip);
    ptr = strstr(shmptr, ip);
    ptr -= 18;
    sscanf(ptr, "%s%*s", ptr2);
    printf("MAC address is: %s\n",ptr2);
    break;
    
  case 2:
    printf("Enter MAC address: ");
    scanf("%s", mac);
    ptr = strstr(shmptr, mac);
    sscanf(ptr, "%*s%s", ptr2);
    printf("IP address is %s\n", ptr2);
    break;
    
  case 3:
    exit(1);
  }
}

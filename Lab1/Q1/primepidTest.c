#include "kernel/types.h"
#include "user/user.h"

#define N 10000

int
main(void)
{
  for(int i = 0; i < N; i++){
    int pid = fork();
    if(pid < 0){
      printf("fork failed\n");
      exit(1);
    }
    if(pid == 0){
      printf("child %d: my PID %d\n", i+1, getpid());
      exit(0);
    }
    else {
        wait(0);
    }
  }
  
  exit(0);
}

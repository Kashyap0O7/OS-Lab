#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "procinfo.h"

#define NPROC 64

int main(void)
{
  struct procinfo arr[NPROC];
  int n = getprocinfo(arr);

  if (n < 0)
  {
    printf("Failed to retrieve process info\n");
    exit(1);
  }

  printf("PID \t STATE \t\t TICKS \t NAME\n");
  printf("------------------------------------------\n");

  for (int i = 0; i < n; i++)
  {
    char *state;

    switch (arr[i].state)
    {
      case UNUSED:   continue; // Skip UNUSED
      case USED:     state = "USED"; break;
      case SLEEPING: state = "SLEEPING"; break;
      case RUNNABLE: state = "RUNNABLE"; break;
      case RUNNING:  state = "RUNNING"; break;
      case ZOMBIE:   state = "ZOMBIE"; break;
      default:       continue; // Skip unknown
    }

    printf("%d \t %s \t %d \t %s\n", arr[i].pid, state, arr[i].ticks, arr[i].name);
  }

  exit(0);
}
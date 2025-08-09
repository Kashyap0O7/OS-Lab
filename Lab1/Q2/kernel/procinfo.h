#pragma once
#include "kernel/types.h"

#ifndef STATE_DEFINE
#define STATE_DEFINE
enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
#endif

#ifndef PROCINFO
#define PROCINFO
struct procinfo
{
  int pid;
  enum procstate state;
  uint ticks;
  char name[16];
};
#endif
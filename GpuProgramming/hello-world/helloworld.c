#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
#pragma omp target teams parallel num_teams(4) thread_limit(64)
	{
  int numTeam = omp_get_team_num();
  int numThread = omp_get_thread_num();
  int global_tid = numTeam * 64 + numThread;
  if (global_tid == 100) { int *a = (int*) 0x10000; *a = 0; }
  printf("Hello world! "
         "I’m thread %i out of 64 in team %i. "
         "My global thread id "
         "is %i out of 256\n",
         numThread, numTeam, global_tid);
	}
  return EXIT_SUCCESS;
}

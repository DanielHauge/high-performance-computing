#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
#pragma omp target teams parallel num_teams(4) thread_limit(64)
  int numTeam = omp_get_team_num();
  int numThread = omp_get_thread_num();
  printf("Hello world! "
         "I’m thread %i out of 64 in team %i. "
         "My global thread id "
         "is %i out of 256",
         numThread, numTeam, numTeam * 64 + numThread);
  return EXIT_SUCCESS;
}

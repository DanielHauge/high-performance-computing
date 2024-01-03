#include "data.h"

#ifdef ARRAY_OF_STRUCTS
double distcheck(particle_t *p, int n) {

  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += p[i].dist;
  }
  return sum;
}
#else
double distcheck(particle_t p, int n) {

  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += p.dist[i];
  }
  return sum;
}
#endif

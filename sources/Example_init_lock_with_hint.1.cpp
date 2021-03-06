/*
* @@name:	init_lock.1c
* @@type:	C++
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_4.5
*/
#include <omp.h>

omp_lock_t *new_locks()
{
  int i;
  omp_lock_t *lock = new omp_lock_t[1000];

  #pragma omp parallel for private(i)
    for (i=0; i<1000; i++)
    {
      omp_init_lock_with_hint(&lock[i], 
        static_cast<omp_lock_hint_t>(omp_lock_hint_contended |
                                     omp_lock_hint_speculative));
    }
    return lock;
}

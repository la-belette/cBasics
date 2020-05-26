#ifndef CBASICS_MEMORY_MANAGER_H
#define CBASICS_MEMORY_MANAGER_H

void swap(int *a,
          int *b);

void memswap(void *a,
             void *b,
             int size);

void *remalloc(void* p,
               unsigned int s,
               unsigned int ns);

#endif //CBASICS_MEMORY_MANAGER_H

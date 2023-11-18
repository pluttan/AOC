#ifndef __ALH__
#define __ALH__

#ifndef NULL
#define NULL (void *)0
#endif

void *malloc(long unsigned int size);
void free(void *ptr);

#endif // !__ALH__
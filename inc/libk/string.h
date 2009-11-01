#ifndef __STRING_H
#define __STRING_H

#define size_t unsigned long
#define NULL 0

void *memcpy(void *dest, void *src, size_t n);
void *memset(void *dest, int p, size_t n);
size_t strlen(const char *str);

#endif

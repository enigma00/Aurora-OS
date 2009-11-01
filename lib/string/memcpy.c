#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
{
	if ((src + n > dest) || (dest + n > src))
	{
		return (void *) NULL;
	}
	while (n!=0)
	{
		((char * ) dest)[n] = ((char *) src)[n];
		n--;
	}
	return dest;
}

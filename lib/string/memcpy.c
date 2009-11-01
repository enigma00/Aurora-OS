#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
{
	if ((src + n > dest) || (dest + n > src))
		return (void *) NULL;
	char *src2 = (char *) src;
	char *dest2 = (char *) dest;
	while (n!=0)
	{
		dest2[n] = src2[n];
		n--;
	}
}

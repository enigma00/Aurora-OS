#include <string.h>

void *memset(void *dest, int p, size_t n)
{
	char pattern = (char) p & 0x000000FF;
	while (n > 0)
	{
		((char *) dest)[n] = pattern;
	}
	return dest;
}

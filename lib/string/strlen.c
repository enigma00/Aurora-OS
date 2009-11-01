#include <string.h>

size_t strlen(const char *str)
{
	size_t retval = 0;
	while (str[retval] != 0)
	{
		retval++;
	}
	return retval;
}

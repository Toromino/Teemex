#include <string.h>

/*
 * TO DO: Replace with a faster solution.
 * But works for the moment...
 */
size_t strlen(const char *_str)
{
    size_t len = 0;

    while(_str[len])
		{
			len++;
		}

    return(len);
}

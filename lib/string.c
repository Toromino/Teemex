#include <string.h>

size_t strlen(const char *_str)
{
    size_t len = 0;

    while(_str[len])
		{
			len++;
		}

    return(len);
}

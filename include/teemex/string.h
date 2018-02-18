#ifndef _TEEMEX_STRING_H
#define _TEEMEX_STRING_H

size_t strlen(const char *_str)
{
    size_t len = 0;

    while(_str[len])
		{
			len++;
		}

    return(len);
}

#endif

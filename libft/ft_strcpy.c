#include "libft.h"

char    *ft_strcpy(char* destination, const char* source)
{
    char *ptr;
    
    ptr = destination;
    if (destination == NULL)
           return NULL;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return (ptr);
}
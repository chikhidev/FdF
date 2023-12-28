#include "./includes/header.h"

void    ft_free(void    **ptr)
{
    if (*ptr != NULL)
    {   
        free(*ptr);
        *ptr = NULL;
    }
}

void    *ft_realloc(void *ptr, size_t old_size, size_t size)
{
    void    *new_ptr;
    size_t  _size_needed;

    if (!ptr)
        return (malloc(size));
    _size_needed = (size > old_size) ? size : old_size;
    new_ptr = malloc(_size_needed);
    if (!new_ptr)
        return (NULL);
    ft_memcpy(new_ptr, ptr, old_size);
    ft_free((void **)&ptr);
    return (new_ptr);
}

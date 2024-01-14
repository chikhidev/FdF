#include "./includes/header.h"

int print_error(const char *message, int error_signal)
{
    if (!message)
        return (error_signal);
    write(2, "Error: ", 8);
    write(2, message, ft_strlen(message));
    exit(error_signal);
}
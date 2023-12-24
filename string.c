#include "./includes/string_utils.h"

int	cols_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

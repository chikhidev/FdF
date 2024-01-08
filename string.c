#include "./includes/string_utils.h"

int	cols_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	atoi_hexa(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 16 + str[i] - 'a' + 10;
		else
			return (0);
		i++;
	}
	return (res);
}
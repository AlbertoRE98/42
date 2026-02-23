#include "libft.h"

int ft_isalpha(int letter)
{
	if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
			return (1);
	return (0);
}
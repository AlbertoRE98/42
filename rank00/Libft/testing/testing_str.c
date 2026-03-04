

#include <stdio.h>

int main(void)
{
    char **result;
    size_t i;
    
    result = ft_split("hello world foo", ' ');
    i = 0;
    while (result && result[i])
    {
        printf("[%zu]: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    result = ft_split("  hello   world  ", ' ');
    i = 0;
    while (result && result[i])
    {
        printf("[%zu]: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    result = ft_split(NULL, ' ');
    printf("NULL test: %s\n", result ? "FAIL" : "PASS");
    
    return (0);
}
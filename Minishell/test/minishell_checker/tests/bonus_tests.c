
#include <stdio.h>
#include <stdlib.h>

void    test_and_or(void);
void    test_wildcards(void);

int    main(void)
{
    printf("Running bonus tests...\n");

    test_and_or();
    test_wildcards();

    printf("All bonus tests completed.\n");
    return (0);
}

void    test_and_or(void)
{
    int    result;

    result = system("false && echo This should not print");
    if (result == 0)
        printf("Test &&: FAIL\n");
    else
        printf("Test &&: PASS\n");

    result = system("true || echo This should not print");
    if (result == 0)
        printf("Test ||: FAIL\n");
    else
        printf("Test ||: PASS\n");
}

void    test_wildcards(void)
{
    int    result;

    result = system("ls *");
    if (result != 0)
        printf("Test wildcards: FAIL\n");
    else
        printf("Test wildcards: PASS\n");
}

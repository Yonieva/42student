
#include <stdio.h>
#include <stdlib.h>

void    test_pwd(void);
void    test_echo(void);
void    test_cd(void);
void    test_env(void);
void    test_export_unset(void);
void    test_exit(void);
void    test_redirections(void);
void    test_pipes(void);
void    test_signals(void);
void    test_quotes(void);
void    test_return_value(void);

int    main(void)
{
    printf("Running base tests...\n");

    test_pwd();
    test_echo();
    test_cd();
    test_env();
    test_export_unset();
    test_exit();
    test_redirections();
    test_pipes();
    test_signals();
    test_quotes();
    test_return_value();

    printf("All base tests completed.\n");
    return (0);
}

void    test_pwd(void)
{
    int    result;

    result = system("pwd");
    if (result != 0)
        printf("Test pwd: FAIL\n");
    else
        printf("Test pwd: PASS\n");
}

void    test_echo(void)
{
    int    result;

    result = system("echo Hello, World!");
    if (result != 0)
        printf("Test echo: FAIL\n");
    else
        printf("Test echo: PASS\n");

    result = system("echo -n Hello");
    if (result != 0)
        printf("Test echo -n: FAIL\n");
    else
        printf("Test echo -n: PASS\n");
}

void    test_cd(void)
{
    int    result;

    result = system("cd / && pwd");
    if (result != 0)
        printf("Test cd to root: FAIL\n");
    else
        printf("Test cd to root: PASS\n");

    result = system("cd .. && pwd");
    if (result != 0)
        printf("Test cd to parent: FAIL\n");
    else
        printf("Test cd to parent: PASS\n");
}

void    test_env(void)
{
    int    result;

    result = system("env");
    if (result != 0)
        printf("Test env: FAIL\n");
    else
        printf("Test env: PASS\n");
}

void    test_export_unset(void)
{
    int    result;

    result = system("export TEST_VAR=42 && env | grep TEST_VAR");
    if (result != 0)
        printf("Test export: FAIL\n");
    else
        printf("Test export: PASS\n");

    result = system("unset TEST_VAR && env | grep TEST_VAR");
    if (result != 0)
        printf("Test unset: FAIL\n");
    else
        printf("Test unset: PASS\n");
}

void    test_exit(void)
{
    int    result;

    result = system("exit");
    if (result != 0)
        printf("Test exit: FAIL\n");
    else
        printf("Test exit: PASS\n");
}

void    test_redirections(void)
{
    int    result;

    result = system("echo Hello > testfile && grep Hello testfile");
    if (result != 0)
        printf("Test redirection >: FAIL\n");
    else
        printf("Test redirection >: PASS\n");

    result = system("echo World >> testfile && grep World testfile");
    if (result != 0)
        printf("Test redirection >>: FAIL\n");
    else
        printf("Test redirection >>: PASS\n");

    result = system("grep Hello < testfile");
    if (result != 0)
        printf("Test redirection <: FAIL\n");
    else
        printf("Test redirection <: PASS\n");

    system("rm -f testfile");
}

void    test_pipes(void)
{
    int    result;

    result = system("echo Hello | grep Hello");
    if (result != 0)
        printf("Test pipe: FAIL\n");
    else
        printf("Test pipe: PASS\n");

    result = system("ls | grep Makefile");
    if (result != 0)
        printf("Test pipe with ls: FAIL\n");
    else
        printf("Test pipe with ls: PASS\n");
}

void    test_signals(void)
{
    printf("Please test signals manually (ctrl-C, ctrl-D, ctrl-\).
");
}

void    test_quotes(void)
{
    int    result;

    result = system("echo "This is a test"");
    if (result != 0)
        printf("Test double quotes: FAIL\n");
    else
        printf("Test double quotes: PASS\n");

    result = system("echo 'This is a test'");
    if (result != 0)
        printf("Test single quotes: FAIL\n");
    else
        printf("Test single quotes: PASS\n");
}

void    test_return_value(void)
{
    int    result;

    system("ls");
    result = system("echo $?");
    if (result != 0)
        printf("Test return value: FAIL\n");
    else
        printf("Test return value: PASS\n");
}

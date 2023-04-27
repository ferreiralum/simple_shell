#include "main.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: Always returns -2 to indicate that the shell should exit with a
 * given status code. If an error occurs, the function returns 1 to indicate
 * that the shell should continue running.
 * Author: Ferreilra Lumbimi
 */
int _myexit(info_t *info)
{
int exit_code = 0;

if (info->argv[1])
{
exit_code = _erratoi(info->argv[1]);
if (exit_code == -1)
{
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
}
return (-2 * (exit_code != 0) - 1);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always returns 0.
 */
int _mycd(info_t *info)
{
char *dir, buffer[1024];

if (!info->argv[1])
dir = _getenv(info, "HOME=");
else if (_strcmp(info->argv[1], "-") == 0)
dir = _getenv(info, "OLDPWD=");
else
dir = info->argv[1];

if (!dir)
{
print_error(info, "cd: ");
_eputs(info->argv[1]);
_eputs(": No such file or directory\n");
return (0);
}

if (chdir(dir) == -1)
{
print_error(info, "cd: ");
_eputs(dir);
_eputs(": ");
perror(NULL);
return (0);
}

_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
return (0);
}

/**
 * _myhelp - displays help information for the shell.
 * @info: Structure containing potential arguments.
 * Return: Always returns 0.
 */
int _myhelp(info_t *info)
{
(void)info; /* suppress unused parameter warning */

_puts("Welcome to Simple Shell! This shell is capable of executing 
		simple commands.\n");
_puts("The following built-in commands are available:\n");
_puts("exit [status]: Exit the shell with a given status code. If no status 
		is provided, exit with 0.\n");
_puts("cd [dir]: Change the current working directory. If no directory is 
		provided, change to the HOME directory.\n");
_puts("help: Display this help message.\n");

return (0);
}


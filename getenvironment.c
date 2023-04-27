#include "main.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Author: Ferreira Lumbimi
 * Return: The string array copy of the environment.
 */
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
free_str_arr(info->environ);
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return info->environ;
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The name of the environment variable to remove.
 * Return: 1 on success, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
size_t i = 0;
int env_changed = 0;

if (!info->env || !var)
return 0;

for (list_t *node = info->env; node; node = node->next, i++)
{
char *p = starts_with(node->str, var);
if (p && *p == '=')
{
delete_node_at_index(&(info->env), i);
env_changed = 1;
i--;
}
}

info->env_changed = env_changed;
return env_changed;
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The name of the environment variable to set or modify.
 * @value: The value of the environment variable to set or modify.
 * Return: 0 on success, 1 on failure.
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;

if (!var || !value)
return 1;

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return 1;

_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);

for (list_t *node = info->env; node; node = node->next)
{
char *p = starts_wih(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return 0;
}
}

add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return 0;
}

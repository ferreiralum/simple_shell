#include "main.h"

/**
 * print_history - Prints the history list, one command per line,
 *                 preceded with line numbers starting at 0.
 * @info: Pointer to the info_t struct containing the history list.
 * Author: Ferreira Lumbimi
 * Return: Always 0.
 */
int print_history(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - Removes an alias from the alias list.
 * @info: Pointer to the info_t struct containing the alias list.
 * @alias: String containing the alias to remove.
 * Return: 0 on success, 1 on failure.
 */
int unset_alias(info_t *info, char *alias)
{
char *equals = strchr(alias, '=');
if (!equals)
return (1);
*equals = '\0';
int ret = delete_node_at_index(&info->alias, get_node_index(info->alias, 
node_starts_with(info->alias, alias, -1)));
*equals = '=';
return (ret);
}

/**
 * set_alias - Adds or modifies an alias in the alias list.
 * @info: Pointer to the info_t struct containing the alias list.
 * @alias: String containing the alias to set.
 * Return: 0 on success, 1 on failure.
 */
int set_alias(info_t *info, char *alias)
{
char *equals = strchr(alias, '=');
if (!equals)
return (1);
if (!*++equals)
return unset_alias(info, alias);
unset_alias(info, alias);
return (add_node_end(&info->alias, alias, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: Pointer to the node containing the alias.
 * Return: 0 on success, 1 on failure.
 */
int print_alias(list_t *node)
{
if (!node)
return (1);
char *equals = strchr(node->str, '=');
if (!equals)
return (1);
*equals = '\0';
printf("%s='%s'\n", node->str, equals + 1);
*equals = '=';
return (0);
}

/**
 * alias - Implements the alias builtin.
 * @info: Pointer to the info_t struct containing the alias list.
 * Return: Always 0.
 */
int alias(info_t *info)
{
int i;
char *equals;
list_t *node;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}

for (i = 1; i < info->argc; i++)
{
equals = strchr(info->argv[i], '=');
if (equals)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}

/**
 * print_environment - Prints the current environment variables.
 * @info: Pointer to the info_t struct containing the environment variables.
 * Return: Always 0.
 */
int print_environment(info_t *info)
{
print_list_str(info->env);
return (0);
}

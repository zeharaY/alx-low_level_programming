#include "hash_tables.h"

/**
 * hash_table_create - Creates the hash table.
 * @size: Size of the table.
 *
 * Return: Hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hashtable;

	if (size == 0)
		return (NULL);
	hashtable = malloc(sizeof(hash_table_t));
	if (hashtable == NULL)
		return (NULL);
	hashtable->size = size;
	hashtable->array = malloc(sizeof(hash_node_t *) * size);
	if (hashtable->array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		hashtable->array[i] = NULL;
	}
	return (hashtable);
}

/**
 * hash_djb2 - Hash function that implement djb2 algorithm.
 * @str: Key to applied the transformation.
 *
 * Return: Integer
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * key_index - Associate an index to a key.
 * @key: Key to be indexed.
 * @size: Size of the hash table.
 *
 * Return: Integer 
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int result;

	result = hash_djb2(key) % size;
	return (result);
}

/**
 * free_node - Free a node.
 * @node: the Node
 *
 * Return: Void
 */
void free_node(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * hash_table_set - Set a value in the hash table.
 * @ht: Hash table.
 * @key: Key to be indexed.
 * @value: Value to set in the hash table.
 *
 * Return: 1 or 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (strcmp(key, "") == 0 || key == NULL || ht == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup((char *)key);
	new_node->value = strdup((char *)value);
	new_node->next = NULL;
	if (ht->array[index] == NULL)
		ht->array[index] = new_node;
	else
	{
		current = ht->array[index];
		if (strcmp(current->key, key) == 0)
		{
			new_node->next = current->next;
			ht->array[index] = new_node;
			free_node(current);
			return (1);
		}
		while (current->next != NULL && strcmp(current->next->key, key) != 0)
		{ current = current->next;
		}
		if (strcmp(current->key, key) == 0)
		{
			new_node->next = current->next->next;
			free_node(current->next);
			current->next = new_node;
		}
		else
		{
			new_node->next = ht->array[index];
			ht->array[index] = new_node;
		}
	}
	return (1);
}

/**
 * hash_table_get - Get a value from the hash table.
 * @ht: Hash table.
 * @key: Key.
 *
 * Return: The value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (strcmp(key, "") == 0 || key == NULL || ht == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	if (current == NULL)
		return (NULL);
	while (strcmp(current->key, key) && current != NULL)
	{
		current = current->next;
	}
	if (current == NULL)
		return (NULL);
	else
		return (current->value);
}

/**
 * hash_table_print - Print whole the hash table.
 * @ht: the Hash table.
 *
 * Return: Void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, flag = 0;
	hash_node_t *current;

	if (ht == NULL)
		return;
	putchar('{');
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		if (current != NULL)
		{
			while (current != NULL)
			{
				if (flag == 1)
				{
					printf(", ");
				}
				printf("'%s': '%s'", current->key, current->value);
				flag = 1;
				current = current->next;
			}
		}
	}
	putchar('}');
	putchar('\n');
}

/**
 * hash_table_delete - Delete the hash table.
 * @ht: the Hash table.
 *
 * Return: Void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			while (ht->array[i] != NULL)
			{
				current = ht->array[i]->next;
				free(ht->array[i]->key);
				free(ht->array[i]->value);
				free(ht->array[i]);
				ht->array[i] = current;
			}
		}
	}
	free(ht->array);
	free(ht);
}


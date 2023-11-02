#include "shell.h"

/**
 * main - 
 * Return: 0 
 */

int main(void)
{
	char *texts = NULL;
	size_t i = 0;
	ssize_t bty;
	char **bts;

	bty = _getline(&texts, &i, stdin);
	bts = _strtok(texts, ' ');
	printf("Length is %lu\n", bty);
	printf("The string is %s\n", texts);
	printf("The first string is %s\n", bts[0]); 
	/*while (true)
	{
		textinput = _getline(stdin);
	*/
	return (0);
}

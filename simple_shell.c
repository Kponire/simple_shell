#include "shell.h"

int main(void)
{
	char *texts = NULL;
	size_t i = 0;
	ssize_t bty;

	bty = _getline(&texts, &i, stdin);
	printf("Length is %lu\n", bty);
	printf("The string %s\n", texts);
	/*while (true)
	{
		textinput = _getline(stdin);
	*/
	return (0);
}

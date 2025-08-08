#include <stdio.h>

int	bonjour = 42;

namespace escargot
{
	int	bonjour = 666;
	const char *bonsoir = "bg";
}

namespace paul = escargot;

int	main(void)
{
	printf("bonjour_global [%d]\n", ::bonjour);
	printf("bonjour::escargot [%d]\n", escargot::bonjour);
	printf("bonjour::paul [%d]\n", paul::bonjour);
	printf("bonsoir::paul [%s]\n", paul::bonsoir);

	return (0);
}
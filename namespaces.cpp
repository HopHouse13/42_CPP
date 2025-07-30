#include <stdio.h>

int	bonjour = 42;

namespace test
{
	int	bonjour = 666;
	const char *bonsoir = "bg";
}

namespace paul = test;

int	main(void)
{
	printf("bonjour_global [%d]\n", ::bonjour);
	printf("bonjour::test [%d]\n", test::bonjour);
	printf("bonjour::paul [%d]\n", paul::bonjour);
	printf("bonsoir::paul [%s]\n", paul::bonsoir);

	return (0);
}
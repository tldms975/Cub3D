#include <iostream>
#include <string>

int	main(int ac, char *av[])
{
	std::string	s;

	if (ac < 2)
		s = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
			s += toupper(av[i][j]);
	}
	std::cout << s << '\n';
	return (0);
}

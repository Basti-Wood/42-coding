#include <iostream>
void megaphone(std::string str)
{
	char c;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 32;
		else
			c = str[i];
		std::cout << c;
	}
	
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			megaphone(argv[i]);
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

#include "so_long.h"

char	*ft_consc_join(char **args)
{
	char	*str;
	int		i;

	str = args[0];
	i = 0;
	while (args[i])
		str = ft_strjoin(str, args[i++]);
	return (str);
}

char	*path_to_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("./textures/", sprite_name);
	str1 = ft_strjoin(str1, "/");
	str1 = ft_strjoin(str1, sprite_name);
	str1 = ft_strjoin(str1, "_");
	str1 = ft_strjoin(str1, nbr);
	str1 = ft_strjoin(str1, ".png");
	return (str1);
}

int main(void)
{
	char	*sprite = "test";
	char	*str;
	int		len = 2;
	int		i = 0;

	while (i < len)
	{
		str = path_to_sprite(sprite, i);
		printf("%s\n", str);
		i++;
	}
}
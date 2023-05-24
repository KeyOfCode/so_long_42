
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

/* int main(void)
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
} */

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	param = NULL;

	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		printf("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		printf("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		printf("!");
	
	if (keydata.key == (MLX_KEY_ESCAPE))
	{
		printf("test ended succesfully\n");
		exit(EXIT_SUCCESS);
	}
}

int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
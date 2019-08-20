/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:48:02 by jterrell          #+#    #+#             */
/*   Updated: 2019/08/04 20:48:06 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);
int		gbs(int layer);
int		bonus(int layer);
void	sastantua(int size);
void	print_layer(int cl, int ll);
void	print_ll(int ll, int i);

int		gbs(int layer)
{
	int number_string;

	number_string = (layer + 1) * (layer + 2) / 2 - 2;
	return (number_string * 2 - 1);
}

int		bonus(int layer)
{
	if (layer == 0)
		return (0);
	else if (layer == 1)
		return (0);
	else if (layer % 2 == 1)
		return (bonus(layer - 1) + layer + 1);
	else
		return (bonus(layer - 1) + layer + 2);
}

void	print_layer(int cl, int ll)
{
	int i;
	int j;

	i = 1;
	while (i <= cl + 2)
	{
		j = 0;
		while (j++ < (gbs(ll) + bonus(ll) + (ll + 1) * 2) / 2\
				- (gbs(cl) + bonus(cl) + (i - 1) * 2) / 2)
			ft_putchar(' ');
		ft_putchar('/');
		j = 0;
		if (cl == ll)
		{
			print_ll(ll, i);
		}
		else
		{
			while (j++ < gbs(cl) + bonus(cl) + (i - 1) * 2)
				ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	print_ll(int ll, int i)
{
	int j;

	j = 0;
	if ((i > 2 && ll % 2) || (i > 3 && ll % 2 == 0))
	{
		while (j++ < (gbs(ll) + bonus(ll) + (i - 1) * 2) / 2 - (ll - 1) / 2)
			ft_putchar('*');
		while (j++ < (gbs(ll) + bonus(ll) + (i - 1) * 2) / 2 + (ll - 1) / 2 + 2)
		{
			if (j == (gbs(ll) + bonus(ll) + (i - 1) * 2) / 2 \
					+ (ll - 1) / 2 + 1 && i - 3 == ll / 2 && ll > 4)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		while (j++ < gbs(ll) + bonus(ll) + (i - 1) * 2 + 2)
			ft_putchar('*');
	}
	else
	{
		while (j++ < gbs(ll) + bonus(ll) + (i - 1) * 2)
			ft_putchar('*');
	}
}

void	sastantua(int size)
{
	int i;

	i = 1;
	while (i <= size)
		print_layer(i++, size);
}

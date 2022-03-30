/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 20:06:38 by marlou        #+#    #+#                 */
/*   Updated: 2020/12/14 13:30:11 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_num(char *str, int x)
{
	int j;
	int num;

	j = 0;
	while (str[x] >= 48 && str[x] <= 57)
	{
		if (j == 0)
		{
			num = str[x] - 48;
		}
		else if (j <= 10 && num <= 214748364 && str[x] <= '9' && str[x] >= '0')
			num = num * 10 + (str[x] - 48);
		x++;
		j++;
	}
	if (j != 0)
		return (num);
	else
		return (0);
}

static int	ft_minus(char *str, int a)
{
	int x;

	if (str[a] == 45)
	{
		x = -1;
	}
	else if (str[a] == 43)
	{
		x = 1;
	}
	else
	{
		x = 1;
	}
	return (x);
}

int			ft_atoi(char *str)
{
	int i;
	int x;
	int num;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || \
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	x = ft_minus(str, i);
	if (str[i] == 43 || str[i] == 45)
	{
		i++;
	}
	num = ft_num(str, i);
	num = x * num;
	if (ft_num(str, i) != 0)
		return (num);
	else
		return (0);
}

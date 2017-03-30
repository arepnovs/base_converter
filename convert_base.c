#include "convert.h"

char	*get_figure(char *line, int f)
{
	char *t;

	if (f == 1)
	{
		t = ft_strchr(line, ' ');
		*t = '\0';
		line = ft_strdup(line);
		return (line);
	}
	else
	{
		t++;
		line = t;
		return (line);
	}
}

void	nbr_to_str(unsigned int value, unsigned int base, char **str)
{
	if (value >= base)
	{
		nbr_to_str(value / base, base, str);
		nbr_to_str(value % base, base, str);
	}
	else
	{
		if (value >= 10)
			**str = value + 'A' - 10;
		else
			**str = value + '0';
		(*str)++;
	}
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 33);
	while (i < 33)
	{
		str[i] = 0;
		i++;
	}
	p = str;
	if (value < 0)
	{
		if (base == 10)
		{
			*p = '-';
			p++;
		}
		value *= -1;
	}
	if (base > 1 && base < 17)
		nbr_to_str((unsigned int)value, (unsigned int)base, &p);
	return (str);
}

int		validation(char *line)
{
	int i;
	int f;

	i = 0;
	f = 0;
	if (line[0] == '\0')
		return(f);
	else
	{
		while (line[i])
		{
			if (line[i] != '-' && line[i] != '+' && line[i] != ' ')
			{
				if (line[i] < '0' || line[i] > '9')
					return(f);
			}
			i++;
		}
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] != ' ')
			f++;
		if (line[i + 1] == '\0' && line[i] != ' ')
			f++;
		i++;
	}
	return(f);
}

int main(void)
{
    char	*line;
    char	*number;
    char	*base;
    int 	f, bs;
    char 	*res;

 	printf("Usage:\n[number] [base] (base >= 2 && base <= 16)\n");
	printf("Use q to exit\n");
	while ((get_next_line(0, &line)) > 0)
	{
		if ((f = validation(line) != 2) && line[0] != 'q')
			printf(RED"ERROR INPUT\n");
		else if ((line[0] >= '0' && line[0] <= '9') || line[0] == '-' || line[0] == '+')
		{
			number = get_figure(line, 1);
			base = get_figure(line, 2);
			bs = atoi(base);
			if (bs > 1 && bs <=16)
			{
				res = ft_itoa_base(atoi(number), atoi(base));
				printf("result = "GREEN"%s\n", res);
				free(res);
			}
			else
				printf(RED"ERROR INPUT\n");
		}
		else if (line[0] == 'q')
			break ;
		else
			printf(RED"ERROR INPUT\n");
		ft_strdel(&line);
		write(1, RESET, 5);
	}
    return(0);
}

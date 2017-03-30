#ifndef CONVERT_H
# define CONVERT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# define RED 	"\x1B[31m"
# define GREEN  "\x1B[32m"
# define RESET  "\x1B[0m"

char	*get_figure(char *line, int f);
void	nbr_to_str(unsigned int value, unsigned int base, char **str);
char	*ft_itoa_base(int value, int base);
int		validation(char *line);

#endif

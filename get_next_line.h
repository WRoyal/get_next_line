#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len, int flag);
int		len(char *str, char symb);
char	*ft_strchr(char *s, char c);
int		check(int retsym, char *buf, char *reaminder, int flag);
int		get_next_line(int fd, char **line);

#endif

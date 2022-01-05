#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

int	len(char *str, char symb)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != symb)
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len, int flag)
{
	int		i;
	char	*str;

	i = 0;
	if (len == 0 && flag == 1)
	{
		free(s);
		return (0);
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	while (s[start] && len > i)
		str[i++] = s[start++];
	if (flag == 1)
		free(s);
	str[i] = '\0';
	return (str);
}

int	check(int retsym, char *buf, char *ost, int flag)
{
	if (ost && flag)
	{
		free(ost);
		return (-1);
	}
	if (buf)
		free(buf);
	if (retsym > 0)
		return (1);
	if (retsym < 0)
		return (-1);
	return (retsym);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * (len(s2, '\0') + len(s1, '\0') + 1));
	if (!str)
	{
		free (str);
		return (0);
	}
	if (len(s2, '\0') + len(s1, '\0') > 0)
	{
		while (s1 && s1[k] != '\0')
			str[i++] = s1[k++];
		k = 0;
		while (s2 && s2[k] != '\0')
			str[i++] = s2[k++];
	}
	if (s1)
		free(s1);
	str[i] = '\0';
	return (str);
}

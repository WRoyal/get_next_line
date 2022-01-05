#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				retsym;
	static char		*ost;

	retsym = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || !line || fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (check(-1, buf, 0, 0));
	while (retsym)
	{
		if (ft_strchr(ost, '\n') != 0)
			break ;
		retsym = read(fd, buf, BUFFER_SIZE);
		if (retsym == -1)
			return (check(-1, buf, 0, 0));
		buf[retsym] = '\0';
		ost = ft_strjoin(ost, buf);
		if (!ost)
			return (check(-1, buf, 0, 0));
	}
	*line = ft_substr(ost, 0, len(ost, '\n'), 0);
	ost = ft_substr(ost, len(ost, '\n') + 1, len(ost, '\0') - len(ost, '\n'), 1);
	return (check(retsym, buf, ost, 0));
}

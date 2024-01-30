#include <stdlib.h>

int		ft_in_seperator(char c, char *charset)
{
	int i;

	i = 0;
	while (*(charset + i))
	{
		if (*(charset + i) == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_in_seperator(*str, charset))
			str++;
		if (*str && !ft_in_seperator(*str, charset))
		{
			count++;
			while (*str && !ft_in_seperator(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*alloc_word(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (*(str + i) && !ft_in_seperator(*(str + i), charset))
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*(str + i) && !ft_in_seperator(*(str + i), charset))
	{
		*(word + i) = *(str + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

char	**split(char *str, char *charset)
{
	char	**words;
	int		count;
	int		size;
	int		j;

	size = count_words(str, charset);
	if (!(words = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	count = 0;
	j = 0;
	while (*(str + j))
	{
		while (*(str + j) && ft_in_seperator(*(str + j), charset))
			j++;
		if (*(str + j) && !ft_in_seperator(*(str + j), charset))
		{
			if (!(words[count] = alloc_word((str + j), charset)))
				return (NULL);
			count++;
			while (*(str + j) && !ft_in_seperator(*(str + j), charset))
				str++;
		}
	}
	words[count] = NULL;
	return (words);
}


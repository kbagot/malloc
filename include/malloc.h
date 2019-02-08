#ifndef SHELL_H
#define SHELL_H


#include "../libft/libft.h"


typedef struct      s_allocs
{
	void			*content;
	size_t			content_size;
	struct s_allocs *next;
}                   t_allocs;

#endif
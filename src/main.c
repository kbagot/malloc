
#include "../include/malloc.h"
 #include <stdio.h>

#include <sys/mman.h>

t_allocs global = NULL;

//void *mmapStrdup(char *str) {
//
//char *nstr;
//size_t size = ft_strlen(str) + 1;
//nstr = ft_malloc(size);
//ft_strcpy(nstr, str);
//printf('Strdupmmmap, %s', nstr);
//}

void *ft_malloc(size_t size);

t_allocs *saveAllocs(char **addr, size_t size)
{
	t_allocs	*new;

	new = ft_malloc(sizeof(t_allocs));
	new->content = *addr;
//	printf("CONTENT ADDR : %p\n", new->content);
	new->content_size = size;
	new->next = NULL;
	return (new);
}

void *ft_malloc(size_t size){
char *addr;

addr = (char*)mmap(NULL, size, PROT_WRITE|PROT_READ, MAP_ANON|MAP_SHARED, -1, 0);
global++;

return (addr);
}

void *newPage(size_t size)
{
char *addr;

addr = ft_malloc(size);
saveAllocs(&addr, size);
return (addr);
}


int        main(int ac, char **av, char **env)
{
int i;
char *addr;

i = 0;
while (i < 1024)
{
addr = (char*)newPage(1024);
addr[0] = 42;
i++;
printf("lol %s [%d]", addr, i);
}
printf("PAGES:[%d]", global);


return (0);

}
#include "ft_printf.h"
#include <stdio.h>

// make && clangc main/main.c libftprintf.a -Iincludes && ./a.out
int main()
{
// 	{
// 		char s[] = "yo";
// 		int res = ft_printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);
// 		int res2 =   printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);
// 		printf("%d : %d\n\n", res, res2);
// 		fflush(stdout);
// 	}
// 	{
// 		char s[] = "yo";
// 		printf("%p | %s\n\n", s, ft_itoa_llu_base((unsigned long long)s, "0123456789abcdef"));
// 		fflush(stdout);
// 	}
// 	{
// 		int res = ft_printf("%");
// 		(void)res;
// //		int res2 =   printf("%");
// //		printf("%d : %d\n\n", res, res2);
// 		fflush(stdout);
// 	}
// 	{
// 		int res = ft_printf("");
// 		int res2 =   printf("");
// 		printf("%d : %d\n\n", res, res2);
// 		fflush(stdout);
// 	}
// 	{
// 		int res = ft_printf("%d, %i, %s, %c, %p, %%\n", 42, 42, "42", 42, NULL);
// 		int res2 =   printf("%d, %i, %s, %c, %p, %%\n", 42, 42, "42", 42, NULL);
// 		printf("%d : %d\n\n", res, res2);
// 		fflush(stdout);
// 	}
// 	{
// 		int res = ft_printf("%x, %X\n", 42, 42);
// 		int res2 =   printf("%x, %X\n", 42, 42);
// 		printf("%d : %d\n\n", res, res2);
// 		fflush(stdout);
// 	}
	{
		printf("\n==================\n%%c\n==================\n");
		int	res1 = ft_printf("Any letter %c", 't');
		printf(" : ");
		int	res2 =    printf("Any letter %c", 't');
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("\\0 char %c", '\0');
		printf(" : ");
		res2 =    printf("\\0 char %c", '\0');
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%s\n==================\n");
		int	res1 = ft_printf("Any %s", "Hello");
		printf(" : ");
		int	res2 =    printf("Any %s", "Hello");
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("Empty %s", "");
		printf(" : ");
		res2 =    printf("Empty %s", "");
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("NULL %s", NULL);
		printf(" : ");
		res2 =    printf("NULL %s", NULL);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%i\n==================\n");
		int	res1 = ft_printf("%i", -42);
		printf(" : ");
		int	res2 =    printf("%i", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%i", 0);
		printf(" : ");
		res2 =    printf("%i", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%i", 2147483647);
		printf(" : ");
		res2 =    printf("%i", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%i", -2147483648);
		printf(" : ");
		res2 =    printf("%i", (int)-2147483648);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%i", 42);
		printf(" : ");
		res2 =    printf("%i", 42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%d\n==================\n");
		int	res1 = ft_printf("%d", -42);
		printf(" : ");
		int	res2 =    printf("%d", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", 0);
		printf(" : ");
		res2 =    printf("%d", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", 2147483647);
		printf(" : ");
		res2 =    printf("%d", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", -2147483648);
		printf(" : ");
		res2 =    printf("%d", (int)-2147483648);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", 42);
		printf(" : ");
		res2 =    printf("%d", 42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%p\n==================\n");
		char p[1];
		int	res1 = ft_printf("%p", p);
		printf(" : ");
		int	res2 =    printf("%p", p);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%p", NULL);
		printf(" : ");
		res2 =    printf("%p", NULL);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%%%\n==================\n");
		int	res1 = ft_printf("%%");
		printf(" : ");
		int	res2 =    printf("%%");
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%u\n==================\n");
		int	res1 = ft_printf("%u", 0);
		printf(" : ");
		int	res2 =    printf("%u", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%u", 2147483647);
		printf(" : ");
		res2 =    printf("%u", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%u", 2147483650);
		printf(" : ");
		res2 =    printf("%u", (unsigned)2147483650);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%u", -1);
		printf(" : ");
		res2 =    printf("%u", -1);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%x\n==================\n");
		int	res1 = ft_printf("%x", 0);
		printf(" : ");
		int	res2 =    printf("%x", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%x", 42);
		printf(" : ");
		res2 =    printf("%x", 42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%x", -42);
		printf(" : ");
		res2 =    printf("%x", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%x", 2147483647);
		printf(" : ");
		res2 =    printf("%x", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%x", -2147483648);
		printf(" : ");
		res2 =    printf("%x", (unsigned int)-2147483648);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%X\n==================\n");
		int	res1 = ft_printf("%X", 0);
		printf(" : ");
		int	res2 =    printf("%X", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%X", 42);
		printf(" : ");
		res2 =    printf("%X", 42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%X", -42);
		printf(" : ");
		res2 =    printf("%X", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%X", 2147483647);
		printf(" : ");
		res2 =    printf("%X", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%X", -2147483648);
		printf(" : ");
		res2 =    printf("%X", (unsigned int)-2147483648);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
}

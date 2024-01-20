#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/* How to test:
$make
$cc -Wall -Wextra -Werror -o test test_p1.c -L. -lft
$./test <function_name>

P.S.
-L. tells the linker to look for libraries in the current directory, 
and -lmylib links with "libmylib.a" (or "mylib.lib" on Windows).
*/

typedef int (*FunctionCallback)(int);
FunctionCallback int_ft_functions[] = {&ft_isalpha,
								&ft_isdigit,
								&ft_isalnum,
								&ft_isascii,
								&ft_isprint,
								&ft_toupper,
								&ft_tolower};

typedef int (*FunctionCallback)(int);
FunctionCallback int_orig_functions[] = {&isalpha, 
								&isdigit,
								&isalnum,
								&isascii,
								&isprint,
								&toupper,
								&tolower};

// write a function for strcmp(function_name, "isalpha"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *function_name = argv[1];

		if (!strcmp(function_name, "isalpha")
				|| !strcmp(function_name, "isdigit")
				|| !strcmp(function_name, "isalnum")
				|| !strcmp(function_name, "isascii")
				|| !strcmp(function_name, "isprint")
				|| !strcmp(function_name, "toupper")
				|| !strcmp(function_name, "tolower"))
		{
			int var = 97;
			const int	funcs_num = 7;
			char	*funcs_names[funcs_num] = {"isalpha",
							"isdigit",
							"isalnum",
							"isascii",
							"isprint",
							"toupper",
							"tolower"};
			int i = 0;
			printf("\nVariable: %d or %c\n\n", var, var);
			while (i < funcs_num)
			{
				printf("Function: %s, Result: %d", 
						funcs_names[i], int_ft_functions[i](var));
				if (strcmp(funcs_names[i], "toupper") == 0 || strcmp(funcs_names[i], "tolower") == 0)
					printf(" or %c", int_ft_functions[i](var));
				if (int_ft_functions[i](var) == int_orig_functions[i](var))
					printf("\nSUCCESS: original and ft results matched!\n\n");
				else
					printf("\nFAIL: check your ft function.\n\n");
				i++;
			}
		}
		else if (!strcmp(function_name, "strlen"))
		{
			printf("Length of 'meow': %d\n", ft_strlen("meow"));
		}
		// this does not work due to (BUS ERROR: 10):
		//printf("Before: meow\n After: %s\n", ft_memset("meow", 43, 3));
		// this works! :
		else if (!strcmp(function_name, "memset"))
		{
			char *str;
			str = strdup("hello");
			ft_memset(str, '!', 3);
			printf("%s\n", str);
		}
		else if (!strcmp(function_name, "bzero"))
		{
			char *str;
			str = strdup("hello");
			ft_bzero(str, 3);
			printf("ft_bzero: %s\n", str);
			/////
			char *str2;
			str2 = strdup("hello");
			bzero(str2, 1);
			printf("bzero: %s\n", str2);
		}
		else if (!strcmp(function_name, "memcpy"))
		{
			// char src[] = "no";
			// char dst[] = "yes";
			// printf("src [%s]; dest [%s]\n", src, dst);
			// ft_memcpy(dst, src, 2);
			// printf("ft_memcpy [%s]\n", dst);

			// char src2[] = "no";
			// char dst2[] = "yes";
			char data[6] = "Privet";
			char *src2 = data;
			char *dst2 = data + 2;
			ft_memcpy(dst2, src2, 3);
			printf("memcpy [%s]\n", data);
		}
		else if (!strcmp(function_name, "memmove"))
		{
			// char src[] = "abcd";
			// char dst[] = "cd000";
			// printf("src [%s]; dest [%s]\n", src, dst);
			// ft_memcpy(dst, src, 2);
			// printf("ft_memcpy [%s]\n", dst);


			// char data[6] = "Privet";
			// char *src2 = data;
			// char *dst2 = data + 2;
			// ft_memmove(dst2, src2, 3);
			// printf("memmove [%s]\n", data);
			char string [] = "stackoverflow";
			char *first, *second;
			first = string;
			second = string;

			puts(string);
			memcpy(first+5, first, 5);
			puts(first);
			memmove(second+5, second, 5);
			puts(second);
		}
		else if (!strcmp(function_name, "strlcpy"))
		{
			char	*src = "Office";
			char	dst[20];
			size_t	n = 6;
			printf("ft_strlcpy: (%s), (%lu)\n", dst, ft_strlcpy(dst, src, n));
			printf("strlcpy: (%s), (%lu)\n", dst, strlcpy(dst, src, n));
		}
		else if (!strcmp(function_name, "strlcat"))
		{
			// char	*src = "Office";
			// char	dst[50] = "Best series: ";
			char *src = "test12345";
			char dst[50] = "aaaaaaaaaa\0\0\0\0\0\0\0\0\0\0";
			printf("ft_strlcat: (%s), (%lu)\n", dst, ft_strlcat(dst, src, 20));

			// char	*src2 = "Office";
			// char	dst2[50] = "Best series: ";
			char *src2 = "test12345";
			char dst2[50] = "aaaaaaaaaa\0\0\0\0\0\0\0\0\0\0";
			printf("strlcat: (%s), (%lu)\n", dst2, strlcat(dst2, src2, 20));
		}
		else if (!strcmp(function_name, "strchr"))
		{
			// const int c = '.';
			// const char str[] = "hfbj.12.=-+";
			// const int c = '\0';
			// const char str[] = "potatoes";
			const int c = 'a' + 256;
			const char str[] = "abc";
			// const int c = '\0';
			// void *str = NULL;
			
			const char *ret;
			ret = strchr(str, c);
			printf("strchr: (%s)\n", ret);

			const char *ft_ret;
			ft_ret = ft_strchr(str, c);
			printf("ft_strchr: (%s)\n", ft_ret);
		}
		else if (!strcmp(function_name, "strrchr"))
		{
			// const int c = '.';
			// const char str[] = "h.12.=-+";
			// const int c = '\0';
			// const char str[] = "potatoes";
			// const int c = 'a' + 256;
			// const char str[] = "abc";
			const int c = '4';
			const char str[] = "4321";

			// this case below does not work (segmentation fault: 11) - fix this!
			// const int c = '\0';
			// void *str = NULL;

			const char *ret;
			ret = strrchr(str, c);
			printf("strrchr: (%s)\n", ret);

			const char *ft_ret;
			ft_ret = ft_strrchr(str, c);
			printf("ft_strrchr: (%s)\n", ft_ret);
			if (ret == ft_ret)
			{
				printf("OK!\n");
			}
			else
				printf("WRONG...\n");
		}
		else if (!strcmp(function_name, "strncmp"))
		{
			char *s1 = "test?";
			char *s2 = "test\0";
			printf("ft_strncmp: (%d)\n", ft_strncmp(s1, s2, 6));
			printf("strncmp: (%d)\n", strncmp(s1, s2, 6));
		}
		else if (!strcmp(function_name, "memchr"))
		{
			const int c = '.';
			const char str[] = "hfbj.12.=-+";
			size_t n = 9;
			// const int c = '\0';
			// const char str[] = "potatoes";
			
			const char *ret;
			ret = memchr(str, c, n);
			printf("memchr: (%s)\n", ret);

			const char *ft_ret;
			ft_ret = ft_memchr(str, c, n);
			printf("ft_memchr: (%s)\n", ft_ret);
		}
		else if (!strcmp(function_name, "memcmp"))
		{
			const char *s1 = "ABC";
			const char *s2 = "ABD";
			size_t n = 6;
			// const char *s1 = "test?";
			// const char *s2 = "test\0";
			printf("ft_memcmp: (%d)\n", ft_memcmp(s1, s2, n));
			printf("memcmp: (%d)\n", memcmp(s1, s2, n));
		}
		else if (!strcmp(function_name, "strnstr"))
		{
			char	*str = "Code, Sleep, Repeat or just Sleep?";
			char	*substr = "eep";
			printf("ft_strnstr: (%s)\n", ft_strnstr(str, substr, 100));
			printf("strnstr: (%s)\n", strnstr(str, substr, 100));
		}
		else if (!strcmp(function_name, "atoi"))
		{
			char	*str = " 	-2147483649a";
			printf("ft_atoi: (%d)\n", ft_atoi(str));
			printf("atoi: (%d)\n", atoi(str));
		}
		else if (!strcmp(function_name, "calloc"))
		{
			int* ptr;
			int n, i;

			// Get the number of elements for the array
			n = 5;
			printf("Enter number of elements: %d\n", n);
			ptr = (int*)ft_calloc(n, sizeof(int));
 
			// Check if the memory has been successfully
			// allocated by calloc or not
			if (ptr == NULL) {
				printf("Memory not allocated.\n");
				exit(0);
			}
			else {

				// Memory has been successfully allocated
				printf("Memory successfully allocated using calloc.\n");

				// Get the elements of the array
				for (i = 0; i < n; ++i) {
					ptr[i] = i + 1;
				}

				// Print the elements of the array
				printf("The elements of the array are: ");
				for (i = 0; i < n; ++i) {
					printf("%d, ", ptr[i]);
				}
			}
		}
	}
	return (0);
}
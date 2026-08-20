//#include "mandatory/ft_printf.h"
#include "bonus/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

// int main()
// {
//     char c = 'k'; // %c
//     char *str = "String test"; // %s
    
//     int nbr = -5;// %d // %i
// 	int *var; var = &nbr;// %p
//     unsigned int nbrr = 20;// %u
//     int b= 0xffffffff;// %x // %X
//     // %%
//     int i;
// 	ft_printf("He%clo\n%s!\n%x\n%%", 'l', "World", -42);
//     printf("\n\nPrintf replica:\n");
//     i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\
// 	\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\
// 	\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\
// 	\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
//     printf("\nReturn Value: %d", i);
//     ///////////////////////////////
//     printf("\nPrintf original:\n");
//     i = printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\
// 	\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\
// 	\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\
// 	\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
//     printf("\nReturn Value: %d\n", i);
//     return (0);
// }


/* ANSI Color Codes for Scannable Test Results */
#define RESET "\033[0m"
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define BOLD  "\033[1m"

static void run_test(const char *test_name, int (*test_fn)(void))
{
	printf(BLUE BOLD "\n========================================\n" RESET);
	printf(BLUE BOLD " TEST: %s\n" RESET, test_name);
	printf(BLUE BOLD "========================================\n" RESET);
	test_fn();
}

/* -------------------------------------------------------------------------- */
/* 1. BASIC CONVERSIONS & NUMERIC LIMITS                                      */
/* -------------------------------------------------------------------------- */
static void test_basics(void)
{
	int ft_ret, std_ret;
	int sample_var = 42;

	printf("--- Basic Int & Unsigned ---\n");
	ft_ret  = ft_printf_bonus("ft_printf_bonus  : [%d] [%i] [%u]\n", 42, -42, 4294967295U);
	std_ret =    printf("std_printf : [%d] [%i] [%u]\n", 42, -42, 4294967295U);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Hexadecimal Lower / Upper ---\n");
	ft_ret  = ft_printf_bonus("ft_printf_bonus  : [%x] [%X] [%x]\n", 255, 255, 0);
	std_ret =    printf("std_printf : [%x] [%X] [%x]\n", 255, 255, 0);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Integer Boundary Limits ---\n");
	ft_ret  = ft_printf_bonus("ft_printf_bonus  : [%d] [%d]\n", INT_MAX, INT_MIN);
	std_ret =    printf("std_printf : [%d] [%d]\n", INT_MAX, INT_MIN);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Pointers (%p) ---\n");
	ft_ret  = ft_printf_bonus("ft_printf_bonus  : [%p] [%p]\n", &sample_var, (void *)-1);
	std_ret =    printf("std_printf : [%p] [%p]\n", &sample_var, (void *)-1);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 2. FLAGS (+, space, #, -, 0)                                              */
/* -------------------------------------------------------------------------- */
static void test_flags(void)
{
	printf("--- Plus (+) & Space (' ') Flags ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%+d] [%+d] [% d] [% d]\n", 42, -42, 42, -42);
	   printf("std_printf : [%+d] [%+d] [% d] [% d]\n", 42, -42, 42, -42);

	printf("\n--- Plus vs Space Priority Check (%+ d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%+ d]\n", 42);
	   printf("std_printf : [%+ d]\n", 42);

	printf("\n--- Hash Flag (#) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%#x] [%#X] [%#x]\n", 255, 255, 0);
	   printf("std_printf : [%#x] [%#X] [%#x]\n", 255, 255, 0);

	printf("\n--- Left-Justify (-) vs Zero Padding (0) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%-10d] [%010d] [%010d]\n", 42, 42, -42);
	   printf("std_printf : [%-10d] [%010d] [%010d]\n", 42, 42, -42);

	printf("\n--- Zero Pad + Hash Flag (%010#x) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%010#x]\n", 255);
	   printf("std_printf : [%010#x]\n", 255);
}

/* -------------------------------------------------------------------------- */
/* 3. WIDTH & PRECISION EDGE CASES                                            */
/* -------------------------------------------------------------------------- */
static void test_precision_width(void)
{
	printf("--- Precision Padding (%.5d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%.5d] [%.2d]\n", 42, 12345);
	   printf("std_printf : [%.5d] [%.2d]\n", 42, 12345);

	printf("\n--- Zero-Precision on Zero (%.0d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%.0d] [%.d]\n", 0, 0);
	   printf("std_printf : [%.0d] [%.d]\n", 0, 0);

	printf("\n--- Width + Zero Precision (%5.0d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%5.0d] [%#5.0x]\n", 0, 0);
	   printf("std_printf : [%5.0d] [%#5.0x]\n", 0, 0);

	printf("\n--- Width + Precision + Signs (%10.5d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%10.5d] [%10.5d]\n", 42, -42);
	   printf("std_printf : [%10.5d] [%10.5d]\n", 42, -42);

	printf("\n--- 0 Flag Ignored When Precision Is Present (%010.5d) ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%010.5d]\n", 42);
	   printf("std_printf : [%010.5d]\n", 42);
}

/* -------------------------------------------------------------------------- */
/* 4. POINTER SPECIFIC EDGE CASES                                             */
/* -------------------------------------------------------------------------- */
static void test_pointers(void)
{
	printf("--- NULL Pointer Handling ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%p]\n", NULL);
	   printf("std_printf : [%p]\n", NULL);

	printf("\n--- NULL Pointer Width & Alignment ---\n");
	ft_printf_bonus("ft_printf_bonus  : [%10p] [%-10p]\n", NULL, NULL);
	   printf("std_printf : [%10p] [%-10p]\n", NULL, NULL);
}

int main(void)
{
	run_test("Basic Conversions & Limits", (int (*)(void))test_basics);
	run_test("Flags (+, space, #, -, 0)", (int (*)(void))test_flags);
	run_test("Width & Precision", (int (*)(void))test_precision_width);
	run_test("Pointers (%p Edge Cases)", (int (*)(void))test_pointers);

	printf(GREEN BOLD "\n[+] Test suite execution finished.\n" RESET);
	return (0);
}
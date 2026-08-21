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

static void run_test(const char *test_name, void (*test_fn)(void))
{
	printf(BLUE BOLD "\n========================================\n" RESET);
	printf(BLUE BOLD " TEST: %s\n" RESET, test_name);
	printf(BLUE BOLD "========================================\n" RESET);
	test_fn();
}

/* -------------------------------------------------------------------------- */
/* 1. CHAR (%c) & PERCENT (%%) CONVERSIONS                                     */
/* -------------------------------------------------------------------------- */
static void test_char_and_percent(void)
{
	int ft_ret, std_ret;

	printf("--- Basic Char & Percent ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%c] [%c] [%%]\n", 'a', 'Z');
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%c] [%c] [%%]\n", 'a', 'Z');
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Null Character ('\\0') ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%c]\n", '\0');
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%c]\n", '\0');
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Char Width & Alignment ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%5c] [%-5c]\n", 'x', 'x');
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%5c] [%-5c]\n", 'x', 'x');
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 2. STRING (%s) CONVERSIONS                                                 */
/* -------------------------------------------------------------------------- */
static void test_strings(void)
{
	int ft_ret, std_ret;
	char *str = "Hello, 42!";

	printf("--- Basic Strings ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%s] [%s]\n", str, "");
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%s] [%s]\n", str, "");
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- String Width & Alignment ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%20s] [%-20s]\n", str, str);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%20s] [%-20s]\n", str, str);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- String Precision (Truncation) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%.5s] [%.0s]\n", str, str);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%.5s] [%.0s]\n", str, str);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- String Width + Precision ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%10.5s] [%-10.5s]\n", str, str);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%10.5s] [%-10.5s]\n", str, str);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- NULL String Pointer ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%s] [%10s] [%.3s]\n", (char *)NULL, (char *)NULL, (char *)NULL);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%s] [%10s] [%.3s]\n", (char *)NULL, (char *)NULL, (char *)NULL);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 3. BASIC NUMERIC CONVERSIONS & LIMITS (%d, %i, %u, %x, %X)                 */
/* -------------------------------------------------------------------------- */
static void test_basics(void)
{
	int ft_ret, std_ret;
	int sample_var = 42;

	printf("--- Basic Int & Unsigned ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%d] [%i] [%u]\n", 42, -42, 4294967295U);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%d] [%i] [%u]\n", 42, -42, 4294967295U);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Hexadecimal Lower / Upper ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%x] [%X] [%x]\n", 255, 255, 0);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%x] [%X] [%x]\n", 255, 255, 0);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Integer Boundary Limits ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%d] [%d]\n", INT_MAX, INT_MIN);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%d] [%d]\n", INT_MAX, INT_MIN);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Pointers (%%p) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%p] [%p]\n", &sample_var, (void *)-1);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%p] [%p]\n", &sample_var, (void *)-1);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 4. FLAGS (+, space, #, -, 0)                                              */
/* -------------------------------------------------------------------------- */
static void test_flags(void)
{
	int ft_ret, std_ret;

	printf("--- Plus (+) & Space (' ') Flags ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%+d] [%+d] [% d] [% d]\n", 42, -42, 42, -42);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%+d] [%+d] [% d] [% d]\n", 42, -42, 42, -42);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Plus vs Space Priority Check (%%+d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%+d]\n", 42);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%+d]\n", 42);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Hash Flag (#) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%#x] [%#X] [%#x]\n", 255, 255, 0);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%#x] [%#X] [%#x]\n", 255, 255, 0);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Left-Justify (-) vs Zero Padding (0) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%-10d] [%010d] [%010d]\n", 42, 42, -42);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%-10d] [%010d] [%010d]\n", 42, 42, -42);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Zero Pad + Hash Flag (%%#010x) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%#010x]\n", 255);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%#010x]\n", 255);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 5. NUMERIC WIDTH & PRECISION EDGE CASES                                     */
/* -------------------------------------------------------------------------- */
static void test_precision_width(void)
{
	int ft_ret, std_ret;

	printf("--- Precision Padding (%%.5d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%.5d] [%.2d]\n", 42, 12345);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%.5d] [%.2d]\n", 42, 12345);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Zero-Precision on Zero (%%.0d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%.0d] [%.d]\n", 0, 0);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%.0d] [%.d]\n", 0, 0);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Width + Zero Precision (%%5.0d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%5.0d] [%#5.0x]\n", 0, 0);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%5.0d] [%#5.0x]\n", 0, 0);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- Width + Precision + Signs (%%10.5d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%10.5d] [%10.5d]\n", 42, -42);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%10.5d] [%10.5d]\n", 42, -42);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- 0 Flag Ignored When Precision Is Present (%%010.5d) ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%010.5d]\n", 42);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%010.5d]\n", 42);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

/* -------------------------------------------------------------------------- */
/* 6. POINTER SPECIFIC EDGE CASES (%p)                                        */
/* -------------------------------------------------------------------------- */
static void test_pointers(void)
{
	int ft_ret, std_ret;

	printf("--- NULL Pointer Handling ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%p]\n", NULL);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%p]\n", NULL);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);

	printf("\n--- NULL Pointer Width & Alignment ---\n");
	printf("ft_printf_bonus  : ");
	fflush(stdout);
	ft_ret  = ft_printf_bonus("[%10p] [%-10p]\n", NULL, NULL);
	printf("std_printf : ");
	fflush(stdout);
	std_ret =    printf("[%10p] [%-10p]\n", NULL, NULL);
	printf("Return -> ft: %d | std: %d\n", ft_ret, std_ret);
}

int main(void)
{
	run_test("Char (%c) & Percent (%%)", test_char_and_percent);
	run_test("String (%s)", test_strings);
	run_test("Basic Conversions & Limits (%d, %i, %u, %x, %X)", test_basics);
	run_test("Flags (+, space, #, -, 0)", test_flags);
	run_test("Width & Precision", test_precision_width);
	run_test("Pointers (%p Edge Cases)", test_pointers);

	printf(GREEN BOLD "\n[+] Test suite execution finished.\n" RESET);
	return (0);
}

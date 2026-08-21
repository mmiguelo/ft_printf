*This project has been created as part of the 42 curriculum by mmiguelo.*

# ft_printf

## Description

This project is a custom implementation of the standard C function `printf`. The goal is to reproduce the essential behavior of formatted output while handling variadic arguments, parsing a format string, and writing the result to the standard output.

The project is a classic 42 exercise: it teaches how to work with variadic functions, how format strings are parsed, how different data types are converted into text, and how the return value of `printf` is computed.

### Mandatory part

The mandatory version implements the core conversions expected from a basic `printf` clone:

- `%c` for a single character
- `%s` for a string
- `%p` for a pointer address
- `%d` and `%i` for signed integers
- `%u` for unsigned integers
- `%x` and `%X` for hexadecimal output
- `%%` for a literal percent sign

The function returns the total number of characters printed, matching the behavior of the real `printf` for the supported cases.

### Bonus part

The bonus version extends the parser with additional formatting features inspired by the real `printf` behavior. It adds support for:

- `-`, `0`, `#`, `+`, and space flags
- minimum field width
- precision using `.`
- better handling of signed/unsigned numeric formatting and padding rules

This part keeps the same core design but introduces a more structured parsing step and a dedicated format state so more advanced formatting rules can be applied without losing clarity.

## Algorithm and data structures

The mandatory version follows a simple and effective flow. The function walks through the format string from left to right. When it encounters a normal character, it is written directly to the output. When it encounters `%`, it reads the following character as a conversion specifier and dispatches the matching printing function.

Each conversion function is responsible for converting a value into a string and writing it to the standard output using `write()`. The total number of printed characters is accumulated and returned at the end. This is the key behavior that makes the function compatible with the standard `printf` contract.

The heart of the algorithm is therefore a parser-dispatch model:

1. scan the format string
2. detect a conversion marker `%`
3. select the correct output function from the specifier
4. convert the associated argument to text
5. write the text and increment the counter
6. continue until the whole string is processed

This pattern is easy to reason about and reliable in a 42 context because it is direct, modular, and explicit.

In the bonus version, the parser becomes more structured. A `t_format` structure stores the current conversion state, including:

- active flags
- width value
- precision value
- conversion specifier

The parsing happens in stages:

1. parse flags
2. parse width if present
3. parse precision if present
4. parse the specifier
5. resolve flag conflicts and precedence
6. dispatch to the correct output function

This data structure is useful because formatting is not independent from one field to another. For example, precision and width both affect numeric output, and some flags must be ignored or prioritized depending on the specifier. The code resolves these cases before printing so the final output matches the expected formatting rules as closely as possible.

For numeric values, the implementation uses base-aware conversion. Integers are converted by repeated division using a digit table, while hexadecimal values choose either lowercase or uppercase characters depending on the conversion. Padding is handled separately so width and precision remain consistent and predictable.

This design is robust because it separates parsing, conversion, and formatting into distinct responsibilities. The parser decides what to do, the conversion functions produce the text, and the padding logic manages alignment and spacing.

## Instructions

### Requirements

- A Unix-like environment
- `make`
- `cc` or `gcc`
- the local `libft` project available in the repository

### Mandatory compilation

From the project root, run:

```bash
make
```

This builds the static library `libftprintf.a`.

### Bonus compilation

```bash
make bonus
```

### Cleaning up

```bash
make clean
make fclean
make re
```

### Example test compilation

```bash
cc -Wall -Wextra -Werror -Imandatory -Ibonus -I. main.c ./libftprintf.a -o test
./test
```

## Usage

A simple example of use is:

```c
#include "mandatory/ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Integer: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42u);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", (void *)0x1234);
    return (0);
}
```

The bonus version supports formatting modifiers such as width and precision, for example:

```c
ft_printf_bonus("[%10.5s] [%-10.5s] [%#x]\n", "Hello", "Hello", 255);
```

## Resources

### References

- C library documentation for `printf`
- `man 3 printf`
- tutorials covering variadic functions, width/precision rules, and hexadecimal conversions
- documentation on pointer formatting and signed/unsigned integer conversion

### AI usage

AI tools were used mainly to support the development process in a few specific areas:

- checking the behavior of edge cases for signed and unsigned integers
- validating the correct parsing of flags, width, and precision in the bonus version
- reviewing how formatting rules should interact between `-`, `0`, `+`, and space flags
- helping debug conversion and padding logic for `%x`, `%X`, `%p`, and `%s`
- comparing the project output against the expected semantics of the standard `printf`

The AI was used as a support tool for reasoning and debugging, not as a substitute for understanding the project itself. The final implementation was adapted and validated by the author according to the constraints of the 42 assignment.

## Notes

This project is meant to strengthen fundamental C skills while staying within the rules and scope of the 42 curriculum. It is especially valuable for learning how variable arguments are handled, how text formatting is parsed, and how low-level output functions can be used to produce reliable formatted strings.


</div>

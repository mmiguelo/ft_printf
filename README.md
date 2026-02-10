<a id="readme-top"></a>

<div align="center">

# 🖨️ ft_printf

**A custom implementation of the C `printf` function | 42 School Project**

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norm-OK-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

---

*Because `write()` alone just isn't enough — a variadic function that handles formatted output to stdout.*

</div>

---

## 📖 Table of Contents

- [About](#-about)
- [Supported Specifiers](#-supported-specifiers)
- [Function Prototype](#-function-prototype)
- [How It Works](#%EF%B8%8F-how-it-works)
- [Project Files](#-project-files)
- [Helper Functions](#-helper-functions)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#-usage)
- [Examples](#-examples)
- [Author](#-author)

---

## 🧠 About

**ft_printf** is a reimplementation of the standard C library function `printf(3)`. It parses a format string, processes variadic arguments, and writes formatted output to `stdout` — returning the total number of characters printed.

This project is a key milestone in the 42 curriculum, reinforcing:

- **Variadic functions** (`va_start`, `va_arg`, `va_end`)
- **Type dispatching** based on format specifiers
- Recursive algorithms for **number-to-string** conversion (decimal, hex, pointer)
- Building a **static library** (`.a`) with `ar` and `ranlib`
- Integration with a previously built **libft**

---

## 🔣 Supported Specifiers

<div align="center">

| Specifier | Description | Example Input | Example Output |
|:---------:|:------------|:--------------|:---------------|
| `%c` | Single character | `'A'` | `A` |
| `%s` | String | `"Hello"` | `Hello` |
| `%p` | Pointer address | `&var` | `0x7ffeeb4c` |
| `%d` | Signed decimal integer | `-42` | `-42` |
| `%i` | Signed integer (same as `%d`) | `42` | `42` |
| `%u` | Unsigned decimal integer | `4294967295` | `4294967295` |
| `%x` | Hexadecimal (lowercase) | `255` | `ff` |
| `%X` | Hexadecimal (uppercase) | `255` | `FF` |
| `%%` | Literal percent sign | — | `%` |

</div>

---

## 🔧 Function Prototype

```c
int  ft_printf(const char *str, ...);
```

| Parameter | Description |
|:----------|:------------|
| `str` | Format string containing text and `%` specifiers |
| `...` | Variadic arguments matching each specifier |
| **Return** | Total number of characters printed, or `-1` on error |

> Behaves identically to `printf(3)` for the supported conversions.

---

## ⚙️ How It Works

```
 ft_printf("Hello %s, you are %d years old!\n", name, age)
     │
     ▼
┌──────────────────────────────────────────────────┐
│              Parse format string                 │
│                                                  │
│   'H' 'e' 'l' 'l' 'o' ' '  → write directly      │
│                                                  │
│   '%s'  → call ft_putstr(va_arg)                 │
│                                                  │
│   ','  ' ' 'y' 'o' 'u' ...  → write directly     │
│                                                  │
│   '%d'  → call ft_putnbr(va_arg)                 │
│                                                  │
│   '!' '\n'               → write directly        │
└──────────────────────────────────────────────────┘
     │
     ▼
  Returns: total characters written
```

1. Iterate through the format string character by character
2. On regular characters → write directly to `stdout`
3. On `%` → read the next character as a **specifier**
4. Dispatch to the matching helper function via `print_args()`
5. Each helper returns the number of characters it printed
6. Accumulate and return the **total count**

---

## 📂 Project Files

```
ft_printf/
├── 📄 Makefile              # Build system (produces libftprintf.a)
├── 📖 README.md
├── ft_printf.h              # Header: prototypes & includes
├── ft_printf.c              # Core: format parsing & specifier dispatch
├── ft_putchar.c             # %c  — single character
├── ft_putstr.c              # %s  — string (handles NULL)
├── ft_putnbr.c              # %d %i — signed integer (uses ft_itoa)
├── ft_pututoa.c             # %u  — unsigned integer
├── ft_puthex.c              # %x %X — hexadecimal (lower/upper)
├── ft_putptr.c              # %p  — pointer address (0x prefix)
└── libft/                   # Custom C library dependency
    ├── libft.h
    ├── Makefile
    └── *.c                  # 40+ utility functions
```

---

## 🔗 Helper Functions

Each specifier is handled by a dedicated function:

| Function | Specifier | Strategy |
|:---------|:---------:|:---------|
| `ft_putchar` | `%c` | Direct `write()` of a single byte |
| `ft_putstr` | `%s` | Iterates and writes each char; prints `(null)` for `NULL` |
| `ft_putnbr` | `%d` `%i` | Converts via `ft_itoa` from libft, then prints the string |
| `ft_pututoa` | `%u` | Manual unsigned-to-string conversion with `malloc` |
| `ft_puthex` | `%x` `%X` | Recursive division by 16 using `"0123456789abcdef"` or uppercase base |
| `ft_putptr` | `%p` | Prints `0x` prefix + recursive hex of the `unsigned long` address; `(nil)` for `NULL` |

> All functions return the number of characters printed for accurate count tracking.

---

## 🚀 Getting Started

### Prerequisites

- **GCC** or **CC** compiler
- **Make**

### Installation

```bash
# Clone the repository
git clone https://github.com/mmiguelo/ft_printf.git
cd ft_printf

# Build the library
make
```

This produces `libftprintf.a` — a static library ready to link.

---

## 🎯 Usage

### Compiling with your project

```bash
# Compile your program linking ft_printf and libft
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

### Including in your code

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

---

## 💡 Examples

```c
// Characters and strings
ft_printf("Char: %c\n", 'A');              // Char: A
ft_printf("String: %s\n", "Hello");        // String: Hello
ft_printf("Null: %s\n", NULL);             // Null: (null)

// Numbers
ft_printf("Decimal: %d\n", -42);           // Decimal: -42
ft_printf("Unsigned: %u\n", 4294967295);   // Unsigned: 4294967295

// Hexadecimal
ft_printf("Lower: %x\n", 255);            // Lower: ff
ft_printf("Upper: %X\n", 255);            // Upper: FF

// Pointer
ft_printf("Ptr: %p\n", &var);             // Ptr: 0x7ffeeb4c

// Escape percent
ft_printf("100%%\n");                      // 100%

// Return value = number of characters printed
int n = ft_printf("Hi!\n");               // prints "Hi!\n", n = 4
```

---

## 🛠️ Makefile Targets

| Command | Description |
|:--------|:------------|
| `make` | Build `libftprintf.a` (includes libft) |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and library |
| `make re` | Full recompile |

---

## 👤 Author

**mmiguelo** — 42 Student

[![GitHub](https://img.shields.io/badge/GitHub-mmiguelo-181717?style=for-the-badge&logo=github)](https://github.com/mmiguelo)

---

<div align="center">

*Made with ❤️ at 42*

<p>(<a href="#readme-top">⬆️ back to top</a>)</p>

</div>

```markdown
# ft_printf 🚀
A reimplementation of the standard C library's `printf` function.

This project provides a custom implementation of `printf`, offering a deeper understanding of variadic functions and formatted output.

![License](https://img.shields.io/github/license/mmiguelo/ft_printf)
![GitHub stars](https://img.shields.io/github/stars/mmiguelo/ft_printf?style=social)
![GitHub forks](https://img.shields.io/github/forks/mmiguelo/ft_printf?style=social)
![GitHub issues](https://img.shields.io/github/issues/mmiguelo/ft_printf)
![GitHub pull requests](https://img.shields.io/github/issues-pr/mmiguelo/ft_printf)
![GitHub last commit](https://img.shields.io/github/last-commit/mmiguelo/ft_printf)

![C Badge](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=white)

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Quick Start](#quick-start)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Testing](#testing)
- [License](#license)
- [Support](#support)
- [Acknowledgments](#acknowledgments)

## About

`ft_printf` is a project aimed at recreating the functionality of the `printf` function from the standard C library. This project serves as an excellent exercise in understanding variadic functions, string parsing, and formatted output in C. It allows users to delve into the inner workings of a fundamental function used extensively in C programming.

This project is primarily intended for students learning C programming, developers who want to understand the implementation details of `printf`, and anyone interested in contributing to a low-level C library. It provides a hands-on experience in memory management, string manipulation, and argument handling. The core technology used is the C programming language, focusing on standard library functions and system calls for output.

The unique selling point of `ft_printf` is its educational value. It's not just about replicating `printf`; it's about understanding how it works and implementing it from scratch. This project provides a solid foundation for more advanced C programming concepts.

## ✨ Features

- 🎯 **Format Specifiers**: Supports common `printf` format specifiers such as `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%p`.
- ⚡ **Efficiency**: Optimized for performance, ensuring minimal overhead.
- 🛠️ **Customizable**: Designed to be easily extensible with additional format specifiers or features.
- 🔒 **Safe**: Implements checks to prevent common vulnerabilities such as buffer overflows.

## 🚀 Quick Start

Clone and compile the project:

```bash
git clone https://github.com/mmiguelo/ft_printf.git
cd ft_printf
make
```

Then, include the header file in your C program and use the `ft_printf` function.

## 📦 Installation

### Prerequisites
- GCC or another C compiler
- Make

### Steps

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/mmiguelo/ft_printf.git
    cd ft_printf
    ```

2.  **Compile the library:**

    ```bash
    make
    ```

    This will create a `libftprintf.a` file.

3.  **Include the header file in your project:**

    ```c
    #include "ft_printf.h"
    ```

4.  **Link the library when compiling your project:**

    ```bash
    gcc your_program.c -L. -lftprintf -o your_program
    ```

## 💻 Usage

```c
#include <stdio.h>
#include "ft_printf.h"

int main() {
    int num = 42;
    char *str = "Hello, world!";

    ft_printf("The number is: %d\n", num);
    ft_printf("The string is: %s\n", str);
    ft_printf("Character: %c, Integer: %i, Unsigned: %u, Hex: %x\n", 'A', -123, 456, 0xABC);

    // Comparing with standard printf
    printf("Standard printf: The number is: %d\n", num);

    return 0;
}
```

## 📁 Project Structure

```
ft_printf/
├── ft_printf.h       # Header file containing function prototypes
├── ft_printf.c       # Main source file for ft_printf function
├── libftprintf.a     # Compiled library file
├── Makefile          # Build instructions
└── README.md         # Project documentation
```

## 🤝 Contributing

We welcome contributions! Please see our [Contributing Guide](CONTRIBUTING.md) for details.

### Quick Contribution Steps
1. 🍴 Fork the repository
2. 🌟 Create your feature branch (git checkout -b feature/AmazingFeature)
3. ✅ Commit your changes (git commit -m 'Add some AmazingFeature')
4. 📤 Push to the branch (git push origin feature/AmazingFeature)
5. 🔃 Open a Pull Request

### Development Setup
```bash
# Fork and clone the repo
git clone https://github.com/yourusername/ft_printf.git

# Create a new branch
git checkout -b feature/your-feature-name

# Make your changes and test
make

# Commit and push
git commit -m "Description of changes"
git push origin feature/your-feature-name
```

## Testing

To test the `ft_printf` implementation, you can create test cases in a separate file and compile them with the library.

```c
#include <stdio.h>
#include "ft_printf.h"

int main() {
    int result_ft, result_std;

    // Test case 1: Integer
    result_ft = ft_printf("ft_printf: %d\n", 123);
    result_std = printf("   printf: %d\n", 123);
    printf("ft_printf returned: %d, printf returned: %d\n", result_ft, result_std);

    // Test case 2: String
    result_ft = ft_printf("ft_printf: %s\n", "test string");
    result_std = printf("   printf: %s\n", "test string");
    printf("ft_printf returned: %d, printf returned: %d\n", result_ft, result_std);

    return 0;
}
```

Compile and run the test:

```bash
gcc test.c ft_printf.c -o test
./test
```

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### License Summary
- ✅ Commercial use
- ✅ Modification
- ✅ Distribution
- ✅ Private use
- ❌ Liability
- ❌ Warranty

## 💬 Support

- 🐛 **Issues**: [GitHub Issues](https://github.com/mmiguelo/ft_printf/issues)

## 🙏 Acknowledgments

- 📚 **Libraries used**:
  - [Libft](https://github.com/42Paris/libft) - Inspiration for project structure and coding style.
- 👥 **Contributors**: Thanks to all [contributors](https://github.com/mmiguelo/ft_printf/contributors)
```

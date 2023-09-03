# ft_printf

![Static Badge](https://img.shields.io/badge/score-100%2F100-brightgreen)

The goal of this project was to create a simplified version of the C `printf` function, supporting only the following specifiers and no flags/width/precision/length arguments:

- **%c** prints a single character.
- **%s** prints a string.
- **%p** prints a pointer address.
- **%d** and **%i** both print an integer in base 10.
- **%u** prints an unsigned integer in base 10.
- **%x** and **%X** print an integer in base 16 in uppercase and lowercase formats, respectively.
- **%%** prints a percent sign.

The key learning point of this exercise was about understanding the power of **variadic functions** and their specific syntax. Our `ft_printf` can then be added to our [Libft](github.com/joao-aiveca-caseiro/Libft) library, providing a new tool for printing values besides the ones based on `write`.

To use `ft_printf` in a project, simply compile the library first using make, then include the executable libftprintf.a in the project's compilation process.

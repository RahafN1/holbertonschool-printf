# Custom Printf

Custom implementation of the printf function in C language.

## Prototype

```c
int _printf(const char *format, ...);
```

## Description

Produces output according to a format string.
Writes output to stdout, the standard output stream.
Returns the number of characters printed.
Returns -1 if format is NULL.

## Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| %c | Prints a single character |
| %s | Prints a string |
| %d | Prints a decimal integer |
| %i | Prints an integer |
| %% | Prints a literal percent sign |

## Files

| File | Description |
|------|-------------|
| main.h | Header file with prototypes |
| _printf.c | Main printf function |
| print_functions.c | Helper print functions |
| man_3_printf | Manual page |

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Authors

Holberton School Students 
Rahaf . dana 

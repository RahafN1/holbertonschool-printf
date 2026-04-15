# Custom Printf

Custom implementation of the printf function in C language.

---

## Prototype

```c
int _printf(const char *format, ...);
```

## Description

Produces output according to a format string.  
Writes output to stdout (standard output stream).  
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

## Installation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Requirements
- Ubuntu 20.04 LTS
- GCC compiler
- C programming language (C89 standard)

## Files

| File | Description |
|------|-------------|
| main.h | Header file with prototypes |
| _printf.c | Main printf function |
| print_functions.c | Helper print functions |
| man_3_printf | Manual page |

## Examples

```c
_printf("Hello %s\n", "World");
_printf("Char: %c\n", 'A');
_printf("Number: %d\n", 10);
```

## Testing

```c
#include "main.h"

int main(void)
{
    _printf("Testing %s %c %d %%\n", "printf", 'A', 123);
    return (0);
}
 ```

## Author
Holberton School Students: Rahaf & Dana 

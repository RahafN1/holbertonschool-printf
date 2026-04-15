#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_int(int n);
int print_number (int n);
int print_unsigned (unsigned int n);
int_octal(unsigned int n)
int print_hex(unsigned int n,int upper case);
#endif

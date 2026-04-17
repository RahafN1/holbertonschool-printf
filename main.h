#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args, char *buffer, int *buf_idx);
int print_string(va_list args, char *buffer, int *buf_idx);
int print_int(va_list args, char *buffer, int *buf_idx);
int print_binary(va_list args, char *buffer, int *buf_idx);
int print_unsigned(va_list args, char *buffer, int *buf_idx);
int print_octal(va_list args, char *buffer, int *buf_idx);
int print_hex(va_list args, char *buffer, int *buf_idx, int uppercase);

#endif

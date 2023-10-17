#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _print_binary(unsigned int i);
int _strlen(char *c);
int _string(char *str);
int _printdigit(int i);
int hex(int n);
int hexadecimal(int n);
int _print_unsigned(unsigned int i);
int _print_octal(int i);
int pointer(va_list arg);
int _print_hex_string(char * s);

#endif /* MAIN_H */

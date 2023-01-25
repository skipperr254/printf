#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct _printf - struct for the conversion specifiers
 * @c: character
 * @s: string
 * @f: function pointer
 */
typedef struct _printf
{
	char c;
	void (*f)(va_list);
} _printf_t;

int _printf(const char *format, ...);

#endif /* MAIN_H */

#include <stdarg.h>
#include <stdio.h>

/**
* _printf - Produces output according to a format
* @format: Character string that contains zero or more directives
*
* Description: This function takes a format string and any additional
* arguments specified by the format string, and uses the "putchar"
* function to print the corresponding characters to the standard output stream.
*
* The function uses the va_list, va_start, and va_end macros to handle the variable
* number of arguments passed in. It iterates through the format string, checking
* for the '%' character, which indicates a conversion specifier. If a '%' is found,
* the next character is checked to determine which conversion specifier is being used.
* If it is 'c', the next argument is interpreted as a character and printed using putchar().
* If it is 's', the next argument is interpreted as a string, and each character in the
* string is printed using putchar(). If it is '%', the '%' character is printed.
* The function keeps a count of the number of characters printed and returns this count
* when the function is finished.
*
* Return: the number of characters printed (excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                char c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (format[i] == 's') {
                char *s = va_arg(args, char *);
                for (int j = 0; s[j] != '\0'; j++) {
                    putchar(s[j]);
                    count++;
                }
            } else if (format[i] == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }
    va_end(args);
    return count;
}

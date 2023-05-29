#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Keeps track of the number of characters printed

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            // Check the conversion specifier
            switch (*format)
            {
                case 'c':
                {
                    // Print a character
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    // Print a string
                    char *str = va_arg(args, char *);
                    while (*str != '\0')
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    // Print a literal '%'
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    // Invalid conversion specifier, ignore it
                    break;
            }
        }
        else
        {
            // Print the regular character
            putchar(*format);
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);

    return count;
}

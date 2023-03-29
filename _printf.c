#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Print formatted output to stdout
 *
 * @format: A string that specifies the format of the output
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings), or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
					case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case '%':
					count += printf("%%");
					break;
				default:
					printf("Error: Unknown conversion specifier");
					return (-1);
			}
		}
		else
		{
			count += printf("%c", *format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

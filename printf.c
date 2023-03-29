#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - prints output according to a format
 *
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	for (; *format != '\0'; ++format)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
			case 'c':
			{
				char c = va_arg(args, int);
				putchar(c);
				++count;
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *);
				fputs(s, stdout);
				count += strlen(s);
				break;
			}
			case '%':
			{
				putchar('%');
				++count;
				break;
			}
			default:
			{
				/* Handle invalid format specifiers */
				return (-1);
			}
			}
		}
		else
		{
			putchar(*format);
			++count;
		}
	}

	va_end(args);
	return (count);
}


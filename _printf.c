#include <stdarg.h>
#include <stdio.h>
/**
* _printf - Print formatted output to stdout
* @format: A string that specifies the format of the output
* Return: The number of characters printed (excluding the null byte used
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
<<<<<<< HEAD
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
=======
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1); */
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list,
				buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
>>>>>>> 28414cd2ac9b96b61dc461fdc2cf806c3876adbc
		}

		format++;
	}
	va_end(args);
	return (count);
}

#include "shell.h"
/**
 * _printf - writes to standard output console
 * @format: input string to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] != '%')
			write(1, &format[i], 1), printed_chars++;
		else
		{
			switch (format[i + 1])
			{
				case 's':
					printed_chars += print_string(va_arg(ap, char *));
					break;
				case 'c':
					printed_chars += _putchar(va_arg(ap, int));
					break;
				default:
					write(1, &format[i], 1), write(1, &format[i + 1], 1), printed_chars += 2;
					break;
			} i++;
		}
	}
	va_end(ap);
	return (printed_chars);
}
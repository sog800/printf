#include "main.h"

/**
 * _printf - printing strings and chars
 * @format: format
 *
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int i, j;
	char buff[100] = {0};
	char *str_arg;

	i = j = 0;
	va_start(vl, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						buff[j] = (char)va_arg(vl, int);
						j++;
						break;
					}
				case 's':
					{
						str_arg = va_arg(vl, char *);
						strcpy(&buff[j], str_arg);
						j += strlen(str_arg);
						break;
					}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(vl);
	return (j);
}

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
	int i = 0, j = 0;
	char buff[100] = {0}, *str_arg, c;

	va_start(vl, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				c = '%';
				write(1, &c, 1);
			}
			else
			{
				if (format[i] == 'c')
				{
					buff[j] = (char)va_arg(vl, int);
					j++;
				}
				else if (format[i] == 's')
				{
					str_arg = va_arg(vl, char *);
					strcpy(&buff[j], str_arg);
					j += strlen(str_arg);
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
	return (j);
}

#include "main.h"

/**
 * format_specifier - function to check for specifier
 * @count: current position of the string pointed to by format
 * @format: pointer to the string to be printed
 * @ap: retrieved arguement
 * @reset: to reset the flag
 * @ptr_is_long: to set the long variable to 1
 * @ptr_is_short: to set variable to short
 * @flags: flag
 * @short_long: length modifier
 * Return: the length of string printed
 */

int format_specifier(int count, const char *format, va_list ap, int *reset,
		int *ptr_is_long, int *ptr_is_short, int *short_long, int *flags)
{
	int i, print_count = 0;
	char *testDefault = "sdicuSpxXobprR";

	switch (format[count])
	{
		case 'l':
			{
				*ptr_is_long = 1, *reset = 0;
				*short_long = LONG;
				goto end;
			}
		case 'h':
			{
				*ptr_is_short = 1, *reset = 0;
				*short_long = SHORT;
				goto end;
			}
		case '%':
			{
				print_count += _putchar('%');
				goto end;
			}
		default:
			{
				for (i = 0; testDefault[i]; i++)
				{
					if (format[count] == testDefault[i])
						goto stop;
				}
				print_count += _putchar('%');
				print_count += _putchar(format[count]);
				goto end;
			}
	}
stop:
	print_count += check_specifier(format, count, ap, flags, short_long);
end:
	return (print_count);
}


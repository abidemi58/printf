#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_c - prints character
 * @args: character argument
 * Return: number of characters
 */
int print_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (_putchar(c));
}
/**
 * print_s - prints a string
 * @args: string  argument
 * Return: number of characters
 */
int print_s(va_list args)
{
	int i, count = 0;
	char *str;

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}
/**
 * print_percent - pass the percent sing
 * @args: string  argument
 * Return: return the percent sing
 *
 */
int print_percent(va_list args)
{
	char *str;

	str = "%";
	if (va_arg(args, int) == *str)
	{
		return (*str);
	}
	return (*str);
}

/**
 * print_d - prints a decimal
 * @args: decimal argument
 * Return: counter
 */
int print_d(va_list args)
{

	unsigned int absolute, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(args, int);
		if (n < 0)
		{
			absolute = (n * -1);
			count += _putchar('-');
		}
		else
			absolute = n;

	aux = absolute;
	countnum = 1;
	while (aux > 9)
	{
		aux /= 10;
		countnum *= 10;
	}
	while (countnum >= 1)
	{
		count += _putchar(((absolute / countnum) % 10) + '0');
		countnum /= 10;
	}
	return (count);
}
/**
 * print_i - prints integer
 * @args: integer argument
 * Return: the decimal function
 */

int print_i(va_list args)
{
	return (print_d(args));
}

/**
 * print_binary - print number binary base
 * @ap: arg list
 * Return: number of printed char
 */

int print_binary(va_list args)
{
	char *str;
	int sum = 0;
	unsigned int argument = va_arg(args, unsigned int);

	if (!argument)
	{
		sum += _puts("0", 0);
		return (sum);
	}
	str = convert_base(argument, 2, 0);
	if (!str)
		return (0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_nbr - print number
 * @ap: arg list
 * Return: number of printed char
 */

int print_nbr(va_list args)
{
	return (print_number(va_arg(args, int)));
}

/**
 * print_octal - print number octal base
 * @ap: arg list
 * Return: number of printed char
 */

int print_octal(va_list args)
{
	char *str;
	int sum;

	str = convert_base(va_arg(args, unsigned int), 8, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

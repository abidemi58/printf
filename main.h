#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>


/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

int _printf(const char *format, ...);
int print_char(va_list ap);
int print_str(va_list ap);
int print_nbr(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hexa_lower(va_list ap);
int print_hexa_upper(va_list ap);
int print_unsigned(va_list ap);
int print_str_unprintable(va_list ap);
int print_str_reverse(va_list ap);
int print_ptr(va_list ap);
int print_rot13(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _putchar(char c);
int _puts(char *str, int ascii);
int _nbr_len(int prmNumber);
int _strlen_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);
int get_width(const char *format, int *i, va_list list);
int is_digit(char);
int get_flags(const char *format, int *i);

/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */

typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} flags_p;
#endif

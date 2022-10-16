#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024
#define SPECIFIERS_SIZE 14
#define LENGTH_SPECS_SIZE 8
#define FLAGS_SPECS_SIZE 6

#define ERROR -2
#define INVALID -1
#define EMPTY 0
#define OK 1



/**
 * struct pf_buf - _printf buffer
 *
 * @buf: the buffer
 * @len: the size of the string to add to main buffer
 * @index: index of last char in main buffer
 *
typedef struct pf_buf
{
	char *buf;
	int len;
	int index;
} pf_buf_t;
*/

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

/* UTILS: utility function using which we can reuse the existing block of code without creating instance of the function */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strcat(char *s1, char *s2);
char *_charcat(char *str, char c);
char *_strdup(char *str);
int _isalpha(int c);
int _islower(int c);
int _isdigit(int c);
int _strnchr(char *s, char c, unsigned int n);
void rev_string(char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int size);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_itoa(int i);
char *_uitoa(unsigned int i);
char *_chartohex(int ch);
char *_dectohex(unsigned int uint, int upper);
char *_dectooct(unsigned int uint);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_ptrtohex(void *ptr);

/* PRINTF */
int _printf(const char *format, ...);
int spec_eng(va_list list, spec_data_t *data, pf_buf_t *buffer);
int is_in_format_specifiers(char c);
int format_parsing(int *i, const char *format, pf_buf_t *buf, va_list list);

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);
#endif

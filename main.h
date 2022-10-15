#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024


/**
 * struct pf_buf - _printf buffer
 *
 * @buf: the buffer
 * @len: the size of the string to add to main buffer
 * @index: index of last char in main buffer
 */
typedef struct pf_buf
{
	char *buf;
	int len;
	int index;
} pf_buf_t;


/* PRINTF */
int _printf(const char *format, ...);




























#endif

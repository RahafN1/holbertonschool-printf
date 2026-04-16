#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

	unsigned int num;
	num = 98;

	 _printf("Unsigned: %u\n", num);
	

	_printf("Octal: %o\n", num);


	_printf("Hex lowercase: %x\n", num);


	_printf("Hex uppercase: %X\n", num);


    return (0);
}

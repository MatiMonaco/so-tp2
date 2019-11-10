#ifndef STDIO_H
#define STDIO_H
#include <stdarg.h>
//void printf(const char* buffer);
void printf(const char* format, ...);
void putchar(char letter);
char getchar();
int scanf(char* format, ...);
void perror(const char* buffer);
void printBin(uint64_t value);
void printDec(uint64_t value);
void printBin(uint64_t value);
void printBase(uint64_t value, uint32_t base);
#endif
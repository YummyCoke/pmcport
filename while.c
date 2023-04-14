#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define PORT0 0xC1
#define PORT1 0xC2
#define PORT2 0xC3
#define PORT3 0xC4
#define PORT4 0xC5
#define PORT5 0xC6
#define PORT6 0xC7
#define PORT7 0xC8

int main() {
	while(1)
	{
       	  __asm__("imul %rax, %rdx");
	} 
}

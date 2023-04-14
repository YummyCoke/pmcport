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
    int fd;
    uint64_t port0;
    uint64_t port1;
    uint64_t port2;
    uint64_t port3;
    uint64_t port4;
    uint64_t port5;
    uint64_t port6;
    uint64_t port7;

    uint64_t nport0,nport1,nport2,nport3,nport4,nport5,nport6,nport7;

    uint32_t port0_id = PORT0;
    uint32_t port1_id = PORT1;
    uint32_t port2_id = PORT2;
    uint32_t port3_id = PORT3;
    uint32_t port4_id = PORT4;
    uint32_t port5_id = PORT5;
    uint32_t port6_id = PORT6;
    uint32_t port7_id = PORT7;

    const char *msr_file = "/dev/cpu/1/msr";

    fd = open(msr_file, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    while(1)
    {
    pread(fd, &port1, sizeof(port1), port1_id) != sizeof(port1);
    __asm__("imul %rax, %rbx");
    __asm__("imul %rax, %rbx");
    system("taskset 0x02 ./temp");
    pread(fd, &nport1, sizeof(nport1), port1_id) != sizeof(nport1);
    printf("difference value of MSR port 1: 0x%llx\n", nport1-port1);

    printf ("\n ========================== \n   count again... \n ========================== \n");

    sleep(1);
    }
    close(fd);

    return 0;
}

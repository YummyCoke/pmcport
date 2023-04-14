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
    pread(fd, &port0, sizeof(port0), port0_id) != sizeof(port0);
    pread(fd, &port1, sizeof(port1), port1_id) != sizeof(port1);
    pread(fd, &port2, sizeof(port2), port2_id) != sizeof(port2);
    pread(fd, &port3, sizeof(port3), port3_id) != sizeof(port3);
    pread(fd, &port4, sizeof(port4), port4_id) != sizeof(port4);
    pread(fd, &port5, sizeof(port5), port5_id) != sizeof(port5);
    pread(fd, &port6, sizeof(port6), port6_id) != sizeof(port6);
    pread(fd, &port7, sizeof(port7), port7_id) != sizeof(port7);

//   __asm__("imul %rax, %rbx");
   __asm__("jmp 0x13d3");
   __asm__("nop");
//    system("taskset 0x02 ./temp");

    pread(fd, &nport0, sizeof(nport0), port0_id) != sizeof(nport0);
    pread(fd, &nport1, sizeof(nport1), port1_id) != sizeof(nport1);
    pread(fd, &nport2, sizeof(nport2), port2_id) != sizeof(nport2);
    pread(fd, &nport3, sizeof(nport3), port3_id) != sizeof(nport3);
    pread(fd, &nport4, sizeof(nport4), port4_id) != sizeof(nport4);
    pread(fd, &nport5, sizeof(nport5), port5_id) != sizeof(nport5);
    pread(fd, &nport6, sizeof(nport6), port6_id) != sizeof(nport6);
    pread(fd, &nport7, sizeof(nport7), port7_id) != sizeof(nport7);

    printf("difference value of MSR port 0: 0x%llx\n", nport0-port0-0x15);
    printf("difference value of MSR port 1: 0x%llx\n", nport1-port1-0x48);
    printf("difference value of MSR port 2: 0x%llx\n", nport2-port2-0x1f);
    printf("difference value of MSR port 3: 0x%llx\n", nport3-port3-0x10);
    printf("difference value of MSR port 4: 0x%llx\n", nport4-port4-0x8);
    printf("difference value of MSR port 5: 0x%llx\n", nport5-port5-0x1d);
    printf("difference value of MSR port 6: 0x%llx\n", nport6-port6-0x68);
    printf("difference value of MSR port 7: 0x%llx\n", nport7-port7-0x8);

    printf ("\n ========================== \n   count again... \n ========================== \n");

    sleep(1);
    }
    close(fd);

    return 0;
}

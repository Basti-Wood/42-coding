
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void reciever(int sig)
{
    static int i = 0;
    static unsigned char c = 0;

    if (sig == SIGUSR2)
        c = c << 1;
    else if (sig == SIGUSR1)
        c = (c << 1) | 0b00000001;
    i++;

    if (i == 8)
    {
        ft_printf("%c", c);
        fflush(stdout); 
        i = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = reciever;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    printf("PID: %d\n", getpid());

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause(); 

    return 0;
}
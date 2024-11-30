#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    printf("DEBUG: Starting to open file...\n");

    fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }
    printf("DEBUG: File opened successfully...\n");

    line = temp_get_next_line(fd);
    printf("DEBUG: Line read: %s\n", line);
    printf("%s", line);
	line = temp_get_next_line(fd);
	printf("\n%s", line);
	free(line);
    

    printf("DEBUG: End of file or error.\n");
    close(fd);
    printf("finished the program\n");

    return 0;
}

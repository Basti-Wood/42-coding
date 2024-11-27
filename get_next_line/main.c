#include <stdio.h>      // For printf()
#include <fcntl.h>      // For open()
#include <unistd.h>     // For close()
#include "get_next_line.h" // Include the header for get_next_line

int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Check if the user provided a file as an argument
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Read and print lines until EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line
        free(line);         // Free the memory allocated by get_next_line
    }

    // Close the file descriptor
    close(fd);
    return (0);
}

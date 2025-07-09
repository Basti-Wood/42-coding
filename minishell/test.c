
#include <stdio.h>

int main(int argc, char **argv, char **env) {
    (void)argc; // Unused, suppress warning
    (void)argv; // Unused, suppress warning

    for (int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }

    return 0;
}
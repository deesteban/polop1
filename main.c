#include <stdio.h>
char **global_argv;
int global_argc;
int a;

int main(int argc, char **argv) {
    global_argv = argv;
    global_argc = argc;
    printf("Hello, World!\n");
    return 0;
}


/*
#include <stdio.h>
#include "heap.c"

void test_system_functions(void* ptr, size_t size) {
    test_system_malloc(size);
    test_system_free(ptr);
    test_system_realloc(ptr, size);
}

int main(int argc, char* argv[]) {

    if (argc == 2 && argv[1][0] == '-' && argv[1][1]== 't') {
        int test_num = atoi(argv[2]);

        switch(test_num) {
            case 1:
                test_system_functions(NULL, 100);
                break;
            default:
                printf("Invalid test number\n");
                break;
        }
    }
    else {
        test_system_functions(NULL, 100);
    }

    printf("Hello, World!\n");

    return 8;
}
*/
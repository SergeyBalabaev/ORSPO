#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define N 10000

long diff_ms(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) * 1000L +
           (b.tv_nsec - a.tv_nsec) / 1000000L;
}

void test_sbrk(size_t size) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < N; i++) {
        char *p = sbrk(size);
        if (p == (void*)-1) {
            perror("sbrk");
            exit(1);
        }

        // доступ к каждой странице
        for (size_t j = 0; j < size; j += 4096) {
            p[j] = 1;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("sbrk (%zu bytes): %ld ms\n", size, diff_ms(start, end));
}

void test_mmap(size_t size) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < N; i++) {
        char *p = mmap(NULL, size,
                       PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS,
                       -1, 0);

        if (p == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }

        for (size_t j = 0; j < size; j += 4096) {
            p[j] = 1;
        }

        munmap(p, size);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("mmap (%zu bytes): %ld ms\n", size, diff_ms(start, end));
}

int main() {
    size_t sizes[] = {64, 1024, 4096, 65536, 1048576}; // 64B → 1MB
    int count = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < count; i++) {
        printf("\n--- size = %zu ---\n", sizes[i]);
        test_sbrk(sizes[i]);
        test_mmap(sizes[i]);
    }

    return 0;
}
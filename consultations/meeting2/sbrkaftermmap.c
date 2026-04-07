#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    void *old_brk = sbrk(0);
    printf("Old program break: %p\n", old_brk);

    size_t heap_inc = 1024 * 1024; // 1 MB
    sbrk(heap_inc);
    void *new_brk = sbrk(0);
    printf("New program break after sbrk: %p\n", new_brk);

    void *mmap_addr = new_brk; 
    size_t mmap_size = 1024 * 1024; // 1 MB
    void *p = mmap(mmap_addr, mmap_size,
                   PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 
                   -1, 0);
    if (p == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    printf("mmap allocated at: %p\n", p);

    void *try_brk = sbrk(heap_inc);
    printf("Program break after second sbrk: %p\n", try_brk);

    if (try_brk == new_brk + heap_inc) {
        printf("sbrk succeeded!\n");
    } else {
        printf("sbrk blocked by mmap!\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

void print_maps_with_pages() {
    FILE *f = fopen("/proc/self/maps", "r");
    if (!f) { perror("fopen"); exit(1); }

    char line[512];
    unsigned long prev_end = 0;

    while (fgets(line, sizeof(line), f)) {
        unsigned long start, end;
        char perms[5], dev[6], mapname[256] = "";
        unsigned long offset = 0, inode = 0;

        int n = sscanf(line, "%lx-%lx %4s %lx %5s %lu %255[^\n]",
                       &start, &end, perms, &offset, dev, &inode, mapname);

        if (n < 6) continue;

        // если есть «дырка» между сегментами
        if (prev_end && start > prev_end) {
            unsigned long hole_pages = (start - prev_end + PAGE_SIZE - 1) / PAGE_SIZE;
            printf("%lx-%lx %lu pages [hole]\n", prev_end, start, hole_pages);
        }

        unsigned long size = end - start;
        unsigned long pages = (size + PAGE_SIZE - 1) / PAGE_SIZE;

        if (n == 7)
            printf("%lx-%lx %lu pages %s %08lx %s %lu %s\n",
                   start, end, pages, perms, offset, dev, inode, mapname);
        else
            printf("%lx-%lx %lu pages %s %08lx %s %lu [anon]\n",
                   start, end, pages, perms, offset, dev, inode);

        prev_end = end;
    }

    fclose(f);
}

int main() {
    printf("=== BEFORE allocations ===\n");
    print_maps_with_pages();

    // // sbrk
    void *p1 = sbrk(4096 * 10 * 1024);
    if (p1 == (void*)-1) { perror("sbrk"); exit(1); }

    // mmap
    void *p2 = mmap(p1, 4096 * 5, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p2 == MAP_FAILED) { perror("mmap"); exit(1); }
    p1 = sbrk(4096 * 10 * 1024);
    if (p1 == (void*)-1) { perror("sbrk"); exit(1); }
    
    printf("Address sbrk = %p\n", p1);
    printf("Address mmap = %p\n", p2);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define MAX_ADDR 0x7fffffffffffUL  // пример для 64-битного пространства пользователя

void print_maps_scaled() {
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

        // Если есть «дырка» между предыдущим сегментом и текущим
        if (prev_end < start) {
            unsigned long hole_pages = (start - prev_end + PAGE_SIZE - 1) / PAGE_SIZE;
            printf("%016lx-%016lx %lu pages [hole]\n", prev_end, start, hole_pages);
        }

        unsigned long size = end - start;
        unsigned long pages = (size + PAGE_SIZE - 1) / PAGE_SIZE;

        if (n == 7)
            printf("%016lx-%016lx %lu pages %s %08lx %s %lu %s\n",
                   start, end, pages, perms, offset, dev, inode, mapname);
        else
            printf("%016lx-%016lx %lu pages %s %08lx %s %lu [anon]\n",
                   start, end, pages, perms, offset, dev, inode);

        prev_end = end;
    }

    // После последнего сегмента
    if (prev_end < MAX_ADDR) {
        unsigned long hole_pages = (MAX_ADDR - prev_end + PAGE_SIZE - 1) / PAGE_SIZE;
        printf("%016lx-%016lx %lu pages [hole]\n", prev_end, MAX_ADDR, hole_pages);
    }

    fclose(f);
}

int main() {
    printf("=== FULL ADDRESS SPACE ===\n");
    print_maps_scaled();
    int arr[1000000];
    arr[5000]=1;
    return 0;
}
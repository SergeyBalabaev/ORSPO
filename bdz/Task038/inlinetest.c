#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define N 100000000UL

__attribute__((noinline))
uint64_t slow_func(uint64_t x) {
    return x * 3 + 1;
}

static inline uint64_t fast_func(uint64_t x) {
    return x * 3 + 1;
}

static inline uint64_t rdtsc() {
    uint32_t lo, hi;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

static inline uint64_t now_us() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    return (uint64_t)ts.tv_sec * 1000000ULL +
           (uint64_t)ts.tv_nsec / 1000ULL;
}

int main() {
    volatile uint64_t x = 1;
    uint64_t t1, t2;
    uint64_t us1, us2;

    // --- slow ---
    us1 = now_us();
    t1  = rdtsc();
    for (uint64_t i = 0; i < N; i++) {
        x = slow_func(x);
    }
    t2  = rdtsc();
    us2 = now_us();
    uint64_t slow_res_t  = t2 - t1;
    uint64_t slow_res_us = us2 - us1;

    printf("slow: %lu cycles, %lu us\n", slow_res_t, slow_res_us);

    // --- fast ---
    us1 = now_us();
    t1  = rdtsc();
    for (uint64_t i = 0; i < N; i++) {
        x = fast_func(x);
    }
    t2  = rdtsc();
    us2 = now_us();
    uint64_t fast_res_t  = t2 - t1;
    uint64_t fast_res_us = us2 - us1;

    printf("fast: %lu cycles, %lu us\n", fast_res_t, fast_res_us);
    printf("diff: %lf cycles, %lf us\n",
           (double)slow_res_t / fast_res_t,
           (double)slow_res_us / fast_res_us);

    return 0;
}
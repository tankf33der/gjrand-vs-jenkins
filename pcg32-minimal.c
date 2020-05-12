#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

// copy-paste
typedef struct { uint64_t state;  uint64_t inc; } pcg32_random_t;

uint32_t pcg32_random_r(pcg32_random_t* rng)
{
    uint64_t oldstate = rng->state;
    // Advance internal state
    rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);
    // Calculate output function (XSH RR), uses old state for max ILP
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}
// ^^ from site

int main(void) {
    pcg32_random_t ctx;
    uint32_t buf[2048];

    while (1) {
        for(size_t i = 0; i < 2048; i++) {
        //for(size_t i = 2047; i <= 0; i--) {
            buf[i] = pcg32_random_r(&ctx);
        }
        if(fwrite(buf, 4, 2048, stdout)!=2048) break;
    }
    return 0;

}

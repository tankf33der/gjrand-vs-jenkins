#include <stdio.h>
#include <inttypes.h>
#include "hydrogen.h"

int main(void) {
    uint32_t buf[2048];

    hydro_init();
    while (1) {
        for(size_t i = 0; i < 2048; i++) {
            buf[i] = hydro_random_u32();
        }
        if(fwrite(buf, 4, 2048, stdout)!=2048) break;
    }
    return 0;
}

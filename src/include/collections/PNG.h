#include "collections/skip_list.h"
#include "types.h"
#include "stdatomic.h"
/*PNG*/
typedef struct png {
        atomic_char dest[MAX_ADDR];
} png_t;

png_t *png_setup();

void png_tear_down(png_t *png);

int png_allow(png_t *png, addr_t addr);

void png_update(png_t *png, addr_t addr, char allow);

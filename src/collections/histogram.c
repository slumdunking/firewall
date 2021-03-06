#include "collections/histogram.h"
#include <unistd.h>
#include <stdatomic.h>
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*histogram*/

hist_t *hist_setup(){

	hist_t *hist = (hist_t *) malloc(sizeof(hist_t));
    memset(hist->dest, 0, MAX_ADDR);

	if (hist== NULL){
		perror("malloc");
	}

	return hist;

}

void hist_tear_down(hist_t *hist){
	free(hist);
}

void hist_update(hist_t *hist, uint16_t fingerprint){
	atomic_int i = 1;
	atomic_fetch_add(hist->dest + fingerprint, &i);
}

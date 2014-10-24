#include "worker.h"

void _process_dpacket(worker_info_t *w, dpacket_t *packet);
uint16_t _fingerprint(dpacket_t *packet);

void *worker_start(void *wi) {
	worker_info_t *w = (worker_info_t *)wi;

	while (1) {
		dpacket_t *packet = (dpacket_t *)squeue_deq_wait(w->queue);
		_process_dpacket(w, packet);
	}
	return NULL;
}

void _process_dpacket(worker_info_t *w, dpacket_t *packet) {
	if (png_allow(w->png, packet->source) &&
		r_accept(w->r, packet->dest, packet->source)) {
		hist_add(w->hist, fingerprint(packet));
	}
}

uint16_t _fingerprint(dpacket_t *packet) {
	// TODO: fingerprint
	return packet->source;
}
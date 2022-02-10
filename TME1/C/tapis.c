#include "tapis.h"

struct Tapis* create_tapis(size_t capacity) {
    struct Tapis* tapis = malloc(sizeof(struct Tapis));
    
    tapis->first = 0;
    tapis->last = 0;
    tapis->size = 0;
    tapis->capacity = capacity;
    tapis->packets = malloc(sizeof(struct Packet*) * capacity);
    
    return tapis;
    
}

void put_tapis(struct Tapis* tapis, struct Packet* packet) {
    
    if(tapis->size < tapis->capacity) {
        tapis->packets[tapis->last] = packet;
        tapis->last = (tapis->last + 1) % tapis->capacity;
        tapis->size++;
    }
    
}

struct Packet* take_tapis(struct Tapis* tapis) {
    
    if(tapis->size > 0) {
        struct Packet* ret = tapis->packets[tapis->first];
        tapis->first = (tapis->first + 1) % tapis->capacity;
        tapis->size--;
        return ret;
    }
    
    return NULL;
}

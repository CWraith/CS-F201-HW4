/* A4: AI-assisted instructor scaffolding. Mark your own assistance separately. */
#include "readings.h"

int valid_reading(struct Reading reading) {
    /* TODO: check each field. */
    if(reading.id < 0 || reading.id > 1000000 || reading.temp < -100 || reading.temp > 100 || reading.unit != 'C'){
    	return 0;
    }
    return 1;
}

int read_reading(FILE *in, struct Reading *result) {
    struct Reading read;
    
	if(fscanf(in, "%d", &read.id) && fscanf(in, "%d", &read.temp) && fscanf(in, "%c", &read.unit)){
		if(valid_reading(read)){
				*result = read;
				return 1;
		}
		return -1;
	}
    return 0;
}

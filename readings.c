// A1
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "readings.h"

int load_readings(const char *path, struct Reading **items, int *length) {
	FILE* in = fopen(path, "r");
	if(in == NULL) return 0;
    int count;
    if(fscanf(in, "%d", &count) != 1){
    	fclose(in);
    	return 0;
    }

    if(count < 0){
    	fclose(in);
    	return 0;
    }
    if(count == 0){
   		*length = 0;
        *items = NULL;
        fclose(in);
        return 1;
	}
	struct Reading* readings = malloc(count * sizeof *readings);
	if(readings == NULL){
		fclose(in);
	    return 0;
	}

	for(int i = 0; i < count; i++){
		if(read_reading(in, &readings[i]) != 1){
	    	fclose(in);
	        free(readings);
	        return 0;
	    }
	}

	char trail;
	if(fscanf(in, " %c", &trail) == 1){
		fclose(in);
		free(readings);
		return 0;
	}
	*items = readings;
	*length = count;
	fclose(in);
	return 1;
}

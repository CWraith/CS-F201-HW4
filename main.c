/* A4: AI-assisted instructor scaffolding. Mark your own assistance separately. */
#include <stdio.h>
#include <stdlib.h>
#include "readings.h"
#include "report.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s INPUT_PATH OUTPUT_PATH\n", argv[0]);
        return 1;
    }
    /* argv[1] is the input filename; argv[2] is the output filename.
       TODO: call the loader, handle failure, write the report, free the array,
       and return success/failure. Report errors to stderr. */
	struct Reading* items;
	int length = 0;
	if(!load_readings(argv[1], &items, &length)){
		fprintf(stderr, "Could not load readings\n");
		return 1;
	}

	if(!write_report(argv[2], items, length)){
		fprintf(stderr, "Could not write report\n");
		return 1;
	}

    return 0;
}

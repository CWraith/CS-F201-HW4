#include <stdio.h>
#include "report.h"

int write_summary(FILE *out, struct Summary summary) {
	if(fprintf(out, "Records: %d\nTotal temperature: %d\nFreezing: %d\n", summary.count, summary.total, summary.freezing) < 0) return 0;
	if(summary.count > 0){
		if(fprintf(out, "Minimum: %d\nMaximum: %d\n", summary.minimum, summary.maximum) < 0) return 0;
	}
	else if(fprintf(out, "Minimum: N/A\nMaximum: N/A\n") < 0) return 0;
	if(fprintf(out, "Freezing readings:\n") < 0) return 0;
    return 1;
}

int write_freezing(FILE *out, const struct Reading items[], int length) {
    for(int i = 0; i < length; i++){
    	if(items[i].temp < 0){
	    	if(fprintf(out, "%d %d %c\n", items[i].id, items[i].temp, items[i].unit) < 0){
	    		return 0;
	    	}
	    }
	}
    return 1;
}

int write_report(const char *path, const struct Reading items[], int length) {
    FILE* out = fopen(path, "w");
    if(out == NULL) return 0;

    if(!write_summary(out, summarize_readings(items, length))){
    	fclose(out);
    	return 0;
    }
    if(!write_freezing(out, items, length)){
    	fclose(out);
    	return 0;
	}
    if(fclose(out) != 0) return 0;
    
    return 1;
}

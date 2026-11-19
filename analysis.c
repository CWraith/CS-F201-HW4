/* A4: AI-assisted instructor scaffolding. Mark your own assistance separately. */
#include "analysis.h"

struct Summary summarize_readings(const struct Reading items[], int length) {
    struct Summary result = {0, 0, 0, 0, 0};
    result.count = length;
    for(int i = 0; i < length; i++){
    	result.total += items[i].temp;
    	if(items[i].temp < 0) result.freezing++;
    	if(items[i].temp < result.minimum) result.minimum = items[i].temp;
    	if(items[i].temp > result.maximum) result.maximum = items[i].temp;
    }
    return result;
}

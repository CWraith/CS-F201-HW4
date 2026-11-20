#include "analysis.h"

struct Summary summarize_readings(const struct Reading items[], int length) {
    struct Summary result = {0, 0, 0, 0, 0};
    result.count = length;
	if(length > 0){
		result.minimum = items[0].temp;
		result.maximum = items[0].temp;
	}
    for(int i = 0; i < length; i++){
    	result.total += items[i].temp;
    	if(items[i].temp < 0) result.freezing++;
    	if(items[i].temp < result.minimum) result.minimum = items[i].temp;
    	if(items[i].temp > result.maximum) result.maximum = items[i].temp;
    }
    return result;
}

#include <stddef.h>
#include "test.h"

void run_student_tests(void) {
       check_program("Caleb: no records", "0\n", "Records: 0\nTotal temperature: 0\n"
       "Freezing: 0\nMinimum: N/A\nMaximum: N/A\nFreezing readings:\n");
       check_program("Caleb: invalid readings", "2\n-1 3 C\n10 102 F", NULL);
       check_program("Caleb: empty input", "", NULL);       
}

#include <stddef.h>
#include "test.h"

void run_student_tests(void) {
    /* TODO: Add at least three original check_program calls per student.
       See tests/README.md. Prefix case names with your name/GitHub username. */
       check_program("Caleb: no records", "0\n", "Records: 0\nTotal temperature: 0\n"
       "Freezing: 0\nMinimum: N/A\nMaximum: N/A\nFreezing readings:");
       check_program("Caleb: invalid readings", "2\n-1 3 C\n10 102 F", NULL);
       check_program("Caleb: empty input", "", NULL);       
}

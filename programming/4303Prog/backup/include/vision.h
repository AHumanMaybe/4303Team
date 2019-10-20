/*vex-vision-config:begin*/
#include "vex.h"
#include "v5_vcs.h"
vex::vision::signature ORANGE = vex::vision::signature (1, 4449, 8337, 6393, -1841, -1213, -1527, 1.6, 0);
vex::vision::signature GREEN = vex::vision::signature (2, -8223, -5219, -6721, -3467, -1525, -2496, 2.3, 0);
vex::vision::signature PURPLE = vex::vision::signature (3, 1075, 2601, 1838, 5705, 10281, 7993, 1.7, 0);
vex::vision::signature IGGY = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision VS = vex::vision (vex::PORT15, 85, ORANGE, GREEN, PURPLE, IGGY, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
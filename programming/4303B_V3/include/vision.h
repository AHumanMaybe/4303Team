/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature O = vex::vision::signature (1, 6715, 8495, 7605, -3041, -1633, -2337, 3.4, 0);
vex::vision::signature G = vex::vision::signature (2, -7183, -2709, -4946, -4761, -1337, -3049, 1.4, 0);
vex::vision::signature P = vex::vision::signature (3, -1, 1849, 924, 1675, 4665, 3170, 1.9, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision VS = vex::vision (vex::PORT20, 51, O, G, P, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
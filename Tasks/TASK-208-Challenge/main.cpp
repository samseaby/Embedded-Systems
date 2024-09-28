#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;

// THE CODE BELOW IS NOT A SOLUTION
//
// IT IS FUNDAMENTALLY FLAWED (AND INCOMPLETE)
//
//
int redState = 0;

int main()
{
    //Start flashing timer
    tmr_flash.start();

    while (true) {

        if (tmr_flash.read_ms() > 500){
            tmr_flash.reset();
            //Toggle Yellow LED
            ledYel = !ledYel;
            ledRed = redState;
        }

        //Wait for switch press and release (by BLOCKING)
        if (SW2.read() == 1 && tmr_flash.read_ms() > 50){
            redState = !redState;
        }
    


    }
}






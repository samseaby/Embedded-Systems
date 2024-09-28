#include "uop_msb.h"
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);

// Timer(modified version from Timer)
TimerCompat tmr1;

int main()
{
    //Time how long it takes to perform a printf
    tmr1.start();
    printf("Hello World, How Are You?\n");
    tmr1.stop();

    //Print out how long it took
    unsigned long long dur = tmr1.read_ms();
    printf("The time taken was %llu milliseconds\n", dur);   

    int prevSwitchState = 0; 

    //Now to use a timer to implement a delay
   //tmr1.start();
    while (true) {

        int currentSwitchState = SW_BLUE;

        // If pressed
        if (currentSwitchState == 1 && prevSwitchState == 0){
            tmr1.reset();
            tmr1.start();
            while (tmr1.read_ms() < 50);
            tmr1.stop();

            // Still held after debounce? If so, Toggle
            if(SW_BLUE == 1){
                ledRed = !ledRed;

                tmr1.reset();
                tmr1.start();
                while (tmr1.read_ms() < 500); // Wait for 500ms
                tmr1.stop();
            }
        }

        // Check for release and debounce
        if (currentSwitchState == 0 && prevSwitchState == 1){
            tmr1.reset();
            tmr1.start();
            while (tmr1.read_ms() < 50);
            tmr1.stop();
        }

        // Update state
        prevSwitchState = currentSwitchState;
    }
}




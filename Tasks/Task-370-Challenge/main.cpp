#include "uop_msb.h"
#include <chrono>
#include <cstdio>
using namespace uop_msb;

// Ticker Definition
Ticker tick;

// Thread Definition
Thread t1;

// Variable Definition
float LDRsum{0};
int sampleCount{0};

// LDR Setup
AnalogIn AIN(AN_LDR_PIN);

// ISR
void threadISR(){
    t1.flags_set(1);
}

// Function Definition
void task1(){
    while (1){
        // Wait for flag
        ThisThread::flags_wait_any(1);

        // Clear flag
        ThisThread::flags_clear(1);
        
        // Update LDR sum
        LDRsum += AIN.read();

        // Increment Counter
        sampleCount++;

        // Average after 1000 samples
        if (sampleCount >= 1000){
            float average = LDRsum / 1000;

            // Print average to terminal
            printf("Average of past 1000 samples = %f\n", average);

            // Reset sum and counter
            LDRsum = 0;
            sampleCount = 0;
        }
    }
}

int main(void)
{
//1. Create an ISR - called by a Ticker every 1ms. This ISR simply has the job of signalling a waiting thread to perform an ADC conversion
    tick.attach(&threadISR, 1ms);

//2. Create a thread that waits for a signal from the ISR. This thread should ideally have the highest priority
    t1.start(task1);

//3. Each time it is unblocked by the signal, it should read the ADC (Use `AnalogIn`) for the LDR and add it to a running sum.
//4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 

    while (true) {
        ThisThread::sleep_for(1000ms);
    }
    
}   


#include "mbed.h"

// Define pins
    // Temperature sensor input (A0)
    AnalogIn AIN(PA_0);
    // PWM output for LED (LED1 on microcontroller)
    PwmOut redLED(LED1);
    

int main() {
           // 100 ms polling interval
           const int hundredmsDelay = 100000;
           // Variable to store the temperature
           float temperature;
           // Variable to store the LED brightness (PWM duty cycle)
           float LED_Brightness;
    
    while (true) {
        // Step 1: Read the analog input from the temperature sensor
        // Read analog value (0.0 to 1.0)
        float tempReading = AIN.read();
        
        // Step 2: Convert the analog reading to temperature in degrees Celsius
        // Convert to temperature (0°C to 100°C)
        float tempReadingDegrees = tempReading * 100;

        // Step 3: Adjust the brightness of the LED based on the temperature
        // Scale brightness proportionally between 20°C and 40°C
        if (tempReadingDegrees < 20) {
            LED_Brightness = 0;
        }
        else if (tempReadingDegrees > 40) {
            LED_Brightness = 1;
        }
        else {
             LED_Brightness = (tempReadingDegrees - 20.0) / 20.0;
        }
        
        // Step 4: Set the PWM duty cycle to control LED brightness
        // Set LED brightness (0.0 = off, 1.0 = fully on)
        redLED.write(LED_Brightness);

        // Step 5: Wait for the polling interval (100 ms)
        wait_us(hundredmsDelay);
    }
}
/*
Internet of Things
Challenge 03
Group:  Aisha sharyf (S1900266)
        Nuha ali (S1800181)
Description: A simple morse code program.
file: sender.cpp for the sender microBit
*/

#include "MicroBit.h"

// Initialize microBit
MicroBit uBit;

// Initialize microBits buttons
    MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
    MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);

// Image display
const uint8_t image_dot_arr[]{
    0,0,0,0,0,
    0,1,0,1,0,
    0,0,1,0,0,
    0,1,0,1,0,
    0,0,0,0,0,};
const uint8_t image_line_arr[]{
    0,0,0,0,0,
    0,0,0,0,0,
    1,1,1,1,1,
    0,0,0,0,0,
    0,0,0,0,0,};
const uint8_t image_space_arr[]{
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1,};
MicroBitImage image_dot(5,5,image_dot_arr); 
MicroBitImage image_line(5,5,image_line_arr);
MicroBitImage image_space(5,5,image_space_arr);

void send() {
        
        // Sends data and displays data when button A is pressed
        if (uBit.buttonA.isPressed()) {
            
            uBit.radio.datagram.send("1");
            uBit.display.print(image_dot);
        }
        
        // Sends data and displays data when button B is pressed
        else if (uBit.buttonB.isPressed()) {
            
            uBit.radio.datagram.send("2");
            uBit.display.print(image_line);
        }
        
        // Sends data and displays data when button AB is pressed
        else {
             
            uBit.radio.datagram.send("3");
            uBit.display.print(image_space);
        }
        uBit.sleep(500);
        uBit.display.clear();
}
    
int main() {
    
    // Initialize microBit runtime
    uBit.init();
    // Enable radio in microBit
    uBit.radio.enable();

    while(1) {
        
        send(); 
    }

}
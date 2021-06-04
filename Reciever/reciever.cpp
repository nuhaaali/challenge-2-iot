/*
Internet of Things
Challenge 03
Group:  Aisha sharyf (S1900266)
        Nuha ali (S1800181)
Description: A simple morse code program.
file: reciever.cpp for the reciever microBit
*/

#include "MicroBit.h"

// Initialize microBit
MicroBit uBit;

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


// Handle the recieved data from the sender
void Data(MicroBitEvent e) {
    
    //Takes data sent from Sender and stores it in a variable
    ManagedString dataFromSender = uBit.radio.datagram.recv();

    // Display correct values from the sender
    if (dataFromSender == "1") {
        
        uBit.display.print(image_dot);
    }
    
    else if (dataFromSender == "2") {
        
        uBit.display.print(image_line);
    }
    
    else if (dataFromSender == "3") {
        
        uBit.display.print(image_space);
    }

    uBit.sleep(500);
    uBit.display.clear();
}

int main() {
    
    // Initialize microBit 
    uBit.init();
    //Setup a hander to run when data is received
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, Data);
    // Enable radio in microBit
    uBit.radio.enable(); 

    while (1) {
        
        uBit.sleep(1000);
    }
}
/*
 * This program demonstrates a three-bit binary odd parity generator.
 * Circuit uses two 74LS04 hex inverters, two 74LS10 triple 3-input 
 * NAND gates, and a 74LS32 quad 2-input OR gate--parts I had on hand.
 * The NANO is connected to the 74LS04 inverter, whose output is
 * connected to the 74LS10 triple 3-input NAND gates. The output of
 * the 74LS10 is inverted again with another 74LS04 which drives 
 * the 74LS32 quad 2-input OR gate acting as a 4-input OR gate. The
 * output of the 74LS32 is the odd parity bit which is read by the
 * NANO. Unused inputs are tied to ground.
 *****************************************************************
 * ATTENTION: This circuit was greatly simplified by using the XOR
  * gate in the 74LS86 quad 2-input XOR gate. The XOR gate is the
  * only gate needed to implement the odd parity generator. The
  * code remains the same.
 *****************************************************************
 * by Charles Stevenson (brucesdad13@gmail.com)
 * Revision History:
 * 2024-05-05: Initial version
 * 2024-05-06: Added delay comparable to debug print to keep timing
 * 2024-05-07: Made note of XOR gate simplification
 */
#include <Arduino.h>

#define DEBUG 1
#undef DEBUG // comment out to enable debugging
#define DELAY_US 16 // delay in microseconds if not debugging

void setup() {
  pinMode(PD4,OUTPUT); // MSB
  pinMode(PD3,OUTPUT); // middle bit
  pinMode(PD2,OUTPUT); // LSB
  pinMode(A4,INPUT);   // input
  Serial.begin(9600);  // initialize serial communication
}

void loop() {
  // pull all outputs low; makes oscilloscope trace easier to read
  digitalWrite(PD4, LOW);
  digitalWrite(PD3, LOW);
  digitalWrite(PD2, LOW);

#ifdef DEBUG
  Serial.println("Truth table for three-bit binary odd parity generator");
#endif

  // cycle through truth table for three-bit binary odd parity generator
  for (int i = 0; i < 0x8; i++) {
    digitalWrite(PD4, (i & 0x4) >> 2); // MSB
    digitalWrite(PD3, (i & 0x2) >> 1); // middle bit
    digitalWrite(PD2, (i & 0x1));      // LSB

#ifdef DEBUG
    Serial.print((i & 0x4) >> 2); // MSB
    Serial.print((i & 0x2) >> 1); // middle bit
    Serial.print((i & 0x1));      // LSB

    int input = digitalRead(A4); // read the input
    if (input) // check if the input is odd parity
      Serial.println(":Odd parity");
    else
      Serial.println(":Even parity");
#else
    delay(DELAY_US); // delay in microseconds
#endif
  }

  // pull all outputs low for 1 second; makes oscilloscope trace easier to read
  digitalWrite(PD4, LOW);
  digitalWrite(PD3, LOW);
  digitalWrite(PD2, LOW);
  delay(1000); // delay 1 second
}

#include <CapacitiveSensor.h>
#include <toneAC.h>
#include "pitch.h"

int vol = 0;
int fre = 0;
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4, 3);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4, 6);
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4, 7);
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4, 8);
CapacitiveSensor   cs_4_11 = CapacitiveSensor(4, 11);
CapacitiveSensor   cs_4_12 = CapacitiveSensor(4, 12);


void setup(){
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}


void loop(){  
   int sen = 150;
  
   long start = millis();
   long total1 =  cs_4_2.capacitiveSensor(30);
   long total2 =  cs_4_3.capacitiveSensor(30);
   long total3 =  cs_4_5.capacitiveSensor(30);
   long total4 =  cs_4_6.capacitiveSensor(30);
   long total5 =  cs_4_7.capacitiveSensor(30);
   long total6 =  cs_4_8.capacitiveSensor(30);
   long total7 =  cs_4_11.capacitiveSensor(30);
   long total8 =  cs_4_12.capacitiveSensor(30); 
    
   Serial.println(total1);
   Serial.println(total2);
   Serial.println(total3);
   Serial.println(total4);
   Serial.println(total5);
   Serial.println(total6);
   Serial.println(total7);
   Serial.println(total8);
   
   if (total1 > sen) {
     fre = NOTE_C4;   
     vol = 10;
   } else if (total2 > sen) {
     fre = NOTE_D4;
     vol = 10;
   } else if (total3 > sen) {
     fre = NOTE_E4;
     vol = 10;
   } else if (total4 > sen) {
     fre = NOTE_F4;
     vol = 10;
   } else if (total5 > sen) {
     fre = NOTE_G4;
     vol = 10;
   } else if (total6 > sen) {
     fre = NOTE_A4;
     vol = 10;
   } else if (total7 > sen) {
     fre = NOTE_B4;
     vol = 10;
   } else if (total8 > sen) {
     fre = NOTE_C5;
     vol = 10;
   } else {
     vol = 0;
   }
   
   toneAC(fre, vol); 
   Serial.println(vol);
}

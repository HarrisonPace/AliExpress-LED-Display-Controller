/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Seven Segment Hex Display Map */

   //OFF ~0x00
   //0- ~0x3F
   //1- ~0x06
   //2- ~0x5B
   //3- ~0x4F
   //4- ~0x66
   //5- ~0x6D
   //6- ~0x7D
   //7- ~0x07
   //8- ~0x7F
   //9- ~0x67 or ~0x6F
   //C- ~0x39
   //c- ~0x59
   //-  ~0x40

 /* With Dot '.' */

   //OFF ~0x80
   //0- ~0xBF
   //1- ~0x86
   //2- ~0xDB
   //3- ~0xCF
   //4- ~0xE6
   //5- ~0xED
   //6- ~0xFD
   //7- ~0x87
   //8- ~0xFF
   //9- ~0xE7 or ~0xEF
   //C- ~0xB9
   //c- ~0xD9
   //-  ~0xC0

/* End */

#include "Arduino.h"

#define LATCH D2
#define CLK D1
#define DATA D0

//This is the hex value of each number stored in an array by index num
byte digitOne[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
byte digitTwo[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
byte digitThree[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
byte digitFour[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

void setup(){

  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);

}

void loop(){

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<10; k++){
        for(int l=0; l<10; l++){
          digitalWrite(LATCH, LOW);
          shiftOut(DATA, CLK, MSBFIRST, ~digitFour[l]); // digitTwo
          shiftOut(DATA, CLK, MSBFIRST, ~digitThree[k]); // digitTwo
          shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[j]); // digitTwo
          shiftOut(DATA, CLK, MSBFIRST, ~digitOne[i]); // digitOne
          digitalWrite(LATCH, HIGH);
          delay(50);
        }
      }
    }
  }
  
}

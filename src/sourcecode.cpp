#include <LedControl.h> //Library LedControl 
 // Atur pin sesuai dengan koneksi display matrix 8x8 
 const int DIN_PIN = 2; 
 const int CS_PIN = 3; 
 const int CLK_PIN = 4; 

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

  byte SenyumMataBuka[8] = { 
     B00000000, 
     B01100100, 
     B01100010, 
     B00000010, 
     B00000010, 
     B01100010, 
     B01100100, 
     B00000000, 
 };  
 byte SenyumMataTutup[8] = { 
     B00000000, 
     B00100100, 
     B00100010, 
     B00000010, 
     B00000010, 
     B00100010, 
     B00100100, 
     B00000000,
 };  
 // Membuat Animasi Hati 
 void Senyum(){ 
   // Tampilkan Hati Sangat Kecil 
   for (int row = 0; row < 8; row++) { 
     lc.setRow(0, row, SenyumMataTutup[row]); 
     
   } 
  
   delay(200);
 //  lc.clearDisplay(0);
   delay(200);// Jeda 0.2 detik 
  // Tampilkan Hati Kecil 
   for (int row = 0; row < 8; row++) { 
     lc.setRow(0, row, SenyumMataBuka[row]); 
   } 
   delay(150); // Jeda 0.15 detik
 } 
void setup() {
  // put your setup code here, to run once:
lc.shutdown(0, false);  // Aktifkan chip 
   lc.setIntensity(0, 0); // Atur intensitas cahaya matriks (0-15) 
   lc.clearDisplay(0);    // Hapus tampilan matriks 

}

void loop() {
  // put your main code here, to run repeatedly:
Senyum();
}

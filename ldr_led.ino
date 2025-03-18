//Mendefinisikan pin
const int ldrPin = A0;    // Pin analog untuk LDR
const int ledPin = 9;     // Pin PWM untuk LED

//Variabel untuk menyimpan nilai
int ldrValue = 0;        // Nilai pembacaan LDR
int ledBrightness = 0;   // Kecerahan LED (0-255)

//Konfigurasi ambang batas
const int thresholdDark = 300;    // Nilai ambang batas gelap
const int thresholdBright = 700;  // Nilai ambang batas terang

void setup() {
  //Inisialisasi komunikasi serial
  Serial.begin(9600);
  
  //Konfigurasi pin
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Membaca nilai dari sensor LDR
  ldrValue = analogRead(ldrPin);
  
  //Menampilkan nilai LDR di Serial Monitor
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);
  
  //Menentukan kecerahan LED berdasarkan nilai LDR
  //Menggunakan map untuk mengkonversi nilai LDR ke kecerahan LED
  //Semakin gelap (nilai LDR rendah), LED semakin terang
  if (ldrValue < thresholdDark) {
    //Kondisi gelap, LED menyala penuh
    ledBrightness = 255;
  } else if (ldrValue > thresholdBright) {
    //Kondisi terang, LED meredup
    ledBrightness = 0;
  } else {
    //Kondisi antara gelap dan terang, LED menyala dengan kecerahan proporsional
    ledBrightness = map(ldrValue, thresholdBright, thresholdDark, 0, 255);
  }
  
  //Menampilkan kecerahan LED di Serial Monitor
  Serial.print("Kecerahan LED: ");
  Serial.println(ledBrightness);
  
  //Mengatur kecerahan LED
  analogWrite(ledPin, ledBrightness);
  
  //Menunggu sebentar sebelum pembacaan berikutnya
  delay(100);
}
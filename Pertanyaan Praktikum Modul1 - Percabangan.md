Pertanyaan Praktikum
1. Pada kondisi apa program masuk ke blok if? 
2. Pada kondisi apa program masuk ke blok else? 
3. Apa fungsi dari perintah delay(timeDelay)? 
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati), ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang → mati dan berikan penjelasan disetiap baris kode nya!

Jawab:
1. Program akan masuk ke blok if ketika kondisi terpenuhi, yaitu: 

if (timeDelay <= 100)

Artinya: Jika nilai timeDelay kurang dari atau sama dengan 100 ms, maka program masuk ke blok if.
Kondisi ini biasanya terjadi setelah proses pengurangan delay secara bertahap (LED makin cepat berkedip).

2. Program masuk ke blok else ketika kondisi if tidak terpenuhi, yaitu:

timeDelay -= 100;

Artinya: Delay akan dikurangi 100 ms setiap siklus → LED berkedip semakin cepat.

3. Fungsi dari delay(timeDelay) adalah untuk memberikan jeda waktu (delay) dalam satuan milidetik dan mengatur lama LED menyala atau mati.

4. Modifikasi program (cepat → sedang → mati, tidak langsung reset):
const int ledPin = 6;     // Menentukan pin LED pada pin digital 6
int timeDelay = 1000;     // Delay awal (LED berkedip lambat)

void setup() { 
  pinMode(ledPin, OUTPUT);   // Mengatur pin LED sebagai output
}

void loop() { 
  // Menyalakan LED
  digitalWrite(ledPin, HIGH);  
  delay(timeDelay);           // Tunggu sesuai delay

  // Mematikan LED
  digitalWrite(ledPin, LOW);  
  delay(timeDelay);           // Tunggu sesuai delay

  // Percabangan perubahan kecepatan
  if (timeDelay <= 200) {     
    // Jika sudah sangat cepat (<=200 ms)
    timeDelay = 500;          
    // Ubah ke kecepatan sedang

  } else if (timeDelay <= 500) {  
    // Jika sudah kecepatan sedang
    timeDelay = 0;            
    // LED akan mati (delay 0 → tidak berkedip)

  } else {  
    // Jika masih lambat
    timeDelay -= 200;         
    // Percepat kedipan LED secara bertahap
  }

  // Jika delay = 0, matikan LED permanen
  if (timeDelay == 0) {
    digitalWrite(ledPin, LOW); // Pastikan LED mati
    while(true);               // Hentikan program (tidak reset)
  }
}


Penjelasan alur baru program:
Awal → LED berkedip lambat (1000 ms)
Masuk else → delay dikurangi → jadi lebih cepat
Saat delay ≤ 200 → masuk kondisi:
Diubah ke sedang (500 ms)
Setelah itu:
Masuk kondisi berikutnya → delay jadi 0
Saat timeDelay == 0:
LED mati permanen
Program berhenti (while(true))
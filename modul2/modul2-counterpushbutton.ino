//Inisiasi program
const int a = 8;  //menampilkan segment "a"
const int b = 9;  //menampilkan segment "b"
const int c = 4;  //menampilkan segment "c"
const int d = 5;  //menampilkan segment "d"
const int e = 6;  //menampilkan segment "e"
const int f = 2;  //menampilkan segment "f"
const int g = 3;  //menampilkan segment "g"

bool bPress = false;
const int buttonPin = 10;

int buttonPushCounter = 0; //menyimpan angka atau nomor ketika ditekan
int buttonState = 0;       //memproses status sekarang pada tombol
int lastButtonState = 0;   //memproses status sebelumnya pada tombol

void setup() {
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode( buttonPin , INPUT_PULLUP );
  Serial.begin(9600);
  displayDigit(buttonPushCounter);
}

// Perulangan
void loop() {
   buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      bPress = true;
      buttonPushCounter++;
      if( buttonPushCounter > 9) buttonPushCounter =0 ;
      Serial.println("on");
    
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  if( bPress ){
     turnOff();
     displayDigit(buttonPushCounter);
  }
}

// Menyalakan tampilan
void displayDigit(int digit)
{
 //kondisi ketika segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //kondisi ketika segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //kondisi ketika segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //kondisi ketika segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //kondisi ketika segment e
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //kondisi ketika segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);

 //kondisi ketika segment g
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);

}

// Mematikan Tampilan
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

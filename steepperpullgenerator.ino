// signal generator for rsteper motors arduino mega on pin3. function slow acceleration to allow pump to ramp up 


long mDelay1 = 600;
long mDelayDEF = 600;
const int ENpin = A0;
const int stepPin = 3;
boolean stepbool = false;
int c2=0;
long c1=0;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(ENpin, OUTPUT);
digitalWrite(ENpin, LOW);

}

void loop() {
if (digitalRead(ENpin)==HIGH){
 do {
  digitalWrite(stepPin, HIGH);
    delayMicroseconds(mDelay1);
    c1++;
    digitalWrite(stepPin, LOW);
      delayMicroseconds(mDelay1);    
      if (c1==100){
        c1=0;
      if (mDelay1>6){
        mDelay1--;
      }
      }
   } while (digitalRead(ENpin)== HIGH);
   mDelay1 = mDelayDEF;
}
}

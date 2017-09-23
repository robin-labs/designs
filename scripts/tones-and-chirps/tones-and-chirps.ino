#define OUT_PIN 3
#define LISTEN 0

void setup() {
  pinMode(OUT_PIN,OUTPUT);
}

void loop() {
    linearSweep(20000,50000,15);
    delay(1000);
}

void playTone(int freq, float duration, bool thenOff) {
  tone(OUT_PIN,freq,duration);
  delayMicroseconds(1000 * duration);
  if(thenOff) {
    noTone(OUT_PIN);
  }
}

void linearSweep(int start_freq, int end_freq, int duration) {
  int intervals = 30;
  float perDuration = float(duration) / intervals;
  for(int i = 0; i <= intervals; i++ ) {
    float f = start_freq + (end_freq - start_freq) * (float(i) / intervals);
    tone(OUT_PIN,f);
    delayMicroseconds(1000 * perDuration);
  }
  noTone(OUT_PIN);
}


/*
  

 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;


int low = 36;
int high = 255;
int stride = 5;
int counter = low;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  //pinMode(ledPin, OUTPUT);
  
  //pins 6-13 are output
  DDRD = B11100000;
  DDRB = B00111111;
  
  cli();//stop interrupts
  //set timer0 interrupt at 2kHz
  TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);
  sei();//allow interrupts
}

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  int button1 = digitalRead(buttonPin1);
  if (button1) return;
  
  counter += stride;
  if (counter > high) {
    counter = low;
    //Serial.println(counter);
  }

  // write to the digital pins  
  writeByte(counter);
}

void writeByte(int x) {
  int pin;
  int temp;
  for (pin=13; pin>=6; pin--) {
    if (pin > 7) {
      temp = (pin-8);
      int tempPortB = (x&1)>>temp;
      PORTB |= tempPortB;
    }
    else {
      temp = pin;
      int tempPortB = (x&1)>>temp;
      PORTD |= tempPortB;
    }
    x >>= 1;
  }

  PORTB ^= B00111111;
  PORTD ^= B11111110;
}


void loop() {

}

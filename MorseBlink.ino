/*
  MorseBlink
  Turns a string into a Morse Code sequence
  
  created July 31 2014
  by Marcos Labad
 */
 
 int led = 13; 

 // set the dot duration. Any other depend on it
 int dotDuration = 500;
 
 int dashDuration = dotDuration * 3;
 int silenceDuration = dotDuration;
 int letterSeparator  = dashDuration; 
 int wordSeparator = dotDuration * 7; 
 
 int i;
 
 char message[] = "SOS";
 
// setup func
void setup() {
  // initialize digital pin 13, Arduino UNO built in
  pinMode(13, OUTPUT);
  // initialize Serial
  Serial.begin(9600);
}

// loop func
void loop() {
  
  for (i = 0; i < sizeof(message) - 1; i++) {
      switch (message[i]) {
        case 'S':
          Serial.print("S");        
          dot(); 
          silence();
          dot();
          silence();
          dot();
        break; 
        case 'O':
          Serial.print("O");
          dash();
          silence();
          dash();
          silence();
          dash();
        break;
        case ' ':
          Serial.print(" ");        
          wordSpace();
        break;
        default: 
          Serial.print("ERROR");    
          // do nothing   
          digitalWrite(led, LOW); 
      }
      Serial.print("--LETTER--");    
      letter();
  }
    Serial.print("--WORD--");   
    wordSpace();  
}

void dash() {
   digitalWrite(led, HIGH);   
   delay(dashDuration); 
}

void dot() {
   digitalWrite(led, HIGH);   
   delay(dotDuration); 
}

void silence() {
   digitalWrite(led, LOW);  
   delay(silenceDuration);   
}

void letter() {
   digitalWrite(led, LOW);  
   delay(letterSeparator);   
}

void wordSpace() {
   digitalWrite(led, LOW);  
   delay(wordSeparator);   
}

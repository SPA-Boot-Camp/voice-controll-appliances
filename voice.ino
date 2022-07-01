String voice;     //String type variable declared
int 
ledPin = 2,       
fanPin = 3,
tvPin = 4; 

/* Turn ON all appliances*/
void allon(){
     digitalWrite(ledPin, HIGH); 
     digitalWrite(fanPin, HIGH); 
     digitalWrite(tvPin, HIGH);
     }

/* Turn OFF all appliances*/
void alloff(){
     digitalWrite(ledPin, LOW); 
     digitalWrite(fanPin, LOW);
     digitalWrite(tvPin, LOW); 
     
}
  
 void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(fanPin, OUTPUT); 
  pinMode(tvPin, OUTPUT);
 
}

 void loop() {
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
     
  
    
  if(voice == "*everything on")
  {
    allon();
  }  
  
  else if(voice == "*everything off")
    {
      alloff();
    } 
  
  /* Turn ON using particular command*/
  else if(voice == "*fan on") 
    {
      digitalWrite(fanPin, HIGH);
    } 
 
  else if(voice == "*light on")
    {
      digitalWrite(ledPin, HIGH);
    }

  else if(voice == "*tv on")
  {
    digitalWrite(tvPin, HIGH);
  }
  
  else if(voice == "*all on")
    {
      digitalWrite(ledPin, HIGH); 
      digitalWrite(fanPin, HIGH);
      digitalWrite(tvPin, HIGH);}
 
  /* Turn off using particular command */ 
  else if(voice == "*fan off")
    {
      digitalWrite(fanPin, LOW);
    } 
  
  else if(voice == "*light off")
    {
      digitalWrite(ledPin, LOW);
    }

  else if(voice == "*tv off")
  {
    digitalWrite(tvPin, LOW);
  }
  
  else if(voice == "*all off")
    {
      digitalWrite(ledPin, LOW);
      digitalWrite(fanPin, LOW);
      digitalWrite(tvPin, LOW);
    }
  
voice="";}}

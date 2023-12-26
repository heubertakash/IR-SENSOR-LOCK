#define IRA 2 
#define IRB 3
#define IRC 4
#define IRD 5 

#define RELAY_PIN       8
int KeyA=0;//password(0101)
int KeyB=1;
int KeyC=0;
int KeyD=1;

void setup() 
{
  Serial.begin(9600);   
  pinMode(IRA, INPUT);
  pinMode(IRB, INPUT);
  pinMode(IRC, INPUT);
  pinMode(IRD, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  }

void loop() 
{  

if(digitalRead(IRA) == KeyA && digitalRead(IRB) == KeyB  && digitalRead(IRC) == KeyC  && digitalRead(IRD) == KeyD)
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(13,HIGH);
    delay(5000); 
   digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(13,LOW);
  }
  else {  
  digitalWrite(RELAY_PIN, HIGH); 
    digitalWrite(13,LOW);
    }
}

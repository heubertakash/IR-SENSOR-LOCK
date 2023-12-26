/*Skynet Robotics*/

#include <IRremote.h>
int IRpin = A0;    
int relay1=8;
int relay2=9;
int relay3=10;
int relay4=11;
IRrecv irrecv(IRpin);
decode_results results;
int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;

long int B1_code=12582913;   //enter your remote button1 code here
long int B2_code=12582914;
long int B3_code=1258565;
long int B4_code=1258291;

void setup()
{
 Serial.begin(9600);
 pinMode(relay1,OUTPUT);
 pinMode(relay2,OUTPUT);
 pinMode(relay3,OUTPUT);
 pinMode(relay4,OUTPUT);
 digitalWrite(relay1,HIGH);
  
  irrecv.enableIRIn(); // Start the receiver
}
void loop() 
{
 if (irrecv.decode(&results)) 
   {
    Serial.println(results.value, DEC);
//Serial.println(B1_code);
    if(results.value==B1_code && flag1==0)
    {
      
      digitalWrite(relay1,LOW);
      flag1=1;
    }
    else if(results.value==B1_code && flag1==1)
    {
      digitalWrite(relay1,HIGH);
      flag1=0;
     }
    if(results.value==B2_code && flag2==0)
    {      
      digitalWrite(relay2,LOW);
      flag2=1;
    }
   else if(results.value==B2_code && flag2==1)
    {
      digitalWrite(relay2,HIGH);
      flag2=0;    
    }
    if(results.value==B3_code && flag3==0)
    {      
      digitalWrite(relay3,LOW);
      flag3=1;
    }
    else if(results.value==B3_code && flag3==1)
    {
      digitalWrite(relay3,HIGH);
      flag3=0;    
    }
    if(results.value==B4_code && flag4==0)
    {      
      digitalWrite(relay4,LOW);
      flag4=1;
    }
    else if(results.value==B4_code && flag4==1)
    {
      digitalWrite(relay4,HIGH);
      flag4=0;    
    }
    delay(500);
     irrecv.resume();   // Receive the next value
   }
}
    

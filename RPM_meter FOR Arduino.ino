/**
 * PIN - 3 -> INTERUPT PIN [IR INPUT]
 * PIN - 7 -> RELAY OUTPUT [0 -> IF PUMP MOTOR SPINNING | 1 -> IF NOT SPINNING]
 */
 
float REV = 0;
int RPM_VALUE;
int PREVIOUS = 0;
int TIME;

void INTERRUPT()
{
  REV++;
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  attachInterrupt(1, INTERRUPT, RISING);
}

void loop()
{
  delay(1000);
  detachInterrupt(0);                   
  TIME = millis() - PREVIOUS;          
  RPM_VALUE = (REV/TIME) * 60000;       
  PREVIOUS = millis();                  
  REV = 0;
  if(RPM_VALUE>120)
   digitalWrite(7, HIGH);
  else
   digitalWrite(7, LOW);
  attachInterrupt(1, INTERRUPT, RISING);
}

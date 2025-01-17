uint8_t GPIO_Pin = D6;

float REV = 0;
int RPM_VALUE;
int PREVIOUS = 0;
int TIME;

void ICACHE_RAM_ATTR handleInterrupt() {
  REV++; fdds
}

void setup() {
  Serial.begin(9600);
  // pinMode(GPIO_Pin, INPUT_PULLUP);
  pinMode(D4, OUTPUT);
  pinMode(D6, INPUT);
  digitalWrite(D4, HIGH);
  attachInterrupt(digitalPinToInterrupt(GPIO_Pin), handleInterrupt, RISING);
}

void loop() {
  delay(1000);
  detachInterrupt(digitalPinToInterrupt(GPIO_Pin));
  TIME = millis() - PREVIOUS;
  RPM_VALUE = (REV / TIME) * 60000;
  PREVIOUS = millis();
  REV = 0;
  if (RPM_VALUE > 400) {
    digitalWrite(D4, LOW);
  } else
    digitalWrite(D4, HIGH);
  Serial.println(RPM_VALUE);
  attachInterrupt(digitalPinToInterrupt(GPIO_Pin), handleInterrupt, RISING);
}
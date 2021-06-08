int i, x, y, z, Oxor, Oxnor;
int sum = 0;
void setup() {
  Serial.begin(9600);
  for( i=4;i<=13;i++)
    pinMode(i, OUTPUT);
}

void loop() {
  Serial.println("Enter values for the logic gate: Y/N");
  delay(2000);
  
  /* taking the three inputs and glowing the corresponding LEDs
     0/False - Red
     1/True - Green */
  
  
  Serial.print("Enter value of X:\t ");
  while(Serial.available()==0){}
  x=Serial.parseInt();
  Serial.println(x);
  Serial.read();
  
  if(x==0)
    digitalWrite(13, HIGH);
  else
    digitalWrite(12, HIGH);
  
  Serial.print("Enter value of Y:\t ");
  while(Serial.available()==0){}
  y=Serial.parseInt();
  Serial.println(y);
  Serial.read();
  
  if(y==0)
    digitalWrite(11, HIGH);
  else
    digitalWrite(10, HIGH);
  
  
  Serial.print("Enter value of Z:\t ");
  while(Serial.available()==0){}
  z=Serial.parseInt();
  Serial.println(z);
  
   if(z==0)
    digitalWrite(9, HIGH);
  else
    digitalWrite(8, HIGH);
  
  
  Serial.print("x\ty\tz");
  Serial.print("\n");
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.print("\n");
  
  //checking if number of true inputs are odd or even
  
  if (x==1) 
    sum++;
  if (y==1)
    sum++;
  if (z==1)
    sum++;
  if (sum%2==0)
  {
    Oxor = 0;
    Oxnor = 1;
  }
  else
  {
    Oxor = 1;
    Oxnor = 0;
  }
  
  Serial.print("XOR OUTPUT -\t");
  Serial.print(Oxor);
  
  if(Oxor==0)
    digitalWrite(7, HIGH);
  else
    digitalWrite(6, HIGH);
  
  Serial.print("\n");
  
  Serial.print("X-NOR OUTPUT -\t");
  Serial.print(Oxnor);
  
    if(Oxnor==0)
    digitalWrite(5, HIGH);
  else
    digitalWrite(4, HIGH);
  
  Serial.print("\n");
  sum = 0;
  delay(5000);
   for( i=4;i<=13;i++)
    digitalWrite(i, LOW);
}
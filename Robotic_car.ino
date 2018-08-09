#define m11 2   // left motor1
#define m12 4    // left motor2
#define m21 6    // right motor1
#define m22 9     //right motor2

void left()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, HIGH);
}

void right()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   delay(1000); 
}

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   delay(1000);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   delay(1000);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() 
{
  while(Serial.available()>0)
  {
    char ch=Serial.read();
    
    if(ch=='1')
    {
     Serial.println("Forward");
     forward();
    }

    else if(ch=='2')
    {
     Serial.println("Left");
     left();
    }

    else if(ch=='3')
    {
      Serial.println("Right");
      right();
    }
    
    else if(ch=='4')
    {
      Serial.println("Backward");
      backward();
    }

    else if(ch=='5')
    {
      Serial.println("Stop");
      Stop();
    }
    delay(100);
  }
}

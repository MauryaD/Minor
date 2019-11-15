void setup() {
  // pin 0 and 1 == Rx and Tx resp, are connected with Tx and Rx of Bolt.
  pinMode(2,INPUT); //pin connected to BOLT   frwd -> P1
  pinMode(4,INPUT); //pin connected to BOLT   bkwd -> P2
  pinMode(7,INPUT); //pin connected to BOLT   lft -> P3
  pinMode(8,INPUT); //pin connected to BOLT   ryt -> P4

  pinMode(5,OUTPUT); //for motors
  pinMode(6,OUTPUT); //5-6 M1
  pinMode(10,OUTPUT);  //9-10 M2
  pinMode(9,OUTPUT); //for motors

  pinMode(12, OUTPUT);  //for dist
  pinMode(11, INPUT);
}

void calcdist()
{
  float duration, distance;
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration = pulseIn(11, HIGH);
  distance = (duration*.0343)/2;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  //delay(100);  
  if(distance < 20)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
    }
}

void loop() {
 // calcdist();
  int left, right, forward, backward;
  forward = digitalRead(2); //p1
  backward = digitalRead(4);  //p2
  left = digitalRead(7);  //p3
  right = digitalRead(8);  //p4
  
  if(forward == 1)   //p1
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }
  
  if(backward == 1)  //p2
  {
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
  if( left == 1)  //p3
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
  if(right == 1)   //p4
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }


  
}

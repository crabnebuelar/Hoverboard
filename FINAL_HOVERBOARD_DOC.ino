// Servo - Version: Latest 
#include <Servo.h>

// SoftwareSerial - Version: Latest 
#include <SoftwareSerial.h>


SoftwareSerial BT(1, 0);
int leftMotorPin = 4;
int rightMotorPin = 2;
Servo leftMotor;
Servo rightMotor;
String a;

int goPin = 8;
int onPin = 6;
Servo goMotor;
Servo onMotor;

void setup() {
    BT.begin(9600);
    BT.setTimeout(10);
    pinMode(leftMotorPin,OUTPUT);
    pinMode(rightMotorPin,OUTPUT);
    pinMode(13, OUTPUT);
    leftMotor.attach(leftMotorPin);
    rightMotor.attach(rightMotorPin);
    BT.println("Ready for Bruh Moments");
    
    pinMode(onPin,OUTPUT);
    onMotor.attach(onPin);
    pinMode(goPin, OUTPUT);
    goMotor.attach(goPin);
}

void loop() {
  if(BT.available() > 0)
  {
    a=(BT.readString());
  if(a.substring(0, 1).equals("?"))
  {
    BT.println("placeholder, retard");
  }
  else if (a.substring(0, 1).equals("L") or (a.substring(0, 1)).equals("R"))
  {
    String direction = a.substring(0, 1);
    int seconds = (a.substring(1)).toDouble();
    if(direction.equals("L"))
    {
      BT.println("Turning Left");
      leftMotor.writeMicroseconds(1000);
      rightMotor.writeMicroseconds(1000);
      delay( (int) (seconds * 1000.0));
      leftMotor.writeMicroseconds(1500);
      rightMotor.writeMicroseconds(1500);
    }
    else
    {
      BT.println("Turning Right");
      leftMotor.writeMicroseconds(2000);
      rightMotor.writeMicroseconds(2000);
      delay( (int) (seconds * 1000.0));
      leftMotor.writeMicroseconds(1500);
      rightMotor.writeMicroseconds(1500);
    }
    
  }
  else if (a.substring(0, 1).equals("C"))
  {
    if(a.equals("Clock"))
    {
      leftMotor.writeMicroseconds(2000);
      rightMotor.writeMicroseconds(2000);
    }
    else if(a.equals("Counter"))
    {
      leftMotor.writeMicroseconds(1000);
      rightMotor.writeMicroseconds(1000);
    }
  }
  else if (a.substring(0, 4).equals("Stop"))
  {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1500);
  }
  else if (a.substring(0, 2).equals("Go"))
  {
    goMotor.writeMicroseconds(2000);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
    goMotor.writeMicroseconds(1500);
  }
  else if (a.substring(0,2).equals("On"))
  {
    onMotor.writeMicroseconds(2000);
    delay(2000);
    onMotor.writeMicroseconds(1500);
  }
  else if (a.substring(0, 4).equals("UnGo"))
  {
    goMotor.writeMicroseconds(1000);
    delay(2000);
    goMotor.writeMicroseconds(1500);
  }
  else if (a.substring(0, 3).equals("Off"))
  {
    onMotor.writeMicroseconds(1000);
    delay(2000);
    onMotor.writeMicroseconds(1500);
  }
  else
  {
    BT.println("This doesn't work, retard");
  }
  }
}

/*
void serialEvent() {
  a=(BT.readString());
  if(a.equals("?"))
  {
    BT.println("placeholder, retard");
  }
  else if (a.substring(0, 1).equals("L") or (a.substring(0, 1)).equals("R"))
  {
    String direction = a.substring(0, 1);
    int seconds = (a.substring(1)).toDouble();
    if(direction.equals("L"))
    {
      BT.println("Turning Left");
      leftMotor.writeMicroseconds(1000);
      rightMotor.writeMicroseconds(1000);
      delay( (int) (seconds * 1000.0));
      leftMotor.writeMicroseconds(1500);
      rightMotor.writeMicroseconds(1500);
    }
    else
    {
      BT.println("Turning Right");
      leftMotor.writeMicroseconds(2000);
      rightMotor.writeMicroseconds(2000);
      delay( (int) (seconds * 1000.0));
      leftMotor.writeMicroseconds(1500);
      rightMotor.writeMicroseconds(1500);
    }
    
  }
  else if (a.substring(0, 1).equals("C"))
  {
    if(a.equals("Clock"))
    {
      leftMotor.writeMicroseconds(2000);
      rightMotor.writeMicroseconds(2000);
    }
    else if(a.equals("Counter"))
    {
      leftMotor.writeMicroseconds(1000);
      rightMotor.writeMicroseconds(1000);
    }
  }
  else if (a.equals("Stop"))
  {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1500);
  }
  else
  {
    BT.println("This doesn't work, retard");
  }
}
*/

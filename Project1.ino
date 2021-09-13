// Smart Solar Cell_ Mini Project//

#include <Servo.h>
//Define Servo
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160; //High angle of Servohori
int servohLimitLow = 15; //Low angle of Servohori
Servo servoverti;
int servov = 0;
int servovLimitHigh = 160; //High angle of Servoverti
int servovLimitLow = 15; //Low angle of Servoverti
//Assigning LDRs
int ldrtopl = 2; //LDR Top left connect to pin Analog A2
int ldrtopr = 1; //LDR Top right connect to pin Analog A1
int ldrbotl = 3; //LDR Bottom left connect to pin Analog A3
int ldrbotr =0; //LDR Bottom right connect to pin Analog A0

void setup() {

  Serial.begin(9600);
  servohori.attach(10); //Servo horizontal connect to PWM 10
  servohori.write(45); // Start Position of Servo horizontal
  servoverti.attach(6); //Servo vertical connect to PWM 6
  servoverti.write(60); // Stat Position of Servo vertical
  delay(2000);
  

}

void loop() {
  servoh = servohori.read();
  servov = servoverti.read();

 // Capturing analog values of each LDR

 int topl = analogRead(ldrtopl); //LDR Top Left
 int topr = analogRead(ldrtopr); //LDR Top Right
 int botl = analogRead(ldrbotl); //LDR Bottom Left
 int botr = analogRead(ldrbotr); //LDR Bottom Right

  
 //Calculating average

 int avgtop = (topl+topr)/2;
 int avgbot = (botl+botr)/2;
 int avgleft = (topl+botl)/2;
 int avgright = (topr+botr)/2;
// Serial Monitor read Value Average
  Serial.print(avgtop);
  Serial.print("\n");
  Serial.print(avgbot);
  Serial.print("\n------------------------\n");
  Serial.print(avgleft);
  Serial.print("\n");
  Serial.print(avgright);
  Serial.print("\n");
 

 if (avgtop < avgbot)
{
  servohori.write(servoh-1);
  if (servoh > servohLimitHigh)
{

  servoh = servohLimitHigh;

}
delay(1);
}

else if ( avgbot < avgtop)
{
  servohori.write(servoh+1);
  if (servoh < servohLimitLow)
  {
    servoh = servohLimitLow;
  }
  delay(1);
}

else
{
  servohori.write(servoh);
}

if (avgleft > avgright)
{
  servoverti.write(servov-1);
  if (servov > servovLimitHigh)
  {
    servov = servovLimitHigh;
  }
  delay(1);
}
else if (avgright > avgleft)
{
  servoverti.write(servov+1);
  if (servov <servovLimitLow)
  {
    servov = servovLimitLow;
  }
  delay(1);
}
else
{
  servoverti.write(servov);
}

delay(150);
}





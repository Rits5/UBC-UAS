#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

//optimal accurarcy range 13 cm - 25 cm
//expect +/- 3cm out of this range

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  
  // 5v
  double volts = analogRead(sensor);
  //according to recalibration, find distance y = -6E-07x^3 + 0.0008x^2 - 0.3615x + 71.443
  double distance = -0.0000006*pow(volts, 3)+ 0.0008*pow(volts, 2)-0.3615*volts + 71.443 - 2.5; // worked out from datasheet graph
  delay(200); // slow down serial port 
  
  if (distance <= 100 && distance >= 0){
    Serial.println(distance);   // print the distance
  }
  
}


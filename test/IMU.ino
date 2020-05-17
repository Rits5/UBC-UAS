#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

float cur_x;
float cur_y;
float cur_z;

float prev_x;
float prev_y;
float prev_z;

int count = 0;
 
void setup(void) 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.println("Orientation Sensor Test"); Serial.println("");  
  
  /* Initialise the sensor */
  if(!bno.begin()){
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);

  imu::Vector<3> acc = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  prev_x = acc.x();
  prev_y = acc.y();
  prev_z = acc.z();
}
 
void loop(void){

  imu::Vector<3> acc = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

  prev_x = cur_x;
  prev_y = cur_y;
  prev_z = cur_z;
  
  cur_x = acc.x();
  cur_y = acc.y();
  cur_z = acc.z();

    
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
//  /* Display the floating point data */
//  Serial.print("X: ");
//  Serial.print(event.orientation.x, 4);
//  Serial.print("\tY: ");
//  Serial.print(event.orientation.y, 4);
//  Serial.print("\tZ: ");
//  Serial.print(event.orientation.z, 4);
//  Serial.println("");

  int temp = bno.getTemp();
  
  Serial.print("x = ");
  Serial.print(acc.x());
  Serial.print(", y = ");
  Serial.print(acc.y());
  Serial.print(", z = ");
  Serial.print(acc.z());
  Serial.println("");

  if(fabs(cur_x - prev_x) < 0.5){
    Serial.println("x is stationary");
  }

  if(fabs(cur_y - prev_y) < 0.5){
    Serial.println("y is stationary");
  }
  
  if(fabs(cur_z - prev_z) < 0.1){
    Serial.println("z is stationary");
  }

  if(cur_z > -5.0 && count > 5){
    Serial.print("x = ");
    Serial.print(acc.x());
    Serial.print(", y = ");
    Serial.print(acc.y());
    Serial.print(", z = ");
    Serial.print(acc.z());
    Serial.println("");
    delay(100);
    exit(0);
  }
 
  delay(100);
  count++;
}

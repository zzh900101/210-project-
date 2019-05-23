int tmp102Address = 0x48;

float low_temp,high_temp;
float temp;

void setup(){

  Wire.begin();
  low_temp =25;
  high_temp = 50;
}

void loop(){

    temp = getTemperature();

    Particle.publish("temp", String(temp),PRIVATE);
    delay(2500); 
    
    if (temp <= low_temp)
    {
        Particle.publish("low");
    }
    
    else if (temp>low_temp && temp<=high_temp)
    {
        Particle.publish("mid");
    }
    
    else if (temp>low_temp)
    {
        Particle.publish("TEMP_LEVEL","HIGH",PRIVATE);///ifttt tigger
        Particle.publish("high");
    }
  }

//function to read the temperature, the function is write base on the code from: https://github.com/tirumalavan/BabyTemperatureSensor/blob/master/temperaturesensor2.ino
float getTemperature(){
  Wire.requestFrom(tmp102Address,2); 

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  int TemperatureSum = ((MSB << 8) | LSB) >> 4; 

  float celsius = TemperatureSum*0.0625;
  return celsius;
}

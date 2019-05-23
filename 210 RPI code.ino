int led_green = D1;
int led_org = D2;
int led_red = D3;
int fanpin = A0;     

void low_temp(const char *event, const char *data)
{
    digitalWrite(led_org,LOW);
    digitalWrite(led_red,LOW);
    digitalWrite(led_green,HIGH);
    analogWrite(fanpin,0);
}

void mid_temp(const char *event, const char *data)
{
    digitalWrite(led_org,HIGH);
    digitalWrite(led_red,LOW);
    digitalWrite(led_green,LOW);
    analogWrite(fanpin,200);
}

void high_temp(const char *event, const char *data)
{
    digitalWrite(led_org,LOW);
    digitalWrite(led_red,HIGH);
    digitalWrite(led_green,LOW);
    analogWrite(fanpin,255);
}



void setup() {
    pinMode(led_green, OUTPUT);
    pinMode(led_org, OUTPUT);
    pinMode(led_red, OUTPUT);
    pinMode(fanpin, OUTPUT);
    
    Particle.subscribe("low", low_temp);
    Particle.subscribe("mid", mid_temp);
    Particle.subscribe("high", high_temp);
    
    digitalWrite(led_green,HIGH);
    digitalWrite(led_org,HIGH);
    digitalWrite(led_red,HIGH);
    delay(1000);
    
    digitalWrite(led_green,LOW);
    digitalWrite(led_org,LOW);
    digitalWrite(led_red,LOW);
    
}

void loop() {


}
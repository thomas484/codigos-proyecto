 int d = 0;

void setup() {
 
   Serial.begin(9600);
}

void loop() {
   Serial.print("Dato: ");
   Serial.println(d);
   d++;
   if(d==1000)
   d=0;
   delay(1000);
}

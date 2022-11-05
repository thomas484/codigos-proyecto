


String palabra = "";
byte  entero = 68;
String stringUno = String(entero);


void setup() {
  // start serial port at 9600 bps:
    pinMode(LED_BUILTIN, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
 
  if (Serial.available()){
palabra = leer_puerto();
    if(palabra=="1") //convierte la cadena a el numero entero correspondiente palabra.toInt()
  digitalWrite(LED_BUILTIN, HIGH);
  else if(palabra=="2")
   digitalWrite(LED_BUILTIN, LOW);
   else if(palabra=="3")
   escribe_puerto(entero);
   delay(500);
  }
}

String leer_puerto(void){ //lee_el_puerto();
    String suma_de_char = "";
   char char_individual = Serial.read(); //lee el el valor desde el puerto
    if (int(char_individual)!=-1){ //pregunta si el char esta sin información nueva haciendo un cast a int 
      suma_de_char = suma_de_char + char_individual;
    }
    if (char_individual=='\n') //cuando desde la pc le damos enter detecta el fin de linea
     return suma_de_char;
  }
  void escribe_puerto(byte p){
    Serial.write(p);
    
    }
  

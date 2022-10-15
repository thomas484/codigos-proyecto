/*
 This program sends an ASCII A (byte of value 65) on startup and repeats that
  until it gets some data in. Then it waits for a byte in the serial port, and
  sends three sensor values whenever it gets a byte in.
*/
String palabra = "";


void setup() {
  // start serial port at 9600 bps:
    pinMode(LED_BUILTIN, OUTPUT);  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  } 
  establishContact();  // send a byte to establish contact until receiver responds 
}

void loop() {
 
  if (Serial.available()){
palabra = leer_puerto();
    if(palabra.toInt()==1) //convierte la cadena a el numero entero correspondiente
  digitalWrite(LED_BUILTIN, HIGH);
  else if(palabra.toInt()==2)
   digitalWrite(LED_BUILTIN, LOW);
   Serial.print(palabra);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A MANDA CARACTERES A HASTA QUE RECIBA ALGUN DATO DE INICIO DEL OTRO PROGRAMA EN C PARA LA INTERFAZ 
    delay(100);
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
  


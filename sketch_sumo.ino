// Puente H L293D
/*
ARDUINO   L293D(Puente H)        
  5          10
  6          15
  9          7
  10         2
  5V         1, 9, 16
  GND        4, 5, 12, 13
*/
const int transmisor = 12;
const int receptor =13; 

const int bton = 8;
int pulsador = 0;
int b1=0;
int b2=0;

int estado = 0;

int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10;
 
int vel = 255;
void setup() {
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(transmisor,OUTPUT);
  pinMode(receptor,INPUT);
  pinMode(bton,INPUT);
  digitalWrite(transmisor,LOW);
  Serial.begin(9600);

}
void emitirPulso(){
  digitalWrite(transmisor,HIGH);
  delayMicroseconds(10);
  digitalWrite(transmisor,LOW);
}
void delante(){
  analogWrite(derB, vel);  // Frente 2 segundos
    analogWrite(izqB, vel); 
}
void vuelta(){
  analogWrite(derA, vel);  // Derecha 0,5 segundos
  analogWrite(izqB, vel);
}
void detener(){
  analogWrite(derA, 0);    // Detiene los Motores
  analogWrite(izqA, 0);
   digitalWrite(derB, 0);  // Detiene los Motores
    analogWrite(izqB, 0);
  delay(600);
}
void operacion(){
   long tiempo;
  long distancia=0;    
      emitirPulso();
      tiempo = pulseIn(receptor,HIGH);
      distancia = tiempo/59;
      Serial.print("Distancia = ");
      Serial.println(distancia);
      if(distancia > 50){
        b1=1;
        if(b2!=0){
          detener();
          b2=0;
        }
        Serial.println("Delante");
        delante();
      }else{
        b2=1;
        if(b1!= 0){
          detener();
          b1=0;
        }
        Serial.println("Vuelta");
        vuelta();
       
      }      
      
}
void loop() {
  pulsador = digitalRead(bton);
  if(pulsador == HIGH){
     estado++;
  }
  Serial.println(estado);
  if(estado == 1){
    operacion();
  }else if(estado == 2){
   detener();
    estado = 0;
  }  
  delay(200);
    
 }

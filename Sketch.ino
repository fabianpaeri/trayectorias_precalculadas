// C++ code
//

#include <Servo.h>

static const uint8_t trayectorias[][51] = {
  {90,92.30769231,94.61538462,96.92307692,99.23076923,101.5384615,103.8461538,106.1538462,108.4615385,110.7692308,113.0769231,115.3846154,117.6923077,120,117.5,115,112.5,110,107.5,105,102.5,100,97.5,95,92.5,90,87.5,85,82.5,80,77.5,75,72.5,70,67.5,65,62.5,60,62.30769231,64.61538462,66.92307692,69.23076923,71.53846154,73.84615385,76.15384615,78.46153846,80.76923077,83.07692308,85.38461538,87.69230769,90},
  {90,99,108,117,126,135,126,117,108,99,90,81,72,63,54,45,54,63,72,81,90,99,108,117,126,135,126,117,108,99,90,81,72,63,54,45,54,63,72,81,90,99,108,117,126,135,126,117,108,99,90},
  {90,85.5,81,76.5,72,67.5,63,58.5,54,49.5,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,49.5,54,58.5,63,67.5,72,76.5,81,85.5,90},
  {90,85.5,81,76.5,72,67.5,63,58.5,54,49.5,45,40.5,36,31.5,27,22.5,18,13.5,9,4.5,0,0,0,0,0,0,0,0,0,0,0,4.5,9,13.5,18,22.5,27,31.5,36,40.5,45,49.5,54,58.5,63,67.5,72,76.5,81,85.5,90},
  {90,92,94,96,98,100,98,96,94,92,90,88,86,84,82,80,82,84,86,88,90,92,94,96,98,100,98,96,94,92,90,88,86,84,82,80,82,84,86,88,90,92,94,96,98,100,98,96,94,92,90}
};

/*---------------Variables globales-----------*/
int PIN_CABEZA = 3, 
	PIN_COLA = 5, 
	PIN_BRAZO_IZQUIERDO = 6, 
	PIN_BRAZO_DERECHO = 9, 
	PIN_ANTEBRAZO_IZQUIERDO = 10;

const int PERIODO = 100;

int iterador = 0;
unsigned long tiempo_transcurrido = 0; 
const static int PUNTOS = 51;

Servo cabeza, cola, brazoIzquierdo, brazoDerecho, antebrazoIzquierdo; 

void setup()
{
  Serial.begin(9600);
  while(!Serial){
  }
  Serial.println("Iniciando configuracion");
  
  cabeza.attach(PIN_CABEZA);
  cola.attach(PIN_COLA);
  brazoIzquierdo.attach(PIN_BRAZO_IZQUIERDO);
  brazoDerecho.attach(PIN_BRAZO_DERECHO);
  antebrazoIzquierdo.attach(PIN_ANTEBRAZO_IZQUIERDO);
  
  Serial.println("Servos configurados");
  
  cabeza.write(90);
  cola.write(90);
  brazoIzquierdo.write(90);
  brazoDerecho.write(90);
  antebrazoIzquierdo.write(90);
  
  Serial.println("Servos en posicion inicial");
  
  tiempo_transcurrido = millis();
}

void loop()
{
  unsigned long tiempo_actual = millis();
  if (tiempo_actual - tiempo_transcurrido < PERIODO){
    return;
  }
  
  
  Serial.print("Iniciando ciclo ");
  Serial.print(iterador);
  Serial.print(" total ");
  Serial.println(PUNTOS);
  
  Serial.print("Puntos: ");
  Serial.print(trayectorias[0][iterador]);
  Serial.print(", ");
  Serial.print(trayectorias[1][iterador]);
  Serial.print(", ");
  Serial.print(trayectorias[2][iterador]);
  Serial.print(", ");
  Serial.print(trayectorias[3][iterador]);
  Serial.print(", ");
  Serial.print(trayectorias[4][iterador]);
  Serial.println();
  
  cabeza.write(trayectorias[0][iterador]);
  cola.write(trayectorias[1][iterador]);
  brazoIzquierdo.write(trayectorias[2][iterador]);
  brazoDerecho.write(trayectorias[3][iterador]);
  antebrazoIzquierdo.write(trayectorias[4][iterador]);
      
  iterador++;
  if (iterador >= PUNTOS) {
    iterador = 0;
  }
  tiempo_transcurrido = millis();
}

#include <Unipolar.h>
#include <Servo.h>
#include <FSM.h>
#include "myStates.h"



//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*************************************AREA DE CONFIGURACION***********************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//A la hora de calibrar la máquina, vamos cambiando los parámetros de este área de configuración.
//Parámetros como retardos de tiempo y los ángulos de los servos.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////RETARDOS////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nota: retardo=offset de tiempo entre los sucesivos Estados.
unsigned long r1 = 1000; 
unsigned long r2 = 1000; 
unsigned long r3 = 1000; 
unsigned long r4 = 1000; 
unsigned long r5 = 1000; 
unsigned long r6 = 1000; 
unsigned long r7 = 1000; 
unsigned long r8 = 4500; 
unsigned long r9 = 1000; 
unsigned long r10 = 1000; 
unsigned long r11 = 1000; 
unsigned long r12 = 1000; 
unsigned long r13 = 500;
unsigned long r14 = 1000;
unsigned long r15 = 1000;
unsigned long r16 = 300;
unsigned long r17 = 300;
unsigned long r18 = 2000;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////ANGULOS DE LOS SERVOS///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Aqui especificamos los ángulos de cada servo.
//Sabiendo que a cada ciclo, cada servo lo situamos únicamente en 2 ó 3 posiciones diferentes, especificamos la posición inicial '1', la siguiente '2' y la posicion '3'.

//SERVO DEL GIRO DEL PENDULO//
int giro_pendulo_1 = 120;
int giro_pendulo_2 = 20;
int giro_pendulo_3 = 55;


//SERVO DEL CARRO DEL PENDULO//
int carro_pendulo_1 = 45;
int carro_pendulo_2 = 120;
int carro_pendulo_aplastando = 65; //Angulo para que el carro aplaste el libro antes de hacer la foto.

//SERVO DEL PUNTERO DE LA FOTO//
int giro_foto_1 = 150;
int giro_foto_2 = 173;
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*************************************FIN AREA DE CONFIGURACION*******************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//
//*********************************************************************************************************//




Unipolar cremallera (10,11,12,13);
Servo carro_pendulo; 
Servo giro_pendulo ;
Servo giro_foto;
int presostato = 4; //Presostato. 
                    //En concreto hemos usado un presostato Festo PEV-W , configurado para que nos devuelva un nivel bajo al detectar una depresión de 2 bar.
                    //Detecta el vacío que genera la ventosa cuando succiona la página del libro. 
                    //Se puede decir que es como un final de carrera inferior de la ventosa. 
int fc_arriba_ventosa = 3; //Final de carrera superior de la ventosa.
int v_solenoide = 7; //Electrovalvula solenoide que abre o cierra el caudal de aire hacia el venturi. 
                     //Hemos usado un Festo que incorpora ya el venturi.
int luz = 2;  // Piloto de actividad. Mientras esté encendido el Arduino, tendremos a un nivel alto el pin 2 para encender un piloto que se encuentra
              // en el mando de paro de emergencia. Al pulsar la seta de emergencia, puenteamos RESET con GND, se detiene todo el programa y la luz de
              // actividad de apaga.
              
//A continuación tenemos todas las constantes donde iremos almacenando el tiempo con la funcion 'millis()' con el fin de generar retardos.
unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long t3 = 0;
unsigned long t4 = 0;
unsigned long t5 = 0;
unsigned long t6 = 0;
unsigned long t7 = 0;
unsigned long t8 = 0;
unsigned long t9 = 0;
unsigned long t10 = 0;
unsigned long t11 = 0;
unsigned long t12 = 0;
unsigned long t13 = 0;
unsigned long t14 = 0;
unsigned long t15 = 0;
unsigned long t16 = 0;
unsigned long t17 = 0;
unsigned long t18 = 0;




void setup()
{
  carro_pendulo.attach(6);
  giro_foto.attach(5);
  giro_pendulo.attach(9);
  pinMode(presostato, INPUT);
  pinMode(fc_arriba_ventosa, INPUT);
  pinMode(v_solenoide, OUTPUT);
  pinMode(luz, OUTPUT);
  FSM.begin(FSM_NextState,nStateMachine,FSM_State,nStateFcn,STATE1); 
}


void loop()
{
digitalWrite (luz, HIGH);
  ReadEvents();
  FSM.Update();  
}

void ReadEvents(void)
{
  FSM.AddEvent(0); 
  
  if ( digitalRead(presostato)==LOW )
  {
    FSM.AddEvent(PRESSURE);  
  }
  
  if ( digitalRead(fc_arriba_ventosa)==LOW )
  {
    FSM.AddEvent(FC_UP_V);  
  }
 }


void func1(void)
{ 

  carro_pendulo.write(carro_pendulo_1);
  cremallera.giraizquierda();
  
}

void func2(void)
{
  cremallera.para();
 t2 = millis();
  FSM.AddEvent(3);
}

void func3(void)
{
 if (millis() - t2 < r3)
 {
   t3 = millis();
 carro_pendulo.write(carro_pendulo_1);
 FSM.AddEvent(4); 
 } 
}

void func4(void)
{
 if (millis() - t3 < r4)
 {
 t4 = millis();
 giro_pendulo.write(giro_pendulo_1); 
 FSM.AddEvent(5);
 }
}


void func5(void)
{
 if (millis() - t4 < r5)
 {
 t5 = millis();
 carro_pendulo.write(carro_pendulo_2);   
 FSM.AddEvent(6);
 }
}


void func6(void)
{
  if (millis() - t5 > r6)
  {
  cremallera.giraderecha();
    digitalWrite(v_solenoide, HIGH); 
  }
}

void func7(void)
{ 
  t7 = millis();
  cremallera.para();
  FSM.AddEvent(8);
}


void func8(void)
{ 
   t8 = millis();
   if (millis()- t7 > 1000)
   {
   FSM.AddEvent(9);
   } 
}

void func9(void)
{
   cremallera.giraizquierda();
   t9= millis();
   if (millis() - t8 > r8)
   {
   FSM.AddEvent(10);
   } 
}

void func10(void)
{
   cremallera.para();
   t10= millis();
   if (millis() - t9 > r10)
   {
   FSM.AddEvent(11);
   }
}

void func11(void)
{
    giro_pendulo.write(giro_pendulo_2);
   digitalWrite(v_solenoide, LOW); 
   carro_pendulo.write(carro_pendulo_1);
   t11 = millis();
  
   FSM.AddEvent(12);
   
}

void func12(void)
{

  t12 = millis(); 
  if (millis() - t11 > r12)
  {
    giro_pendulo.write(giro_pendulo_3);
  FSM.AddEvent(13);
  }
}

void func13(void)
{
  if (millis() - t12 > r13)
  {
   t13= millis();
   carro_pendulo.write(carro_pendulo_aplastando);
   cremallera.giraizquierda();  
  }
}

void func14(void)
{ 
  t14 = millis();
  cremallera.para();  
  FSM.AddEvent(15);
}


void func15(void)
{ 
  t15 = millis();
  giro_foto.write(giro_foto_1);
  FSM.AddEvent(16);
}

void func16(void)
{ 
  if(millis() - t15 > r16){
  giro_foto.write(giro_foto_2);
  t16 = millis();
  FSM.AddEvent(17);
  
  }
}

void func17(void)
{ t17 = millis();
  if(millis() - t16 > r17){
  giro_foto.write(giro_foto_1);
  }
  if(millis() - t16 > (r17+3000)){
  FSM.AddEvent(1);
  }
}






 





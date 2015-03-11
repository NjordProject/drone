#include <Wire.h>
#include "gyro_lib.h"


#include <bccm01b.h>

Gyro gyro;
Bccm01b m3(3);
Bccm01b m5(5);
Bccm01b m9(9);
Bccm01b m10(10);
int report = 0;
int s = 0;
int flag = 0;

void setup(){
  Serial.begin(9600);
  int init = gyro.initialise();
  if(init ==0){
     Serial.print("Error Init"); 
  }
    report = m3.controlSpeed(200);
    report = m5.controlSpeed(200);
    report = m9.controlSpeed(200);
    report = m10.controlSpeed(200);
}

void loop(){ 
  
  int *moteur = gyro.fct_loop();
  
  if(moteur[3]+100<255){
    if (moteur[3]+100 <100){
       report = m3.controlSpeed(0);
    }
    else{
      report = m3.controlSpeed(moteur[3]);
    }
  }
  else{
    report = m3.controlSpeed(255);
  }
  if(moteur[0]+100<255){
    if (moteur[0]+100 <100){
       report = m5.controlSpeed(0);
    }
    else{
      report = m5.controlSpeed(moteur[0]);
    }
  }
  else{
    report = m5.controlSpeed(255);
  }
  
  if(moteur[1]+100<255){
    if (moteur[1]+100 <100){
       report = m9.controlSpeed(0);
    }
    else{
      report = m9.controlSpeed(moteur[1]+100);
    }
  }
  else{
    report = m9.controlSpeed(255);
  }
  
  if(moteur[2]+100<255){
    if (moteur[2]+100 <100){
       report = m10.controlSpeed(0);
    }
    else{
      report = m10.controlSpeed(moteur[2]+10);
    }
  }
  else{
    report = m10.controlSpeed(255);
  }
  
  
  // Si moteur[4] == 1 => le drone n'est pas stabilisé : A effectuer : action sur moteur pour le stabiliser
  while(moteur[4]==1){
    int *moteur = gyro.fct_loop();
   if(moteur[3]+100<255){
    if (moteur[3]+100 <100){
       report = m3.controlSpeed(0);
    }
    else{
      report = m3.controlSpeed(moteur[3]);
    }
  }
  else{
    report = m3.controlSpeed(255);
  }
  if(moteur[0]+100<255){
    if (moteur[0]+100 <100){
       report = m5.controlSpeed(0);
    }
    else{
      report = m5.controlSpeed(moteur[0]);
    }
  }
  else{
    report = m5.controlSpeed(255);
  }
  
  if(moteur[1]+100<255){
    if (moteur[1]+100 <100){
       report = m9.controlSpeed(0);
    }
    else{
      report = m9.controlSpeed(moteur[1]+100);
    }
  }
  else{
    report = m9.controlSpeed(255);
  }
  
  if(moteur[2]+100<255){
    if (moteur[2]+100 <100){
       report = m10.controlSpeed(0);
    }
    else{
      report = m10.controlSpeed(moteur[2]+10);
    }
  }
  else{
    report = m10.controlSpeed(255);
  }
  
    delay(100);
  }
}

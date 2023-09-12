//Carrega a biblioteca SoftwareSerial
#include <SoftwareSerial.h>
    
//Define os pinos para a serial   
SoftwareSerial mySerial(10, 11); // RX, TX

String command = ""; 


void setup()   
{  
  //Inicia a serial  
  Serial.begin(115200);  
  Serial.println("Digite os comandos AT :");  
  //Inicia a serial configurada nas portas 10 e 11
  mySerial.begin(38400);        // se não conectar, utilize 38400
}  

void loop()  
{  
  if (mySerial.available()) 
  {  
     while(mySerial.available()) 
     { command += (char)mySerial.read();  
     }  
   Serial.print(command);  
   command = "";
  }

  // Read user input if available.  
  if (Serial.available())
  {  
    delay(10); // The DELAY!  
    mySerial.write(Serial.read());  
  }  
}


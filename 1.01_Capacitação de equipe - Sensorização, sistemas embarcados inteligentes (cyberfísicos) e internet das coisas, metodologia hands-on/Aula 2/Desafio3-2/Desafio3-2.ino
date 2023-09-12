int temp =0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
    int dataV= Serial.available();
    //Serial.println (dataV);
  
  if (dataV != 0) {
    int dataS= Serial.read();
    
    //Serial.println (dataS);
    //Serial.print("/n");
    //Serial.println("_______");
    //Serial.write (dataS);
    
    if (dataS == 65 || dataS == 97){
      Serial.print("\nInfo recebida\n");
      temp = 1;
    }
    else if( dataS == 49){
      Serial.print("\nfim de mensagem\n");
      temp = 1;
    }
    else{
      if(temp == 2){
        temp = 0;
        }
      else if(temp == 1){
        temp = temp +1;
        }
      else{
        Serial.print("\nConteudo não identificado\n");
        temp = 1;
        }
    }
  }
  delay(20);
}


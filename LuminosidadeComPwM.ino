unsigned char recepcao[3];
unsigned char conta=0;
unsigned int valor_pwm;

void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  digitalWrite(10, LOW);
}
void loop()
{
  if (Serial.available()>0){

   recepcao[conta] = Serial.read() - '0';
     // - '0' converte  o número de ASCii para int
    conta++;
  }
  if (conta==3){
    //calcula o valor do PWM
  valor_pwm = recepcao[0]*100 + recepcao[1]*10 + recepcao[2];
 		
     if(valor_pwm>255)
           valor_pwm=255;
    
    analogWrite(10,valor_pwm);
    conta=0;
  
  
  }
}

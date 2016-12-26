

int SX = 100;
int led = 7;

int morseList[] = {101,11000, 11010, 1100, 10, 10010, 1110, 10000, 100, 10111, 1101
             ,10100, 111, 110 , 1111, 10110, 11101, 1010, 1000, 11, 1001, 10001
             , 1011, 11001, 11011, 11100, 23};


void lightLED(int n){
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(SX*n);               // wait for a dot or dash
  digitalWrite(led, LOW); 
  
  
}

void lightMorse() {
  char message[] = "David";
  char toConvert;
  int letter;
  bool endM = false;
  int last = 0;
 
  
  for(int i = 0; i < sizeof(message)-1;i++){
     toConvert = message[i];
     Serial.println(toConvert);
  
     letter = toConvert;
     //Serial.println(letter);
     
     if(letter > 96){
       letter = letter-96;
     }   
     else{
       if(letter == 32){
         letter = 27;
       }
       else{  
         letter = letter-64;
       }
       
     }
     //Serial.println(letter);
     
     String toMorse = String(morseList[letter-1]);
     toMorse = toMorse.substring(1, toMorse.length());
     Serial.println(toMorse);
     
     char toLight;  
   Serial.println(last);
 Serial.println(letter);  
     if(last == 1 && letter != 27){
       delay(SX*3);
       Serial.println("did 3 delay");
     }
     for(int i = 0; i < sizeof(toMorse);i++){
       toLight = toMorse[i];
       
       
       if(toLight == '1'){   
         lightLED(3);
         if(i < sizeof(toMorse)-1){
           delay(SX);
           last = 1;
         }
       }
       if(toLight == '0'){
         lightLED(1);
         if(i < sizeof(toMorse)-1){
           delay(SX);
           last = 1;
         }
       }
       if(toLight == NULL){
           last = 1;
        
       }
       
       if(toLight == '3'){
         delay(SX*7);
         Serial.println("did 7 delay");
         last = 0;
       }
     }
     
     
  
    
  }
 
  
}
  
 


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);   
  Serial.begin(9600);
  

}

void loop() {
  lightMorse();
  delay(SX*10);
}

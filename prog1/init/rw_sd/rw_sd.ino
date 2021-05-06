#include<SD.h>

File my_file;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting the sd, hoping it's here...");

  pinMode(10, OUTPUT);

  if(!SD.begin(10)){
    Serial.println("could not initialize");
    return;
  }

  Serial.println("Found it!");

  my_file = SD.open("sdwr.txt");

  if(my_file){
    Serial.println("starting write...");
    while(my_file.available()){
    Serial.write(my_file.read());
    }
    my_file.close();

    Serial.println("Done");
    
//    
//    my_file.println("Test 1, 2, 3");
//    my_file.close();
//    
    
  }else{
    Serial.println("Could not open for some reason");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

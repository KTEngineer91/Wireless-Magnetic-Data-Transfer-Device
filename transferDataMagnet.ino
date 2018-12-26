const int dPin = 12;
int incomingByte = 0;
int data = 0;


void setup() {
  
  Serial.begin(9600); //opens serial port and sets data rate to bps
  pinMode(dPin, OUTPUT);
  Serial.println("Starting...");
  Serial.println("Send a string of binary digits");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) { //sends data only when we receive data

    incomingByte = Serial.read(); // reads incoming byte
    data = 1;

    if (incomingByte = 48) { //if it receives data
      digitalWrite(dPin,LOW); //turn off the magnet
      Serial.print("0");
      delay(200);
    } else if (incomingByte == 49) { //if it doesn't receive data
      digitalWrite(12, HIGH); //turns on magnet
      Serial.print("1");
      delay(200);
    } else {
      Serial.print("Invalid transfer");
    }
  } else {
    if (data == 1) {
      digitalWrite(12, LOW);
      Serial.println("");
      data = 0;
    }
  }
}

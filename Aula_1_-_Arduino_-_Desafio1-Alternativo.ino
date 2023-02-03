/*
  State change detection (edge detection)

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground (or use the built-in LED on most
    Arduino boards)

*/

// this constant won't change:
const int  buttonPin = 4;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  pinMode(buttonPin, INPUT); // initialize the button pin as a input:
  pinMode(ledPin, OUTPUT);  // initialize the LED as an output:
  Serial.begin(9600); // initialize serial communication:
}


void loop() {
  buttonState = digitalRead(buttonPin);// read the pushbutton input pin:

 
  if (buttonState != lastButtonState) { // compare the buttonState to its previous state
    if (buttonState == HIGH) { // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;// if the state has changed, increment the counter
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      Serial.print("Novo delay: ");
      Serial.print(4000/(pow(2,buttonPushCounter)));

    } else { // if the current state is LOW then the button went from on to off:
      Serial.println("\noff");
    }
    delay(50);// Delay a little bit to avoid bouncing
  }                                          
  lastButtonState = buttonState;// save the current state as the last state, for next time through the loop
  digitalWrite(ledPin, HIGH);
  delay(4000/(pow(2,buttonPushCounter)));
  digitalWrite(ledPin, LOW);
  delay(4000/(pow(2,buttonPushCounter)));
}

int rightpin1 = 6;
int rightpin2 = 5;
int leftpin1 = 10;
int leftpin2 = 9;
char value;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";

void setup()
{
  // Digital pin 6, 7, 8 and 9 set as output pin

  pinMode(rightpin1, OUTPUT);
  pinMode(rightpin2, OUTPUT);
  pinMode(leftpin1, OUTPUT);
  pinMode(leftpin2, OUTPUT);
  Serial.begin(9600);
}
String getTextToPrint()
{
  String value = inputString.substring(5, inputString.length() - 2);
  return value;
}


void serialEvent() {
  while (Serial.available()) {

    char inChar = (char)Serial.read();

    int sec = (int)char;

    inputString += inChar;

    if (inChar == '\n') {
      stringComplete = true;
    }
  }

  void loop()
  {
    while (Serial.available() > 0)
    {
      value = Serial.read();
      Serial.println(value);
    }

    if (commandString.equals("TEXT"))
    {
      String text = getTextToPrint();
      printText(text);
    }

    inputString = "";

    if ( value == 'F') // Forward
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 40);
      analogWrite(leftpin1, 40);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'B') // to move in reverse
    {
      analogWrite(rightpin1, 40);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 40);
      delay(sec * 1000);
    }

    else if (value == 'L') //to move towards left
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 40);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'R') ////to move towards right
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 40);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }

    else if (value == 'S') // to halt all movement
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'I') // to move forward towards the right
    {
      analogWrite(rightpin1, 40);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'J') // to move backward towards the left
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 40);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'G') // to move backward towards the left
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 40);
      analogWrite(leftpin2, 0);
      delay(sec * 1000);
    }
    else if (value == 'H') // to move backward towards the right
    {
      analogWrite(rightpin1, 0);
      analogWrite(rightpin2, 0);
      analogWrite(leftpin1, 0);
      analogWrite(leftpin2, 40);
      delay(sec * 1000);
    }
  }

  void getCommand()
  {
    if (inputString.length() > 0)
    {
      commandString = inputString.substring(1, 5);
    }
  }

}

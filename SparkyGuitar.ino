/*
 SparkyGuitar v0.1.1
 Works like a keyboard.

 Works only with with Arduino Micro, Leonardo and Due (and every UNO, MEGA, ... with hoodLoader). 

 The circuit:
 * 4 pushbuttons attached from pins 10, 7, 3, 4, A0 to +5V (or 3.3V on a 3.3V-based Arduino)
 * 10 K resistor attached to pins 10, 7, 3, 4, A0 from ground
 * Note: for more information about the Keyboard and Mouse features of Arduino Micro, Leonardo and Due see     
   https://www.arduino.cc/en/Reference/MouseKeyboard

 created 16 November 2015
 by SparkyCola <https://github.com/SparkyCola/>
 modified  16 November 2015
 by SparkyCola

 This code is in public domain.
 https://github.com/SparkyCola/SparkyGuitar/
 */

//define the pressed states for each button:
bool greenBtnPressed, redBtnPressed, yellowBtnPressed, blueBtnPressed, pickBtnPressed;

// pins for the buttons
#define BLUE_BTN    10
#define YELLOW_BTN  7
#define RED_BTN     3 
#define GREEN_BTN   4
#define PICK_BTN    A0

// keys which will be sent keyodes can be seen at https://www.arduino.cc/en/Reference/KeyboardModifiers
#define BLUE_KEY    KEY_F12
#define YELLOW_KEY  KEY_F11
#define RED_KEY     KEY_F10
#define GREEN_KEY   KEY_F9
#define PICK_KEY    KEY_F8

void setup() {
  // intialize the Keyboard
  Keyboard.begin();
  // initialize the buttons as input:
  pinMode(BLUE_BTN, INPUT);
  pinMode(YELLOW_BTN, INPUT);
  pinMode(RED_BTN, INPUT);
  pinMode(GREEN_BTN, INPUT);
  pinMode(PICK_BTN, INPUT);
  // set pressed states of each button to false:
  greenBtnPressed = false;
  redBtnPressed = false;
  yellowBtnPressed = false;
  blueBtnPressed = false;
  pickBtnPressed = false;  
}

void loop() {
  //if BLUE_BTN is pressed
  if(digitalRead(BLUE_BTN)) //if pressed
  {
    //"press" the blue key (F12 by defalut)
    Keyboard.press(BLUE_KEY);
    //set pressed to true 
    blueBtnPressed = true;
  }
  //if BLUE_BTN isn't pressed and was pressed before
  else if(blueBtnPressed)
  {
    //"release" the blue key (F12 by defalut)
    Keyboard.release(BLUE_KEY);
    //set pressed to false 
    blueBtnPressed = false;
  }

  //YELLOW_BTN
  if(digitalRead(YELLOW_BTN))
  {
     Keyboard.press(YELLOW_KEY);
     yellowBtnPressed = true;
  }
  else if(yellowBtnPressed)
  {
    Keyboard.release(YELLOW_KEY);
    yellowBtnPressed = false;
  }

  //RED_BTN
  if(digitalRead(RED_BTN))
  {
     Keyboard.press(RED_KEY);
     redBtnPressed = true;
  }
  else if(redBtnPressed)
  {
    Keyboard.release(RED_KEY);
    redBtnPressed = false;
  }

  //GREEN BTN
  if(digitalRead(GREEN_BTN))
  {
     Keyboard.press(GREEN_KEY);
     greenBtnPressed = true;
  }
  else if(greenBtnPressed)
  {
    Keyboard.release(GREEN_KEY);
    greenBtnPressed = false;
  }

  //ENTER
  if(digitalRead(PICK_BTN))
  {
     Keyboard.press(PICK_KEY);
     pickBtnPressed = true;
  }
  else if(pickBtnPressed)
  {
    Keyboard.release(PICK_KEY);
    pickBtnPressed = false;
  }
  
}

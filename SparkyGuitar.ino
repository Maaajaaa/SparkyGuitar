bool GREEN_BTNpressed, RED_BTNpressed, YELLOW_BTNpressed, BLUE_BTNpressed, enterPressed;

#define BLUE_BTN    10
#define YELLOW_BTN  7
#define RED_BTN     3 
#define GREEN_BTN   4
#define ENTER       A0

#define BLUE_KEY    KEY_F12
#define YELLOW_KEY  KEY_F11
#define RED_KEY     KEY_F10
#define GREEN_KEY   KEY_F9
#define ENTER_KEY   KEY_F8

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(BLUE_BTN, INPUT);
  pinMode(YELLOW_BTN, INPUT);
  pinMode(RED_BTN, INPUT);
  pinMode(GREEN_BTN, INPUT);
  pinMode(ENTER, INPUT);
  GREEN_BTNpressed = false;
  RED_BTNpressed = false;
  YELLOW_BTNpressed = false;
  BLUE_BTNpressed = false;
  enterPressed = false;  
}

void loop() {
  //BLUE_BTN
  if(digitalRead(BLUE_BTN))
  {
     Keyboard.press(BLUE_KEY);
     BLUE_BTNpressed = true;
  }
  else if(BLUE_BTNpressed)
  {
    Keyboard.release(BLUE_KEY);
    BLUE_BTNpressed = false;
  }

  //YELLOW_BTN
  if(digitalRead(YELLOW_BTN))
  {
     Keyboard.press(YELLOW_KEY);
     YELLOW_BTNpressed = true;
  }
  else if(YELLOW_BTNpressed)
  {
    Keyboard.release(YELLOW_KEY);
    YELLOW_BTNpressed = false;
  }

  //RED_BTN
  if(digitalRead(RED_BTN))
  {
     Keyboard.press(RED_KEY);
     RED_BTNpressed = true;
  }
  else if(RED_BTNpressed)
  {
    Keyboard.release(RED_KEY);
    RED_BTNpressed = false;
  }

  //GREEN BTN
  if(digitalRead(GREEN_BTN))
  {
     Keyboard.press(GREEN_KEY);
     GREEN_BTNpressed = true;
  }
  else if(GREEN_BTNpressed)
  {
    Keyboard.release(GREEN_KEY);
    GREEN_BTNpressed = false;
  }

  //ENTER
  if(digitalRead(ENTER))
  {
     Keyboard.press(ENTER_KEY);
     enterPressed = true;
  }
  else if(enterPressed)
  {
    Keyboard.release(ENTER_KEY);
    enterPressed = false;
  }
  
}

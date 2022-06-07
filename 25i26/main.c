#include <LPC21xx.H>

//dodany komentarz dla gita

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define BUTTON1_bm (1<<4)
#define BUTTON2_bm (1<<6)
#define BUTTON3_bm (1<<5)
#define BUTTON4_bm (1<<7)

enum KeyboardState {RELEASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
enum LedStepDir {LEFT, RIGHT};

void Delay(unsigned int iTimeInMs){
  unsigned int uiCycle;
  int uiTotalCycles = (iTimeInMs * 12000) - 4;
  for(uiCycle = 0; uiCycle < uiTotalCycles; uiCycle++);
}

void LedInit(void){
  IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIdx){
  IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  switch(ucLedIdx){
    case 0:
      IO1SET = LED0_bm;
      break;
    case 1:
      IO1SET = LED1_bm;
      break;
    case 2:
      IO1SET = LED2_bm;
      break;
    case 3:
      IO1SET = LED3_bm;
      break;
    default:
      break;
  }
}

void KeyboardInit(void){
  IO0DIR = IO0DIR & (~(BUTTON1_bm | BUTTON2_bm | BUTTON3_bm | BUTTON4_bm));
}

enum KeyboardState eKeyboardRead(void){
  if(0 == (IO0PIN & BUTTON1_bm)){     // !(IO0PIN & BUTTON1_bm)
    return BUTTON_1; //wynik iloczynu (~x) & y       wcisniety  puszczony
  }
  else if(0 == (IO0PIN & BUTTON2_bm)){//             0010       0000     (~xx...xxxx1101xxxx & 0..0010..0)    
    return BUTTON_2;
  }
  else if(0 == (IO0PIN & BUTTON3_bm)){//             0100       0000
    return BUTTON_3;
  }
  else if(0 == (IO0PIN & BUTTON4_bm)){//             1000       0000
    return BUTTON_4;
  }
  return RELEASED;
}

void LedStep(enum LedStepDir eLedStepDir){
  static unsigned char sucLedStepIdx = 0;
  switch(eLedStepDir){
    case LEFT:
      sucLedStepIdx = (sucLedStepIdx + 1) % 4;
      break;
    case RIGHT:
      sucLedStepIdx = (sucLedStepIdx + 3) % 4; // -1 +4
      break;
  }
  LedOn(sucLedStepIdx);
}

void LedStepLeft(void){
  LedStep(LEFT);
}

void LedStepRight(void){
  LedStep(RIGHT);
}

int main(){
  LedInit();
  KeyboardInit();
  
  while(1){
    
    switch (eKeyboardRead()){
      case BUTTON_1:
        LedStepRight();
        break;
      case BUTTON_2:
        LedStepLeft();
        break;
      case BUTTON_3:
      case BUTTON_4:
      default:
        break;
    }
    Delay(250);
    
  }
}

#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define BUTTON1_bm (1<<4)
#define BUTTON2_bm (1<<6)
#define BUTTON3_bm (1<<5)
#define BUTTON4_bm (1<<7)

enum KeyboardState {RELEASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
unsigned char ucLedStepIdx = 0;

void Delay(unsigned int iTimeInMs){
  unsigned int uiCycle;
  int uiTotalCycles = (iTimeInMs * 12000) - 4;
  // 2400 with -4 0.00000025 sec too short or with -3 0._17 sec too long
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
  if(!(IO0PIN & BUTTON1_bm)) return BUTTON_1;
  else if(!(IO0PIN & BUTTON2_bm)) return BUTTON_2;
  else if(!(IO0PIN & BUTTON3_bm)) return BUTTON_3;
  else if(!(IO0PIN & BUTTON4_bm)) return BUTTON_4;
  return RELEASED;
}

void StepLeft(void){
  //ucLedStepIdx = (ucLedStepIdx - 1) % 4;
  //ucLedStepIdx = (ucLedStepIdx + 3) % 4; // -1 +4
  ucLedStepIdx = (ucLedStepIdx + 1) % 4;
  LedOn(ucLedStepIdx);
}

void StepRight(void){
  //ucLedStepIdx = (ucLedStepIdx - 1) % 4;
  ucLedStepIdx = (ucLedStepIdx + 3) % 4; // -1 +4
  LedOn(ucLedStepIdx);
}

int main(){
  
  LedInit();
  KeyboardInit();
  
  while(1){
    Delay(250);
    StepRight();
    
    /*
    switch (eKeyboardRead()){
      case RELEASED:
        LedOn(4);
        break;
      case BUTTON_1:
        LedOn(0);
        break;
      case BUTTON_2:
        LedOn(1);
        break;
      case BUTTON_3:
        LedOn(2);
        break;
      case BUTTON_4:
        LedOn(3);
        break;
      default:
        LedOn(4);
    }
    */
    
  }
}

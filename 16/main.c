#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define BUTTON1_bm (1<<4)
#define BUTTON2_bm (1<<6)
#define BUTTON3_bm (1<<5)
#define BUTTON4_bm (1<<7)

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

unsigned char ReadButton1(void){
  return (~IO0PIN & BUTTON1_bm);
}
unsigned char test1;
int main(){
  
  LedInit();
  IO0DIR = IO0DIR & (~BUTTON1_bm);
  
  while(1){
    /*
    LedOn(0);
    Delay(250);
    LedOn(1);
    Delay(250);
    LedOn(2);
    Delay(250);
    LedOn(3);
    Delay(250);
    */
    test1 = ReadButton1();
    if(0 != test1) LedOn(1);
    else LedOn(0);
    //Delay(250);

    
  }
}

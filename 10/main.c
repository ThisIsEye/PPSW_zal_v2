#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

void Delay(unsigned int iTimeInMs){
  unsigned int uiCycle;
  int uiTotalCycles = (iTimeInMs * 12000) - 4;
  // 2400 with -4 0.00000025 sec too short or with -3 0._17 sec too long
  for(uiCycle = 0; uiCycle < uiTotalCycles; uiCycle++);
}

int main(){
  
  IO1DIR = IO1DIR | LED3_bm;
  
  while(1){
    if((IO1PIN & LED3_bm) != 0) IO1CLR = LED3_bm;
    else IO1SET = LED3_bm;
    Delay(50); //10 Hz ON+OFF
    
  }
}

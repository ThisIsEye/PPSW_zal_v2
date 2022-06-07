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
  
  IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  
  IO1SET = LED0_bm;
  IO1SET = LED0_bm | LED1_bm;
  IO1SET = LED0_bm | LED1_bm | LED2_bm;
  IO1SET = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  
  while(1){
    
  }
}

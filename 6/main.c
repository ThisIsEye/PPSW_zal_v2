#include <LPC21xx.H>

void Delay(unsigned int iTimeInMs){
  unsigned int uiCycle;
  int uiTotalCycles = (iTimeInMs * 2400) - 4;
  // with -4 0.00000025 sec too short or with -3 0._17 sec too long
  for(uiCycle = 0; uiCycle < uiTotalCycles; uiCycle++);
}

int main(){
  
  IO1DIR = IO1DIR | (1<<16);
  
  while(1){
    if((IO1PIN & (1<<16)) != 0) IO1CLR = (1<<16);
    else IO1SET = (1<<16);
    Delay(1);
    Delay(1);
    Delay(1);
    Delay(1);
    Delay(1000);
    Delay(1000);
    Delay(1000);
    Delay(1000);
    
  }
}

#include <LPC21xx.H>

void Delay(void){
  unsigned int uiCycle;
  for(uiCycle = 0; uiCycle < 1000; uiCycle++);
}

int main(){
  
  IO1DIR = IO1DIR | (1<<16);
  
  while(1){
    if((IO1PIN & (1<<16)) != 0) IO1CLR = (1<<16);
    else IO1SET = (1<<16);
    Delay();
    
  }
}

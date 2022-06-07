#include <LPC21xx.H>

int main(){
  
  IO1DIR = IO1DIR | (1<<16);
  IO1SET = (1<<16);
  IO1CLR = (1<<16);
  
  while(1){
    
  }
}




#include "Gui.h"
#include <avr/io.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>




void Gui__init() {
    LCD_Init();
    button_init();
    LCDDR18 = 1;
    printAt(0,0);
    printAt(0,4);

 }

void LCD_Init(void) {
	CLKPR = (1 << CLKPCE); 
	CLKPR = 0x00;

    // Use external asynchronous clock source 
    // 1/3 Bias and 1/4 duty, 25 segments enabled 
    LCDCRB = (1<<LCDCS) | (1<<LCDMUX1)| (1<<LCDMUX0)| (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0);
	// 
    // Using 16 as prescaler selection and 8 as LCD Clock Divide 
    LCDFRR = (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0);
    // Set segment drive time to 300 us and output voltage to 3.35 V
    LCDCCR = (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1)| (1<<LCDCC0);
    // Enable LCD, low power waveform, no frame interrupt, no blanking 
    LCDCRA = (1<<LCDEN) | (1<<LCDAB) |  (0<<LCDBL);
}

void button_init(void){


    
    // initialize button
    PORTB |= ((1 << 7)| (1 << 6 ) | (1 << 4));  // 7 down, 6 up, 4 center down 
	PORTE |= ( (1 << 2) | ( 1 << 3));           // 2 left, 3 right


	// enable interupts for joystick
    EIMSK |= (1 << PCIE1) | (1 << PCIE0); //  PCIE1 enables PCINT15..8 interupts // PCIE0 enables PCINT7..0 interupts
	//EIMSK |= (1 << PCINT15);

	PCMSK1 |= (1 << PCINT15)|(1 << PCINT14)|(1 << PCINT12); //enables those pins
	PCMSK0 |= (1 << PCINT3)|(1 << PCINT2);

  


}

int getValueArray(int i){
    switch (i)
    {
    case 0:
        return ZeroValue;

    case 1:
        return OneValue;
    
    case 2:
        return TwoValue;

    case 3:
        return ThreeValue;
    
    case 4:
        return FourValue;

    case 5:
        return FiveValue;
    
    case 6:
        return SixValue;
    
    case 7:
        return SevenValue;
        
    case 8:
        return EightValue;
    
    case 9:
        return NineValue;
    
    default: // 10
        return BlankValue;
    }
}

void writeChar(char ch, int pos) {
	

	volatile int i = 0;
	if (pos < 0 || pos > 5) {
		return; // do nothing if pos is outside the supported range
	}
	if ((int)ch < (0+48) || (int)ch > (9+48)) {
		i=10;
	}else{
        i = ch - 48;
    }
	if(pos==0){
		LCDDR0 =  (LCDDR0&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR5 =  (LCDDR5&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR10 = (LCDDR10&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR15 = (LCDDR15&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==1){
		LCDDR0 =     (LCDDR0&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR5 =     (LCDDR5&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR10 =    (LCDDR10&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR15 =    (LCDDR15&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
	} else if(pos==2){
		LCDDR1 =  (LCDDR1&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR6 =  (LCDDR6&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR11 = (LCDDR11&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR16 = (LCDDR16&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==3){
		LCDDR1 =     (LCDDR1&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR6 =     (LCDDR6&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR11 =    (LCDDR11&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR16 =    (LCDDR16&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
		
	} else if(pos==4){
		LCDDR2 =  (LCDDR2&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR7 =  (LCDDR7&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR12 = (LCDDR12&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR17 = (LCDDR17&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==5){
		LCDDR2 =     (LCDDR2&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR7 =     (LCDDR7&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR12 =    (LCDDR12&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR17 =    (LCDDR17&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
		
	}
	

}

void printAt(long num, int pos) {
    int pp = pos;
    writeChar( (num % 100) / 10 + '0', pp);
    pp++;
    writeChar( num % 10 + '0', pp);
}

int readJoystick(void){
    if(PINB>>7==0){ // 7 down
        return 7;
    }else if((PINB & (1<<6))==0){ // 6 up
        return 6;
    }else if((PINB & (1<<4))==0){ // 4 center
        return 4;
    }else if((PINE & (1<<2))==0){ // 2 left
        return 2;
    }else if((PINE & (1<<3))==0){ // 3 right
        return 3;
    }else{
        return 0;
    }
}

void hold(guiObj* self){
    self->hold = 1;
    if(self->preValue == readJoystick()){
        if(readJoystick() != 4){
            ASYNC(self,updateGui, NULL);
        }
        
        AFTER(MSEC(200),self,hold,NULL);
    }else{
        self->hold = 0;
    }
}

void updateGui(guiObj* self){

    int value = readJoystick();
    self->preValue = value;
    if(self->debounce >= 1){
        value = 0;
    }
    switch (value)
    {
    case 7:  // down
        if(self->pos==0 && self->freq1 > 0){
            self->freq1--;
            ASYNC(self->pulse1 , setFreq ,self->freq1);
            printAt(self->freq1,self->pos);
        }else if(self->pos==4 && self->freq2 > 0){
            self->freq2--;
            ASYNC(self->pulse2 , setFreq ,self->freq2);
            printAt(self->freq2,self->pos);
        }
        self->debounce += 2;
        if(self->hold == 0){      
            ASYNC(self, hold, NULL);   // starts hold cycle
        }
        
        break;
    case 6:   //up
        if(self->pos==0 && self->freq1 < 99){
            self->freq1++;
            ASYNC(self->pulse1 , setFreq ,self->freq1);
            printAt(self->freq1,self->pos);
        }else if(self->pos==4 && self->freq2 < 99){
            self->freq2++;
            ASYNC(self->pulse2 , setFreq ,self->freq2);
            printAt(self->freq2,self->pos);
        }
        self->debounce += 2;
        if(self->hold == 0){
            ASYNC(self, hold, NULL);   // starts hold cycle
        }
        break;
    case 2:  // left
        self->pos = 0;
        LCDDR3 = 0;
        LCDDR18 = 1;
        self->debounce += 2;
        break;
    case 3:   // right
        self->pos = 4;
        LCDDR3 = 1;
        LCDDR18 = 0;
        self->debounce += 2;
        break;
    case 4:   // center
        if(self->pos == 0){
            if(self->freq1 != 0){
                ASYNC(self->pulse1,saveFreq, self->freq1); 
                self->savedFreq1 = self->freq1;
                ASYNC(self->pulse1,setFreq, 0);
                self->freq1 = 0;
            }else{
                ASYNC(self->pulse1, setSaveFreq, NULL);
                self->freq1 = self->savedFreq1;
                
            }
            printAt(self->freq1,self->pos);
        }else if(self->pos == 4){
            if(self->freq2 != 0){
                ASYNC(self->pulse2,saveFreq, self->freq2); 
                self->savedFreq2 = self->freq2;
                ASYNC(self->pulse2,setFreq, 0);
                self->freq2 = 0;
            }else{
                ASYNC(self->pulse2, setSaveFreq, NULL);
                self->freq2 = self->savedFreq2;
            }
            printAt(self->freq2,self->pos);
        }
        printAt(4,2);
        break;
    default:
       
        self->debounce = 0;
        
        printAt(2,2);
        break;
    }
    
}


void inter(guiObj* self){

}

void updateGui2(guiObj* self){

    int value = readJoystick();
    self->preValue = value;
    switch (value)
    {
    case 7:  // down
        if(self->pos==0 && self->freq1 > 0){
            self->freq1--;
            ASYNC(self->pulse1 , setFreq ,self->freq1);
            printAt(self->freq1,self->pos);
        }else if(self->pos==4 && self->freq2 > 0){
            self->freq2--;
            ASYNC(self->pulse2 , setFreq ,self->freq2);
            printAt(self->freq2,self->pos);
        }
   
        
        
        break;
    case 6:   //up
        if(self->pos==0 && self->freq1 < 99){
            self->freq1++;
            ASYNC(self->pulse1 , setFreq ,self->freq1);
            printAt(self->freq1,self->pos);
        }else if(self->pos==4 && self->freq2 < 99){
            self->freq2++;
            ASYNC(self->pulse2 , setFreq ,self->freq2);
            printAt(self->freq2,self->pos);
        }
        printAt(4,2);
    
       
        break;
    case 2:  // left
        self->pos = 0;
        LCDDR3 = 0;
        LCDDR18 = 1;
        break;
    case 3:   // right
        self->pos = 4;
        LCDDR3 = 1;
        LCDDR18 = 0;
        break;
    case 4:   // center
        if(self->pos == 0){
            if(self->freq1 != 0){
                ASYNC(self->pulse1,saveFreq, self->freq1); 
                self->savedFreq1 = self->freq1;
                ASYNC(self->pulse1,setFreq, 0);
                self->freq1 = 0;
            }else{
                ASYNC(self->pulse1, setSaveFreq, NULL);
                self->freq1 = self->savedFreq1;
                
            }
            printAt(self->freq1,self->pos);
        }else if(self->pos == 4){
            if(self->freq2 != 0){
                ASYNC(self->pulse2,saveFreq, self->freq2); 
                self->savedFreq2 = self->freq2;
                ASYNC(self->pulse2,setFreq, 0);
                self->freq2 = 0;
            }else{
                ASYNC(self->pulse2, setSaveFreq, NULL);
                self->freq2 = self->savedFreq2;
            }
            printAt(self->freq2,self->pos);
        }
        
        printAt(4,2);
        break;
    default:

        
        printAt(2,2);
        break;
    }

    if(self->hold == 0){  
        self->hold = 1;    
        ASYNC(self, hold, NULL);   // starts hold cycle
    }
    
}









#include "TinyTimber.h"
#include "pulseGenerator.h"


#define BlankValue  0x0000
#define ZeroValue   0x1551 //0001010101010001 0x1 0x5 0x5 0x1 = 0x1551
#define OneValue    0x2080 //0000100000000010 0x2 0x0 0x8 0x0 = 0x2080 
#define TwoValue    0x1e11 //0001000111100001 0x1 0xd 0x1 0x1 = 0x1d11
#define ThreeValue  0x1b11 //0001000110110001 0x1 0xb 0x1 0x1 = 0x1b11
#define FourValue   0x0b50 //0000010110110000 0x0 0xb 0x5 0x0 = 0x0b50
#define FiveValue   0x1b41 //0001010010110001 0x1 0xb 0x4 0x1 = 0x1b41
#define SixValue    0x1f41 //0001010011110001 0x1 0xf 0x4 0x1 = 0x1f41
#define SevenValue  0x0111 //0001000100010000 0x0 0x1 0x1 0x1 = 0x0111
#define EightValue  0x1f51 //0001010111110001 0x1 0xf 0x5 0x1 = 0x1f51
#define NineValue   0x0b51 //0001010110110000 0x0 0xb 0x5 0x1 = 0x0b51 


#define initGui(pulse1, pulse2, pos) {initObject(),pulse1 ,pulse2 ,pos,0,0,0,0,0,0,0,0,0}


typedef struct {
    Object super;
	pulseGenerator* pulse1;
	pulseGenerator* pulse2;
	int pos;
	int initialized;
	int freq1;
	int freq2;
	int savedFreq1;
	int savedFreq2;
	int joystickValue;
	int preValue;
	int hold;
	int debounce;
	
} guiObj;



void Gui__init();	
void LCD_Init();
void button_init();
void writeChar(char ch, int pos);
void printAt(long num, int pos);
int getValueArray(int i);
int readJoystick();
void updateGui(guiObj* self);
void updateGui2(guiObj* self);
void inter(guiObj* self);

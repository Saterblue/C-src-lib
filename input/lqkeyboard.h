#ifndef LQKEYBOARD_2018
#define LQKEYBOARD_2018

#include <stdint.h>



//set virtual-key max number
#define LQ_VK_NUMBER_MAX    255
#define LQ_BIT_NUMBERS      32
#define LQ_FLAG_INDEX       ( (LQ_VK_NUMBER_MAX+1)/LQ_BIT_NUMBERS + ((LQ_VK_NUMBER_MAX+1)%LQ_BIT_NUMBERS == 0 ? 0 : 1) )
//why use 32 bit not 64 bit?  1 << x ,if x > 32,its will have bug...
//every bit as a keystate down/up
//example status[0] is a uint32_t, consist of 32 bits, so it can store 64 key's status, key:[0-31]
//all key up:      status[0] = 0b00000000000000000000000000000000;
//lq_keydown(3); = status[0] = 0b00000000000000000000000000001000;
//lq_keydown(2); = status[0] = 0b00000000000000000000000000000100;
struct LQ_VK_SET
{
    uint32_t status[LQ_FLAG_INDEX];
};

//keysets
extern LQ_VK_SET lq_keysets ;

//return:0  means succese,otherwise false;
int lq_keydown(uint32_t key);
int lq_keyup(uint32_t key);

//return:
//1         the key is down
//0         the key is up
//-1        the key is not supported
int lq_checkKeyDown(uint32_t key);

//set all key up;
void lq_resetkey();

#endif // LQKEYBOARD_2018

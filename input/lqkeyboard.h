#ifndef LQKEYBOARD_2018
#define LQKEYBOARD_2018

#include <stdint.h>

//set virtual-key max number
#define LQ_VK_NUMBER_MAX    255
#define LQ_FLAG_INDEX       ( (LQ_VK_NUMBER_MAX+1)/64 + ((LQ_VK_NUMBER_MAX+1)%64 == 0 ? 0 : 1) )

//every bit as a keystate down/up
//example state[0] is a uint64_t, consist of 64 bits, so it can store 64 key's state, key:[0-63]
//all key up:      state[0] = 0b0000000000000000000000000000000000000000000000000000000000000000;
//lq_keydown(3); = state[0] = 0b0000000000000000000000000000000000000000000000000000000000001000;
//lq_keydown(2); = state[0] = 0b0000000000000000000000000000000000000000000000000000000000001100;
struct LQ_VK_SET
{
    uint64_t state[LQ_FLAG_INDEX];
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

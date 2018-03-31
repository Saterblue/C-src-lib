#include    "lqkeyboard.h"

LQ_VK_SET lq_keysets = {0};
//common code:check if key is support,then do last
#define _imkey   if(key < 0 || key > LQ_VK_NUMBER_MAX) return -1;int i = key/64;int m = key%64;
int lq_keydown(uint32_t key)
{
    _imkey;
    lq_keysets.state[i] |= ( 1 << m );
    return 0;
}

int lq_keyup(uint32_t key)
{
    _imkey;
    lq_keysets.state[i] &= (UINT64_MAX - ( 1 << m ));
    return 0;
}

int lq_checkKeyDown(uint32_t key)
{
    _imkey;
    return ((lq_keysets.state[i] & ( 1 << m )) == 0 ? 0 : 1);
}


void lq_resetkey()
{
    int i = 0;
    while(i != LQ_FLAG_INDEX)
    {
        lq_keysets.state[i++] = 0;
    }
}

#include    "lq_tools.h"

int lq_getLocaltime(char* buffer,size_t bufferSize)
{
	time_t now = time(NULL);
	struct tm* now_tm = localtime(&now);
	char tmp[1024]  = {0};
	sprintf(tmp,"%04d-%02d-%02d %02d:%02d:%02d",
		now_tm->tm_year	+ 1900,
		now_tm->tm_mon	+ 1,
		now_tm->tm_mday,
		now_tm->tm_hour,
		now_tm->tm_min,
		now_tm->tm_sec);

	size_t len = strlen(tmp);
	if(len + 1 > bufferSize){return len + 1;}
	memcpy(buffer,tmp,len + 1);

	return 0;
}

void lq_strToLower(char* text,size_t textLength)
{
    int i = 0;
    for(; i < textLength; i++)
    {
        text[i] = tolower(text[i]);
    }
}

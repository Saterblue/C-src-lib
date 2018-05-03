#ifndef LQ_TOOLS_ORZ
#define LQ_TOOLS_ORZ

#include    <stdio.h>
#include    <string.h>
#include    <time.h>
#include    <ctype.h>

/*
Parameters
buffer	    -	pointer to the object to write to
bufferSize	-	buffer size

Return value
zero        -  success
non-zero    -  error; the minSize need;

example:
    char date[128] = {0};
    int result = lq_getlocaltime(date,128);
    printf("%s",date);
output:
    2014-04-21 21:32:13
*/
static inline int lq_getLocaltime(char* buffer,size_t bufferSize)
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
/*
Parameters
text	    -	pointer to the text change to lower
textLength	-	length of text; always strlen(text);

example:
    char text[128] = "ABCDEFG";
    lq_strToLower(text,strlen(text));
    printf("text:%s",text);
output:
    abcdefg
*/
static inline void lq_strToLower(char* text,size_t textLength)
{
    int i = 0;
    for(; i < textLength; i++)
    {
        text[i] = tolower(text[i]);
    }
}



#endif // LQ_TOOLS_ORZ

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
inline int lq_getLocaltime(char* buffer,size_t bufferSize);

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
inline void lq_strToLower(char* text,size_t textLength);



#endif // LQ_TOOLS_ORZ

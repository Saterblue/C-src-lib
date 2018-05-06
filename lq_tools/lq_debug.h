#ifndef LQ_DEBUG_ORZ
#define LQ_DEBUG_ORZ

#include <stdio.h>
#include <errno.h>
#include <string.h>




/*
Parameters
A	    -	bool, 0 false; otherwise true;
M	    -	format string
...     -   VA_ARGS,variadic arguments

example:
int main(int args,char* argv[])
{
    lq_log_warn("test");
    int a = 2;
    int b = 3;
    lq_check_debug(a == b , "%d not equal %d",a,b);
    return 0;

error:
    return -1;
}
output:
    [WARN] (lq_debug.h:19: errno: None) test
    DEBUG lq_debug.h:22: 2 not equal 3
    return -1;
*/

#define     LQ_DEBUG

#ifdef 		LQ_DEBUG
#define 	lq_debug(M, ...) fprintf(stderr,"DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define 	lq_debug(M, ...)
#endif

//no jump
#define lq_error_message() (errno == 0 ? "None" : strerror(errno))

#define lq_log_err(M, ...) fprintf(stderr,"[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, lq_error_message(), ##__VA_ARGS__)

#define lq_log_warn(M, ...) fprintf(stderr,"[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, lq_error_message(), ##__VA_ARGS__ )

#define lq_log_info(M, ...) fprintf(stderr,"[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)


/***       jump to error             ***/
#define lq_sentinel(M, ...) {lq_log_err(M, ##__VA_ARGS__); errno = 0; goto error;}

/***       if(A) jump to error       ***/
#define lq_error(A, M, ...) if((A)){ lq_log_err(M, ##__VA_ARGS__); errno = 0; goto error;}

/***       if(!A) jump to error     ***/
#define lq_check(A, M, ...) if(!(A)){ lq_log_err(M, ##__VA_ARGS__); errno = 0; goto error;}

#define lq_check_mem(A) lq_check((A),"bad memory.")

#define lq_check_debug(A, M, ...) if(!(A)) { lq_debug(M, ##__VA_ARGS__); errno=0; goto error;}



#endif // LQ_DEBUG_ORZ

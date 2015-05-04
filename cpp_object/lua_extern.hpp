#ifndef LUA_EXTERN_HHH
#define LUA_EXTERN_HHH
#include <stdio.h>
#include <stdlib.h>

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}



#define err_exit(num,fmt,args...)  \
    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);exit(num);} while(0)
    
#define err_return(num,fmt,args...)  \
    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);return(num);} while(0)


#endif

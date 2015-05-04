#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#define err_exit(num,fmt,args...)  \
    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);exit(num);} while(0)
#define err_return(num,fmt,args...)  \
    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);return(num);} while(0)

class CBSDateTime{
public:
  CBSDateTime()
  {
    //printf("construct\n");
  }
  ~CBSDateTime()
  {
    //printf("distory\n");
  }
};

int datetime (lua_State *L){    
  CBSDateTime* pDateTime = (CBSDateTime*)lua_newuserdata(L, sizeof(CBSDateTime));
  new (pDateTime) CBSDateTime();

  luaL_getmetatable(L, "datetime");
  lua_setmetatable(L, -2);

  return 1;
}
int datetime_gc(lua_State* L){
  CBSDateTime* pDateTime = (CBSDateTime*)luaL_checkudata(L, -1, "datetime");
  if (pDateTime)
    pDateTime->~CBSDateTime();
  
  return 0;
}

int datetime_check(lua_State* L){
  CBSDateTime* pDateTime = (CBSDateTime*)luaL_checkudata(L, -1, "datetime");
  if (pDateTime)
    lua_pushboolean(L, true);

  return 1;
}

int datetime_classname(lua_State* L){
  lua_pushstring(L, "CBSDatetime");
  return 1;
}

int datetime_index(lua_State* L){
  CBSDateTime* pDateTime = (CBSDateTime*)luaL_checkudata(L, 1, "datetime");
  const char* __index = lua_tostring(L, 2);
  if (strcmp(__index, "classname") == 0)
  {
    lua_pushcfunction(L, datetime_classname);
  }
  else
  {
    lua_pushnil(L);
  }
  return 1;
}

void register_datetime_func(lua_State *L) {
  //...
  lua_pushcfunction(L, datetime);
  lua_setglobal(L, "datetime");

  lua_pushcfunction(L, datetime_check);
  lua_setglobal(L, "datetime_check");

  luaL_newmetatable(L, "datetime");    
  lua_pushstring(L, "__gc");    
  lua_pushcfunction(L, datetime_gc);    
  lua_settable(L, -3);

  lua_pushstring(L, "__index");
  lua_pushcfunction(L, datetime_index);
  lua_settable(L, -3);
}

int main(int argc,char** argv)
{
    lua_State * l = luaL_newstate() ;       
    if ( l == NULL ) 
        err_return(-1,"luaL_newstat() failed"); 
    luaL_openlibs(l);
    int ret = 0 ;
   
    register_datetime_func(l);

    ret = luaL_loadfile(l,"func.lua") ;      
    if ( ret != 0 ) 
        err_return(-1,"luaL_loadfile failed") ;
    
    ret = lua_pcall(l,0,0,0) ;
    if ( ret != 0 ) 
        err_return(-1,"lua_pcall failed:%s",lua_tostring(l,-1)) ;

    lua_close(l);                     
    return 0;
}

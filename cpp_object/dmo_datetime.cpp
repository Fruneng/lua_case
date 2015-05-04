#include <string.h>
#include <errno.h>
#include "dmo_datetime.h"
static char strLuaFilePath[] = "./rule_lua/dateTime.lua";

int datetime (lua_State *L)
{    
  CBSDateTime* pDateTime = (CBSDateTime*)lua_newuserdata(L, sizeof(CBSDateTime));
  new (pDateTime) CBSDateTime();

  luaL_getmetatable(L, "datetime");
  lua_setmetatable(L, -2);

  return 1;
}

int datetime_gc(lua_State* L)
{
  CBSDateTime* pDateTime = (CBSDateTime*)luaL_checkudata(L, -1, "datetime");
  if (pDateTime)
    pDateTime->~CBSDateTime();
  
  return 0;
}

int datetime_check(lua_State* L)
{
  CBSDateTime* pDateTime = (CBSDateTime*)luaL_checkudata(L, -1, "datetime");
  if (pDateTime)
    lua_pushboolean(L, true);

  return 1;
}

int datetime_classname(lua_State* L)
{
  lua_pushstring(L, "CBSDatetime");
  return 1;
}

int datetime_index(lua_State* L)
{
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

void register_datetime_func(lua_State *L) 
{
  printf("register_datetime_func:\n");
  
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

/*************Test********************************/

int Test_dateTime()
{
	  lua_State * L = luaL_newstate() ;       
    if ( L == NULL ) 
    	{
        err_return(-1,"luaL_newstat() failed"); 
      }
      
    luaL_openlibs(L);
    int ret = 0 ;
   
    register_datetime_func(L);

    ret = luaL_loadfile(L,strLuaFilePath) ;      
    if ( ret != 0 ) 
    	{
        err_return(-1,"luaL_loadfile failed") ;
      }
    
    ret = lua_pcall(L,0,0,0) ;
    if ( ret != 0 ) 
    	{
        err_return(-1,"lua_pcall failed:%s",lua_tostring(L,-1)) ;
      }

    lua_close(L);   	
}
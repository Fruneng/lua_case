#include"dmo_add.h"
#include"lua_extern.hpp"
static char strLuaFilePath[] = "./rule_lua/add.lua";


//c++ function call Lua function add
int lua_add(lua_State* L,int x,int y)
{
	int sum = 0;

	/* the function name */
	lua_getglobal(L,"add");

	/* the first argument */
	lua_pushnumber(L,x);

	/* the second argument */
	lua_pushnumber(L,y);

	/* call the function with 2
  arguments, return 1 result */
	lua_call(L,2,1);

	/* get the result */
	sum = static_cast<int>(lua_tonumber(L,-1));

	lua_pop(L,1);
	
	const int n = lua_gettop(L);
	//printf("lua_add for Test,the value of Top In LuaState is [%d]\n ",n);

	return sum;

}


/********************************/

void Test_add_lua(int x,int y)
{
	int sum = 0;
	int ret ;
  lua_State* L = lua_open();
  if(L == 0)
  	{
  		printf("fail to open Lua_State\n");	
  	}
 
 	/*int luaL_loadfile (lua_State *L, const char *filename);
 	 *Loads a file as a Lua chunk. 
 	 *This function uses lua_load to load the chunk in the file named filename. 
 	 *If filename is NULL, then it loads from the standard input. 
 	 *The first line in the file is ignored if it starts with a #.
 	 *more details,please read 
 	 *http://www.codingnow.com/2000/download/lua_manual.html
   */
  ret = luaL_loadfile(L,strLuaFilePath);
  if(LUA_ERRFILE == ret)
  	{
  		printf("fail to load lua file\n");	
  	}
  	
  
  lua_pcall(L, 0, LUA_MULTRET, 0);
  
  sum = lua_add(L,x,y);
  printf("The sum is %d\n", sum);
  lua_close(L);
}
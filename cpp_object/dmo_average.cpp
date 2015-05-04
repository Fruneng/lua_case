#include "dmo_average.h"

static char script_path[] = "./rule_lua/average.lua";

int Lua_average(lua_State *L)
{
	/* get number of arguments */
	const int n = lua_gettop(L);
	double sum = 0;
	int i;
	
	/* loop through each argument */
	for (i = 1; i <= n; i++)
	{
		 if (!lua_isnumber(L, i)) 
		 	{
           lua_pushstring(L, "incorrect argument");
           lua_error(L);
      }
		/* total the arguments */
		sum += lua_tonumber(L, i);
	}
	
	double average = sum / n;
	
	/* push the average£¬return the first arg */
	lua_pushnumber(L, average);
	
	/* push the sum ,return the first arg*/
	lua_pushnumber(L, sum);
	
	/* return the number of results */
	return 2;
}


void test_average()
{
	/* initialize Lua */
	lua_State* L = lua_open();
	
	/*  To have access to these libraries, the C host program 
	 *  should call the luaL_openlibs function,which opens all standard libraries. 
	 *  Alternatively, it can open them individually 
	 *  by calling luaopen_base (for the basic library)
	 */
	luaopen_base(L);  
  luaL_openlibs(L);
	
	/* register our function */
	lua_register(L, "average", Lua_average);
	
	/*int luaL_dofile (lua_State *L, const char *filename);
	 *Loads and runs the given file. It is defined as the following macro:
	 *(luaL_loadfile(L, filename) || lua_pcall(L, 0, LUA_MULTRET, 0))
	 */
	luaL_dofile(L, script_path);
	
	/* cleanup Lua */
	lua_close(L);
}
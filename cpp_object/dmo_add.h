#ifndef DEMO_ADD_H
#define DEMO_ADD_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lua_extern.hpp"


int lua_add(lua_State* L, int x, int y);


/*******************************/
void Test_add_lua(int x,int y);

#endif


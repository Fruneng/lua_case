#ifndef DMO_AVERAGE_H
#define DMO_AVERAGE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lua_extern.hpp"

int Lua_average(lua_State* L);


void test_average();

#endif
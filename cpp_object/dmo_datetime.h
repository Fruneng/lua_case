#ifndef DMO_DATETIME_HHHH
#define DMO_DATETIME_HHHH
#include<stdio.h>
#include"lua_extern.hpp"


class CBSDateTime{
public:
  CBSDateTime()
  {
    //printf("CBSDateTime is constructing \n");
  }
  ~CBSDateTime()
  {
   // printf("CBSDateTime object is being disconsructed\n");
  }
};



int datetime (lua_State *L);
int datetime_gc(lua_State* L);
int datetime_check(lua_State* L);
int datetime_classname(lua_State* L);
int datetime_index(lua_State* L);
void register_datetime_func(lua_State *L);



/**********************/
int Test_dateTime();

#endif
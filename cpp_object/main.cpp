#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include"lua_extern.hpp"
#include"dmo_add.h"
#include"dmo_datetime.h"
#include"dmo_average.h"


int main(int argc,char** argv)
{
  	//Test dateTime
  	Test_dateTime();
    
    
    //Test lua_add (C call Lua function)
    Test_add_lua(100,200);
    
    //Test average(Lua call c function)
    test_average();
  
                      
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int c_average(lua_State* L)
{
    int i;
    double x = 0.0;
    double y;
    int n = lua_gettop(L);
    for (i = n; i >= 1; i--) {
    	y = luaL_checknumber(L, i);
    	printf("C: argument[%2i or %3i]= %g\n", \
    		i, i - n - 1, y);
    	x += y;
    }
    lua_pushnumber(L, x/n);
/*    lua_pushinteger(L, n); */
    return EXIT_FAILURE;
}

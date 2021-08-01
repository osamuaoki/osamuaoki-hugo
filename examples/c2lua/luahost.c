#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "dump.h"
#include "average.h"

#define TRUE 1
#define FALSE 0

int
main(int argc, char *argv[])
{
    double w;
    double h;
    double a;

    puts("-- lua_State* L = luaL_newstate(); /* initialize Lua */");
    lua_State* L = luaL_newstate();

    puts("-- luaL_openlibs(L); /* standard libraries */");
    luaL_openlibs(L);

    puts("-- lua_register(L, \"average\", c_average); /* private library */");
    lua_register(L, "average", c_average);

    puts("-- luaL_loadfile(L, argv[1]) ...");
    if (luaL_loadfile(L, argv[1]) || lua_pcall(L, 0, 0, 0))
    {
    	printf("cannot run: %s\n", lua_tostring(L, -1));
    	return EXIT_FAILURE;
    }
    else
    	printf("-- %s load and executed.\n", argv[1]);

    puts("-- lua_getglobal(L, \"width\"); /* push Lua variable width */");
    lua_getglobal(L, "width");
    dump_stack(L);

    puts("-- lua_getglobal(L, \"height\"); /* push Lua variable height */");
    lua_getglobal(L, "height");
    dump_stack(L);

    puts("-- lua_getglobal(L, \"ave\"); /* push Lua variable ave */");
    lua_getglobal(L, "ave");
    dump_stack(L);

    puts("-- a = lua_tonumber(L, -1); /* read ave at -1 in the stack */");
    a = lua_tonumber(L, -1);
    printf("C: Average = %g\n", a);

    puts("-- h = lua_tonumber(L, -2); /* read height at -2 in the stack */");
    h = lua_tonumber(L, -2);
    printf("C: Height  = %g\n", h);

    puts("-- h = lua_tonumber(L, -3); /* read width at -3 in the stack */");
    w = lua_tonumber(L, -3);
    printf("C: Width   = %g\n", w);

    printf("C: Volume  %g * %g * %g = %g\n", w, h, a, w*h*a);

    lua_close(L);
    return EXIT_SUCCESS;
}


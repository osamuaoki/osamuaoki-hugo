#include <stdlib.h>
#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "dump.h"

#define TRUE 1
#define FALSE 0

int 
main (void)
{
    lua_State* L = luaL_newstate();

    printf("lua_pushboolean(L, TRUE)\n");
    lua_pushboolean(L, TRUE);
    dump_stack(L);

    printf("lua_pushnumber(L, 3.141592) -- push 3.141592\n");
    lua_pushnumber(L, 3.141592);
    dump_stack(L);

    printf("lua_pushinteger(L, -200) -- push -200\n");
    lua_pushinteger(L, -200);
    dump_stack(L);

    printf("lua_pushnil(L) -- push nil\n");
    lua_pushnil(L);
    dump_stack(L);

    printf("lua_pushstring(L, \"Hello world!\") -- push \"Hello world!\"\n");
    lua_pushstring(L, "Hello world!");
    dump_stack(L);

    printf("lua_replace(L, 2) -- replace stack[2] with stack top\n");
    lua_replace(L, 2);
    dump_stack(L);
    
    printf("lua_pushvalue(L, 1) -- push value of stack[1]\n");
    lua_pushvalue(L, 1);
    dump_stack(L);
    
    printf("lua_pushvalue(L, -2) -- push value of stack[-2]\n");
    lua_pushvalue(L, -2);
    dump_stack(L);
    
    printf("lua_insert(L, 2) -- insert stack top to stack[2]\n");
    lua_insert(L, 2);
    dump_stack(L);
    
    printf("lua_remove(L, 2) -- remove stack[2]\n");
    lua_remove(L, 2);
    dump_stack(L);
    
    printf("lua_settop(L, -1) -- remove 1 item from stack top\n");
    lua_settop(L, -1);
    dump_stack(L);

    printf("\n");

    lua_close(L);
    return EXIT_SUCCESS;
}


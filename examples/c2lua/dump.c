#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void dump_stack(lua_State* L)
{
    int i;
    int stack_size = lua_gettop(L); /*  Lua virtual stack size */
    printf ("=== DUMP STACK top=[%i] --> bottom=[1] ===\n", stack_size);
    for (i = stack_size; i >= 1; i--) {
    	int type = lua_type(L, i);
    	printf("C: stack[%2i or %3i] type=%10s", i, i - stack_size - 1, 
    			lua_typename(L,type));
    	switch(type) {
    	case LUA_TNUMBER: /* Lua type: number */
    		printf(";  value= %g", lua_tonumber(L, i));
    		break;
    	case LUA_TBOOLEAN: /* Lua type: boolean */
    		if (lua_toboolean(L, i)) {
    			printf(";  value= true");
    		} else {
    			printf(";  value= false");
    		}
    		break;
    	case LUA_TSTRING: /* Lua type: string */
    		printf(";  value= %s", lua_tostring(L, i) );
    		break;
    	case LUA_TNIL: /* Lua type: nil */
    			printf(";  value= nil (nil == 0)");
    		break;
    	default:
    			printf(";  value= non-printable");
    		break;
    	}
    	printf("\n");
    }
}

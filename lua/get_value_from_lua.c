#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <string.h>

//gcc get_value_from_lua.c -I/usr/local/include/lua5.1 -llua5.1

int main()
{
   lua_State *L = luaL_newstate();
   char buff[] = "return 1,'a'";
   int error;
   printf( "%d\n", lua_gettop(L) );
   error = luaL_loadbuffer(L, buff, strlen(buff), "my test") || lua_pcall(L, 0, LUA_MULTRET, 0);
   if (error) {
      fprintf(stderr, "%s", lua_tostring(L, -1));
      lua_pop(L, 1);  /* pop error message from the stack */
   }
   printf( "%d\n", lua_gettop(L) );
   printf( "%s\n", lua_tostring(L,-2) );
   printf( "%s\n", lua_tostring(L,-1) );
   return 0;
}

local csource =[[
   #include <stdio.h>
   #include <lua.h>
   #include <lauxlib.h>
   #include <lualib.h>
   
   int main()
   {
       lua_State *L = luaL_newstate(); 
       luaL_openlibs(L); 
       int result = luaL_dofile(L, "hello_excel.lua"); 
       if (result != 0) {
		      printf("lua_pcall error %s", lua_tostring(L, -1));
	    }
       lua_close(L); 
       return 0;
   }
]]
print(csource)
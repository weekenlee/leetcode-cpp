#include<stdio.h> 
#include<lua.h> 
#include<lualib.h> 
#include<lauxlib.h> 

typedef struct NumArray {
    int size;
    double values[1];
} NumArray;

static int newarray(lua_State *L) {
    int n = luaL_checknumber(L, 1);
    size_t  nbytes = sizeof(NumArray) + (n-1)*sizeof(double);
    NumArray *a = (NumArray *)lua_newuserdata(L, nbytes);
    a->size = n;
    return 1;
}

static int setarray(lua_State *L) {
    NumArray *a = (NumArray*)lua_touserdata(L, 1);
    int index = luaL_checknumber(L, 2);
    double value = luaL_checknumber(L, 3);

    a->values[index - 1] = value;
    return 0;
}

static int getarray(lua_State *L) {
    NumArray *a = (NumArray *)lua_touserdata(L, 1);
    int index = luaL_checknumber(L, 2);
    lua_pushnumber(L, a->values[index - 1]);
    return 1;
}

static const struct luaL_Reg arraylib[] = {
    {"new", newarray}, 
    {"set", setarray},
    {"get", getarray},
    {NULL, NULL}
};

int luaopen_array(lua_State *L) {
    luaL_newlib(L, arraylib);
    return 1;
}

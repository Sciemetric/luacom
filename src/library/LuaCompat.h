/*
 * LuaCompat.h
 *
 *  Library that tries to hide almost all differences
 *  between Lua versions
 *
 *  This file isn't as useful as it used to be since
 *  we no longer support Lua < 5.1.
 */

#ifndef __LUACOMPAT_H
#define __LUACOMPAT_H

#include "tStringBuffer.h"

int luaCompat_call(lua_State* L, int nargs, int nresults);
int luaCompat_call(lua_State* L, int nargs, int nresults, tStringBuffer& ErrMsg);

void luaCompat_newLuaType(lua_State* L, const char* module_name, const char* name);
void luaCompat_pushTypeByName(lua_State* L, const char* module, const char* type_name);
int luaCompat_newTypedObject(lua_State* L, void* object);
int luaCompat_isOfType(lua_State* L, const char* module, const char* type);
void luaCompat_getType(lua_State* L, int index);
const void* luaCompat_getType2(lua_State* L, int index);

void* luaCompat_getPointer(lua_State* L, int index);

void luaCompat_moduleCreate(lua_State* L, const char* module);
void luaCompat_moduleSet(lua_State* L, const char* module, const char* key);
void luaCompat_moduleGet(lua_State* L, const char* module, const char* key);

int luaCompat_checkTagToCom(lua_State *L, int luaval);

#if LUA_VERSION_NUM < 502
#define luaL_newlib(L, l) lua_createtable(L, 0, sizeof((l)) / sizeof((l[0])) ); luaL_register(L, NULL, l)
#define lua_rawlen(L, index) lua_objlen(L, index)

enum LUA_OPS { LUA_OPEQ = 0, LUA_OPLT, LUA_OPLE, };
int lua_compare(lua_State *L, int a, int b, LUA_OPS op);
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include <lua.h>
#ifdef __cplusplus
}
#endif

#define lua_boxpointer(L,u) \
    (*(void **)(lua_newuserdata(L, sizeof(void *))) = (u)) 

#endif /* __LUACOMPAT_H */


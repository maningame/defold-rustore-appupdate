#include "appupdate_enums.h"
#include "appupdate_enums_defs.h"

static int ReadonlyNewIndex(lua_State* L)
{
	return luaL_error(L, "Attempt to modify readonly enum table");
}

static void MakeReadonly(lua_State* L, int index)
{
	if (index < 0) index = lua_gettop(L) + index + 1;

	lua_newtable(L);                         // mt
	lua_pushcfunction(L, ReadonlyNewIndex);  // mt.__newindex
	lua_setfield(L, -2, "__newindex");

	lua_pushboolean(L, 0);                   // mt.__metatable = false
	lua_setfield(L, -2, "__metatable");

	lua_setmetatable(L, index);
}

static inline void PushIntField(lua_State* L, const char* key, int value)
{
	lua_pushinteger(L, (lua_Integer)value);
	lua_setfield(L, -2, key);
}

static void PushEnumTable(lua_State* L, void (*fill)(lua_State*))
{
	lua_newtable(L);
	fill(L);
	MakeReadonly(L, -1);
}

// ---- Fill functions

static void FillInstallErrorCode(lua_State* L)
{
	#define X(KEY, VAL) PushIntField(L, #KEY, (int)(VAL));
	APPUPDATE_ENUM_INSTALL_ERROR_CODE(X)
	#undef X
}

static void FillInstallStatus(lua_State* L)
{
	#define X(KEY, VAL) PushIntField(L, #KEY, (int)(VAL));
	APPUPDATE_ENUM_INSTALL_STATUS(X)
	#undef X
}

static void FillUpdateAvailability(lua_State* L)
{
	#define X(KEY, VAL) PushIntField(L, #KEY, (int)(VAL));
	APPUPDATE_ENUM_UPDATE_AVAILABILITY(X)
	#undef X
}

static void FillUpdateFlowResult(lua_State* L)
{
	#define X(KEY, VAL) PushIntField(L, #KEY, (int)(VAL));
	APPUPDATE_ENUM_UPDATE_FLOW_RESULT(X)
	#undef X
}

// ---- Public

void RegisterGlobalRuStoreAppUpdateEnums(lua_State* L)
{
	int top = lua_gettop(L);

	// _G.RuStoreAppUpdateEnums = { ... }
	lua_newtable(L); // root

	PushEnumTable(L, FillInstallErrorCode);
	lua_setfield(L, -2, "InstallErrorCode");

	PushEnumTable(L, FillInstallStatus);
	lua_setfield(L, -2, "InstallStatus");

	PushEnumTable(L, FillUpdateAvailability);
	lua_setfield(L, -2, "UpdateAvailability");

	PushEnumTable(L, FillUpdateFlowResult);
	lua_setfield(L, -2, "UpdateFlowResult");

	MakeReadonly(L, -1);
	lua_setglobal(L, "RuStoreAppUpdateEnums");

	assert(top == lua_gettop(L));
}

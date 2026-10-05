#define EXTENSION_NAME RuStoreAppUpdate
#define LIB_NAME "RuStoreAppUpdate"
#define MODULE_NAME "rustoreappupdate"

#include <dmsdk/sdk.h>
#include "appupdate_enums.h"

#if defined(DM_PLATFORM_ANDROID)

#include <dmsdk/dlib/android.h>
#include "AndroidJavaObject.h"

using namespace RuStoreSDK;

static void GetJavaObjectInstance(JNIEnv* env, AndroidJavaObject* instance)
{
    jclass cls = dmAndroid::LoadClass(env, "ru.rustore.defold.appupdate.RuStoreAppUpdate");
    jfieldID instanceField = env->GetStaticFieldID(cls, "INSTANCE", "Lru/rustore/defold/appupdate/RuStoreAppUpdate;");
    jobject obj = env->GetStaticObjectField(cls, instanceField);

    instance->cls = cls;
    instance->obj = obj;
}

static int Init(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    
    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "init", "(Landroid/app/Activity;)V");
    env->CallVoidMethod(instance.obj, method, dmGraphics::GetNativeAndroidActivity());

    thread.Detach();

    return 0;
}

static int RegisterListener(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "registerListener", "()Z");

    bool result = env->CallBooleanMethod(instance.obj, method);
    lua_pushboolean(L, result);
    
    thread.Detach();

    return 1;
}

static int UnregisterListener(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "unregisterListener", "()Z");

    bool result = env->CallBooleanMethod(instance.obj, method);
    lua_pushboolean(L, result);
    
    thread.Detach();

    return 1;
}

static int GetAppUpdateInfo(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "getAppUpdateInfo", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static int CheckIsImmediateUpdateAllowed(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "checkIsImmediateUpdateAllowed", "()Z");

    bool result = env->CallBooleanMethod(instance.obj, method);
    lua_pushboolean(L, result);

    thread.Detach();

    return 1;
}

static int StartUpdateFlowImmediate(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "startUpdateFlowImmediate", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static int StartUpdateFlowSilent(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "startUpdateFlowSilent", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static int StartUpdateFlowDelayed(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "startUpdateFlowDelayed", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static int CompleteUpdateSilent(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "completeUpdateSilent", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static int CompleteUpdateFlexible(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    dmAndroid::ThreadAttacher thread;
    JNIEnv* env = thread.GetEnv();

    AndroidJavaObject instance;
    GetJavaObjectInstance(env, &instance);
    jmethodID method = env->GetMethodID(instance.cls, "completeUpdateFlexible", "()V");
    env->CallVoidMethod(instance.obj, method);

    thread.Detach();

    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"init", Init},
    {"register_listener", RegisterListener},
    {"unregister_listener", UnregisterListener},
    {"get_appupdateinfo", GetAppUpdateInfo},
    {"check_is_immediate_update_allowed", CheckIsImmediateUpdateAllowed},
    {"start_update_flow_immediate", StartUpdateFlowImmediate},
    {"start_update_flow_silent", StartUpdateFlowSilent},
    {"start_update_flow_delayed", StartUpdateFlowDelayed},
    {"complete_update_silent", CompleteUpdateSilent},
    {"complete_update_flexible", CompleteUpdateFlexible},
    {0, 0}
};

#endif

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

static dmExtension::Result AppInitializeAppUpdateExtension(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeAppUpdateExtension(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    RegisterGlobalRuStoreAppUpdateEnums(params->m_L);
    
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeAppUpdateExtension(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeAppUpdateExtension(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeAppUpdateExtension, AppFinalizeAppUpdateExtension, InitializeAppUpdateExtension, nullptr, nullptr, FinalizeAppUpdateExtension)

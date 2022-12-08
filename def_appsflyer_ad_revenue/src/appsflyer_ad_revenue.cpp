#define EXTENSION_NAME AppsflyerAdRevenueExt
#define LIB_NAME "AppsflyerAdRevenue"
#define MODULE_NAME "appsflyer_ad_revenue"

#define DLIB_LOG_DOMAIN LIB_NAME

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_ANDROID)

#include <stdlib.h>
#include "appsflyer_ad_revenue.h"
#include "utils/lua_util.h"

namespace dmAppsflyerAdRevenue {
enum MediationNetwork
{
    MN_IRONSOURCE = 1,
    MN_APPLOVINMAX = 2,
    MN_GOOGLEADMOB = 3,
    MN_MOPUB = 4,
    MN_FYBER = 5,
    MN_APPODEAL = 6,
    MN_ADMOST = 7,
    MN_TOPON = 8,
    MN_TRADPLUS = 9,
    MN_YANDEX = 10,
};

enum AdType
{
    AT_REWARDED = 1,
    AT_INTERSTITIAL = 2,
};

static int Lua_Initialize(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    Initialize();
    return 0;
}


static int Lua_LogAdRevenue(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    int ad_type = lua_tointeger(L, 1);
    int mediationNetworkConst = lua_tointeger(L, 2);
    const char* network = lua_tostring(L, 3);
    double revenue = lua_tonumber(L, 4);
    const char* adUnitId = lua_tostring(L, 5);
    const char* placement = lua_tostring(L, 6);
    LogAdRevenue(ad_type, mediationNetworkConst, network, revenue, adUnitId, placement);
    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"initialize", Lua_Initialize},
    {"log_ad_revenue", Lua_LogAdRevenue},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    luaL_register(L, MODULE_NAME, Module_methods);
    #define SETCONSTANT(name) \
    lua_pushnumber(L, (lua_Number) name); \
    lua_setfield(L, -2, #name); \

    
    SETCONSTANT(MN_IRONSOURCE)
    SETCONSTANT(MN_APPLOVINMAX)
    SETCONSTANT(MN_GOOGLEADMOB)
    SETCONSTANT(MN_MOPUB)
    SETCONSTANT(MN_FYBER)
    SETCONSTANT(MN_APPODEAL)
    SETCONSTANT(MN_ADMOST)
    SETCONSTANT(MN_TOPON)
    SETCONSTANT(MN_TRADPLUS)
    SETCONSTANT(MN_YANDEX)
    SETCONSTANT(MN_YANDEX)
    SETCONSTANT(AT_REWARDED)
    SETCONSTANT(AT_INTERSTITIAL)

    #undef SETCONSTANT
    lua_pop(L, 1);
}

static dmExtension::Result AppInitializeAppsflyerAdRevenue(dmExtension::AppParams* params)
{
    Initialize_Ext();
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeAppsflyerAdRevenue(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    dmLogInfo("Registered extension AppsflyerAdRevenue");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result UpdateAppsflyerAdRevenue(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeAppsflyerAdRevenue(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeAppsflyerAdRevenue(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

} // namespace

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, dmAppsflyerAdRevenue::AppInitializeAppsflyerAdRevenue, dmAppsflyerAdRevenue::AppFinalizeAppsflyerAdRevenue, dmAppsflyerAdRevenue::InitializeAppsflyerAdRevenue, dmAppsflyerAdRevenue::UpdateAppsflyerAdRevenue,  0, dmAppsflyerAdRevenue::FinalizeAppsflyerAdRevenue)

#else // platform

static dmExtension::Result InitializeAppsflyerAdRevenue(dmExtension::Params *params) {
    dmLogInfo("Registered extension AppsflyerAdRevenue (null)");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeAppsflyerAdRevenue(dmExtension::Params *params) {
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeAppsflyerAdRevenue, 0, 0, FinalizeAppsflyerAdRevenue)

#endif // platform
#if defined(DM_PLATFORM_ANDROID)

#pragma once

#include <dmsdk/sdk.h>

namespace dmAppsflyerAdRevenue {

void Initialize_Ext();
void Initialize();
void LogAdRevenue(int ad_type, int mediationNetworkConst, const char* network, double revenue, const char* adUnitId, const char* placement);

} // namespace

#endif // platform
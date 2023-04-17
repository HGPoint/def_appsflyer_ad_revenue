#if defined(DM_PLATFORM_ANDROID) || defined(DM_PLATFORM_IOS)

#pragma once

#include <dmsdk/sdk.h>

namespace dmAppsflyerAdRevenue
{
    enum MediationNetwork
    {
        MN_IRONSOURCE = 1,
        MN_APPLOVINMAX = 2,
        MN_GOOGLEADMOB = 3,
        MN_FYBER = 4,
        MN_APPODEAL = 5,
        MN_ADMOST = 6,
        MN_TOPON = 7,
        MN_TRADPLUS = 8,
        MN_YANDEX = 9,
        MN_CHARTBOOST = 10,
        MN_UNITY = 11,
        MN_CUSTOMMEDIATION = 12,
    };

    enum AdType
    {
        AT_REWARDED = 1,
        AT_INTERSTITIAL = 2,
    };

    void Initialize_Ext();
    void Initialize();
    void LogAdRevenue(int ad_type, int mediationNetworkConst, const char *network, double revenue, const char *adUnitId, const char *placement);

} // namespace

#endif // platform
#if defined(DM_PLATFORM_IOS)

#include <dmsdk/sdk.h>

#import "appsflyer_ad_revenue.h"
#import <AppsFlyerAdRevenue/AppsFlyerAdRevenue.h>

namespace dmAppsflyerAdRevenue {
    const int GoogleAdMob = 1;
    const int IronSource = 2;
    const int ApplovinMax= 3;
    const int Fyber = 4;
    const int Appodeal = 5;
    const int Admost = 6;
    const int Topon = 7;
    const int Tradplus = 8;
    const int Yandex = 9;
    const int ChartBoost = 10;
    const int Unity = 11;
    const int Custom = 12;

    void Initialize_Ext(){
    }

    void Initialize(){
        [AppsFlyerAdRevenue start];
    }

    void LogAdRevenue(int ad_type, int mediationNetworkConst, const char* network, double revenue, const char* adUnitId, const char* placement)
    {
        @autoreleasepool {
            NSMutableDictionary* newDict = [NSMutableDictionary dictionary];
            
            NSString* nsAdUnitId = [NSString stringWithUTF8String: adUnitId];
            NSString* nsAdType = ad_type == AdType::AT_REWARDED ? @"Rewarded" : @"Interstitial";
            newDict[kAppsFlyerAdRevenueAdUnit] = nsAdUnitId;
            newDict[kAppsFlyerAdRevenueAdType] = nsAdType;
            
            if(placement != NULL){
                newDict[kAppsFlyerAdRevenuePlacement] = [NSString stringWithUTF8String: placement];
            }
            AppsFlyerAdRevenueMediationNetworkType network_type;




            switch(mediationNetworkConst){
                    case(MediationNetwork::MN_IRONSOURCE):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType)IronSource ;
                        break;
                    case(MediationNetwork::MN_APPLOVINMAX):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) ApplovinMax;
                        break;
                    case(MediationNetwork::MN_GOOGLEADMOB):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) GoogleAdMob;
                        break;
                    case(MediationNetwork::MN_FYBER):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Fyber;
                        break;
                    case(MediationNetwork::MN_APPODEAL):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Appodeal;
                        break;
                    case(MediationNetwork::MN_ADMOST):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Admost;
                        break;
                    case(MediationNetwork::MN_TOPON):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Topon;
                        break;
                    case(MediationNetwork::MN_TRADPLUS):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Tradplus;
                        break;
                    case(MediationNetwork::MN_YANDEX):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Yandex;
                        break;
                    case(MediationNetwork::MN_CHARTBOOST):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) ChartBoost;
                        break;
                    case(MediationNetwork::MN_UNITY):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Unity;
                        break;
                    case(MediationNetwork::MN_CUSTOMMEDIATION):
                        network_type = (AppsFlyerAdRevenueMediationNetworkType) Custom;
                        break;
                    network_type = (AppsFlyerAdRevenueMediationNetworkType) Custom;
                    break;
            }

            [[AppsFlyerAdRevenue shared] logAdRevenueWithMonetizationNetwork:[NSString stringWithUTF8String: network]
                                                            mediationNetwork:network_type
                                                                eventRevenue:[NSNumber numberWithDouble:revenue]
                                                            revenueCurrency:@"USD"
                                                        additionalParameters:newDict];
        }
    }
} // namespace

#endif // platform
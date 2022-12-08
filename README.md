# def_appsflyer_ad_revenue

 ---@class appsflyer_ad_revenue 
 ---@field initialize fun():void -- call this after appsflyer initialized
 ---@field log_ad_revenue fun(adType:int, mediationNetworkConst:int, network:string, revenue:number, adUnitId:string, placement:string):void
 appsflyer_ad_revenue = {}
 
  
adType
 AT_REWARDED 1
 AT_INTERSTITIAL 2
 
mediationNetworkConst
 MN_IRONSOURCE 1,
 MN_APPLOVINMAX 2,
 MN_GOOGLEADMOB 3,
 MN_MOPUB 4,
 MN_FYBER 5,
 MN_APPODEAL 6,
 MN_ADMOST 7,
 MN_TOPON 8,
 MN_TRADPLUS 9,
 MN_YANDEX 10

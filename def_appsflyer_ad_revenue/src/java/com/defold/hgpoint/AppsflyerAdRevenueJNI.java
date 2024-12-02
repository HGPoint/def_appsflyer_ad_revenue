package com.defold.hgpoint;

import android.util.Log;
import android.app.Activity;
import android.app.Application;

import com.appsflyer.AFAdRevenueData;
import com.appsflyer.AdRevenueScheme;
import com.appsflyer.AppsFlyerAdNetworkEventType;
import com.appsflyer.MediationNetwork;
import com.appsflyer.AppsFlyerLib;

import java.util.HashMap;
import java.util.Map;

public class AppsflyerAdRevenueJNI {
    private static final String TAG = "AppsflyerAdRevenue";
    private static final int REWARDED = 1;
    private static final int INTERSTITIAL = 2;

    private static final int IRONSOURCE = 1;
    private static final int APPLOVINMAX = 2;
    private static final int GOOGLEADMOB = 3;
    private static final int FYBER = 4;
    private static final int APPODEAL = 5;
    private static final int ADMOST = 6;
    private static final int TOPON = 7;
    private static final int TRADPLUS = 8;
    private static final int YANDEX = 9;
    private static final int CHARTBOOST = 10;
    private static final int UNITY = 11;
    private static final int CUSTOMMEDIATION = 12;

    private Activity activity;
    private Application application;
    AppsFlyerLib appsflyer;
    public AppsflyerAdRevenueJNI(Activity activity) {
        this.activity = activity;
        this.application = activity.getApplication();
    }

    public void Initialize() {
        appsflyer = AppsFlyerLib.getInstance();
    }

    public void LogAdRevenue(int adType, int mediationNetworkConst, String network, double revenue, String adUnitId,
                             String placement) {
        AppsFlyerAdNetworkEventType adEventType = adType == 1 ? AppsFlyerAdNetworkEventType.REWARDED
                : AppsFlyerAdNetworkEventType.INTERSTITIAL;
        MediationNetwork mediationNetwork = MediationNetwork.APPLOVIN_MAX;
        switch (mediationNetworkConst) {
            case IRONSOURCE:
                mediationNetwork = MediationNetwork.IRONSOURCE;
                break;
            case APPLOVINMAX:
                mediationNetwork = MediationNetwork.APPLOVIN_MAX;
                break;
            case GOOGLEADMOB:
                mediationNetwork = MediationNetwork.GOOGLE_ADMOB;
                break;
            case FYBER:
                mediationNetwork = MediationNetwork.FYBER;
                break;
            case APPODEAL:
                mediationNetwork = MediationNetwork.APPODEAL;
                break;
            case ADMOST:
                mediationNetwork = MediationNetwork.ADMOST;
                break;
            case TOPON:
                mediationNetwork = MediationNetwork.TOPON;
                break;
            case TRADPLUS:
                mediationNetwork = MediationNetwork.TRADPLUS;
                break;
            case YANDEX:
                mediationNetwork = MediationNetwork.YANDEX;
                break;
            case CHARTBOOST:
                mediationNetwork = MediationNetwork.CHARTBOOST;
                break;
            case UNITY:
                mediationNetwork = MediationNetwork.UNITY;
                break;
            case CUSTOMMEDIATION:
                mediationNetwork = MediationNetwork.CUSTOM_MEDIATION;
                break;
            default:
                Log.w(TAG, "No mediation network " + String.valueOf(mediationNetworkConst));
        }


        AFAdRevenueData adRevenueData = new AFAdRevenueData(
                network,       // monetizationNetwork
                mediationNetwork, // mediationNetwork
                "USD",           // currencyIso4217Code
                revenue       // revenue
        );

        Map<String, Object> additionalParameters = new HashMap<>();
        additionalParameters.put(AdRevenueScheme.AD_UNIT, adUnitId);
        additionalParameters.put(AdRevenueScheme.AD_TYPE, adEventType.toString());
        additionalParameters.put(AdRevenueScheme.PLACEMENT, placement);

        appsflyer.logAdRevenue(adRevenueData, additionalParameters);
    }
}

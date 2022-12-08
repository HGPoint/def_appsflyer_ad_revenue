package com.defold.hgpoint;

import android.util.Log;
import android.app.Activity;
import android.app.Application;

import com.appsflyer.adrevenue.adnetworks.AppsFlyerAdNetworkEventType;
import com.appsflyer.adrevenue.adnetworks.generic.MediationNetwork;
import com.appsflyer.adrevenue.adnetworks.generic.Scheme;
import com.appsflyer.adrevenue.AppsFlyerAdRevenue;

import java.util.Currency;
import java.util.HashMap;
import java.util.Locale;

public class AppsflyerAdRevenueJNI {
    private static final String TAG = "AppsflyerAdRevenue";
    private static final int REWARDED = 1;
    private static final int INTERSTITIAL = 2;


    private static final int IRONSOURCE = 1;
    private static final int APPLOVINMAX = 2;
    private static final int GOOGLEADMOB = 3;
    private static final int MOPUB = 4;
    private static final int FYBER = 5;
    private static final int APPODEAL = 6;
    private static final int ADMOST = 7;
    private static final int TOPON = 8;
    private static final int TRADPLUS = 9;
    private static final int YANDEX = 10;

    private Activity activity;
    private Application application;

    public AppsflyerAdRevenueJNI(Activity activity) {
        this.activity = activity;
        this.application = activity.getApplication();
    }
    
    public void Initialize(){
        AppsFlyerAdRevenue.Builder afRevenueBuilder = new AppsFlyerAdRevenue.Builder(this.application); 
        AppsFlyerAdRevenue.initialize(afRevenueBuilder.build());    
    }

    public void LogAdRevenue(int adType, int mediationNetworkConst, String network, double revenue, String adUnitId, String placement){
        AppsFlyerAdNetworkEventType adEventType = adType == 1 ? AppsFlyerAdNetworkEventType.REWARDED : AppsFlyerAdNetworkEventType.INTERSTITIAL;
        MediationNetwork mediationNetwork = MediationNetwork.applovinmax;
        switch (mediationNetworkConst) {
            case IRONSOURCE:
                mediationNetwork = MediationNetwork.ironsource;
                break;
            case APPLOVINMAX:
                mediationNetwork = MediationNetwork.applovinmax;
                break;
            case GOOGLEADMOB:
                mediationNetwork = MediationNetwork.googleadmob;
                break;
            case MOPUB:
                mediationNetwork = MediationNetwork.mopub;
                break;
            case FYBER:
                mediationNetwork = MediationNetwork.fyber;
                break;
            case APPODEAL:
                mediationNetwork = MediationNetwork.appodeal;
                break;
            case ADMOST:
                mediationNetwork = MediationNetwork.Admost;
                break;
            case TOPON:
                mediationNetwork = MediationNetwork.Topon;
                break;
            case TRADPLUS:
                mediationNetwork = MediationNetwork.Tradplus;
                break;
            case YANDEX:
                mediationNetwork = MediationNetwork.Yandex;
                break;
            default:
                Log.w(TAG, "No mediation network " + String.valueOf(mediationNetworkConst));
        }

        HashMap<String, String> customParams = new HashMap<>();
        customParams.put(Scheme.AD_TYPE, adEventType.toString());
        customParams.put(Scheme.AD_UNIT, adUnitId);
        customParams.put(Scheme.PLACEMENT, placement);
        AppsFlyerAdRevenue.logAdRevenue(
                network,
                mediationNetwork,
                Currency.getInstance(Locale.US),
                revenue,
                customParams
        );
    }
}

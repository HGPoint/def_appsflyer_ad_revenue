#if defined(DM_PLATFORM_ANDROID)

#include <dmsdk/dlib/android.h>

#include "appsflyer_ad_revenue.h"

namespace dmAppsflyerAdRevenue {

struct AdRevenue
{
    jobject         m_AdRevenueJNI;
    jmethodID       m_Initialize;
    jmethodID       m_LogAdRevenue;
};

static AdRevenue g_AdRevenue;

static void InitJNIMethods(JNIEnv* env, jclass cls)
{
    g_AdRevenue.m_Initialize = env->GetMethodID(cls, "Initialize", "()V");
    g_AdRevenue.m_LogAdRevenue = env->GetMethodID(cls, "LogAdRevenue", "(IILjava/lang/String;DLjava/lang/String;Ljava/lang/String;)V");//https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html
}

void Initialize_Ext()
{
    dmAndroid::ThreadAttacher threadAttacher;
    JNIEnv* env = threadAttacher.GetEnv();
    jclass cls = dmAndroid::LoadClass(env, "com.defold.hgpoint.AppsflyerAdRevenueJNI");
    InitJNIMethods(env, cls);
    jmethodID jni_constructor = env->GetMethodID(cls, "<init>", "(Landroid/app/Activity;)V");
    g_AdRevenue.m_AdRevenueJNI = env->NewGlobalRef(env->NewObject(cls, jni_constructor, threadAttacher.GetActivity()->clazz));
}

void Initialize()
{
    dmAndroid::ThreadAttacher threadAttacher;
    JNIEnv* env = threadAttacher.GetEnv();
    env->CallVoidMethod(g_AdRevenue.m_AdRevenueJNI, g_AdRevenue.m_Initialize);
}

void LogAdRevenue(int ad_type, int mediationNetworkConst, const char* network, double revenue, const char* adUnitId, const char* placement)
{
    dmAndroid::ThreadAttacher threadAttacher;
    JNIEnv* env = threadAttacher.GetEnv();
    jstring jnetwork = env->NewStringUTF(network);
    jstring jadUnitId = env->NewStringUTF(adUnitId);
    jstring jplacement = env->NewStringUTF(placement);
    env->CallVoidMethod(g_AdRevenue.m_AdRevenueJNI, g_AdRevenue.m_LogAdRevenue, ad_type, mediationNetworkConst, jnetwork, revenue, jadUnitId, jplacement);
    env->DeleteLocalRef(jnetwork);
    env->DeleteLocalRef(jadUnitId);
    env->DeleteLocalRef(jplacement);
}

} // namespace

#endif // platform

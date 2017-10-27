//
// Created by 吴登 on 17/10/27.
//

#include "Outter.h"
#include "jni.h"
#include "lib/include/Inner.h"
#include "string.h"
#include "assert.h"
#include "android/log.h"

#define JNIREG_CLASS "com/vip/c/demo/Outter"

jint outterCall(JNIEnv *env, jclass obj, jint i, jint j) {
    return call(env, obj, i, j);
}


static JNINativeMethod gMethods[] = {
        {"outterCall", "(II)I", (void *) outterCall},
};


static int registerNativeMethods(JNIEnv *env, const char *className,
                                 JNINativeMethod *gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}


static int registerNatives(JNIEnv *env) {
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods,
                               sizeof(gMethods) / sizeof(gMethods[0]))) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    __android_log_print(ANDROID_LOG_DEFAULT, "JNI", "onLoad");

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) {//注册
        return -1;
    }
/* success -- return valid version number */
    result = JNI_VERSION_1_4;

    return result;
}
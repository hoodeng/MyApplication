//
// Created by 吴登 on 17/10/26.
//
#include "jni.h"

#ifndef MYAPPLICATION_INNER_H
#define MYAPPLICATION_INNER_H

extern "C" {
JNIEXPORT jint JNICALL call(JNIEnv *, jclass, jint, jint);
};

#endif //MYAPPLICATION_INNER_H
